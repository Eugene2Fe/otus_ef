#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <thread>
#include <atomic>

#include "CRC32.hpp"
#include "IO.hpp"

/// @brief Переписывает последние 4 байта значением value
void replaceLastFourBytes(std::vector<char> &data, uint32_t value) {
  std::copy_n(reinterpret_cast<const char *>(&value), 4, data.end() - 4);
}

/**
 * @brief Заменяем последние четыре байта результата перебираемым значением i из поддиапозона
 * и проверяем не сошлось ли crc32
 * @param originalCrc32 CRC32 оригинального вектора
 * @param result Буфер с данными
 * @param start Начало поддиапазона
 * @param end   Конец поддиапазона
 * @param found Флаг завершения
 * @return Если нашли true, false если нет
 */
bool find4lastCRCval(uint32_t originalCrc32, std::vector<char> &result,
                   uint32_t start, uint32_t end, std::atomic<bool> &found) {
  for (uint32_t i = start; i < end && !found; ++i) {
        replaceLastFourBytes(result, i);
            // Отображаем прогресс
            if (i % 1000 == 0) {
            std::cout << "progress: "
                      << static_cast<double>(i) / static_cast<double>(end)
                      << std::endl;
          }
    auto currentCrc32 = crc32(result.data(), result.size());
    if (currentCrc32 == originalCrc32) {
      found = true;
      std::cout << "Success\n";
      return true;
    }
  }
  return false; // Ниче не нашлось
}

/**
 * @brief Формирует новый вектор с тем же CRC32, добавляя в конец оригинального
 * строку injection и дополнительные 4 байта
 * @details При формировании нового вектора последние 4 байта не несут полезной
 * нагрузки и подбираются таким образом, чтобы CRC32 нового и оригинального
 * вектора совпадали
 * @param original оригинальный вектор
 * @param injection произвольная строка, которая будет добавлена после данных
 * оригинального вектора
 * @return новый вектор
 */
std::vector<char> hack(const std::vector<char> &original,
                       const std::string &injection) {
  const uint32_t originalCrc32 = crc32(original.data(), original.size());

  // Создается буфер , содержащий оригинал вх.данных, injection и 4 байта
  std::vector<char> result(original.size() + injection.size() + 4);
  auto it = std::copy(original.begin(), original.end(), result.begin());
  std::copy(injection.begin(), injection.end(), it);

  // Кол-во доступных в OS потоков
  const unsigned int threadCount = std::thread::hardware_concurrency();

  // Определим тут в каком диапозоне будут вычислять каждый из доступных потоков
  const uint32_t rangeSize = std::numeric_limits<uint32_t>::max() / threadCount;

  // Если поиск успегно завершен выставим флаг в тру
  std::atomic<bool> found(false);

  std::vector<std::thread> threads;

  // Разделяем диапазон значений и запускаем потоки
  for (unsigned int t = 0; t < threadCount; ++t) {
    // Начало и конец диапазона для каждого треда
    uint32_t start = t * rangeSize;
    uint32_t end = (t == threadCount - 1) ? std::numeric_limits<uint32_t>::max() : start + rangeSize;

    // лямба ф-ция для создании локальной копии буфера результатов, чтобы
    // треды не изменяли общий буфер одновременно
    threads.emplace_back([=, &result, &found]() mutable { // Доавляем новые потоки
      std::vector<char> localResult = result; // Локальная копия буфера для потока
      if (find4lastCRCval(originalCrc32, localResult, start, end, found)) {
        result = std::move(localResult); //  Мувом копируем результат в общий буфер
      }
    });
  }

  // Ожидаем завершения всех потоков
  for (auto &thread : threads) {
    thread.join(); // Bспользуется для ожидания завершения конкретного текущего потока
                  // Без вызова join, программа может завершиться до завершения потоков, оставив "висящие" потоки.
                 // join обеспечивает синхронизацию и как следствие вы уверены,
                //  что все потоки завершились до того, как выполнение программы продолжится.

  }

  if (!found) {
    throw std::logic_error("Can't hack");
  }

  return result;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Call with two args: " << argv[0]
              << " <input file> <output file>\n";
    return 1;
  }

  try {
    const std::vector<char> data = readFromFile(argv[1]);
    const std::vector<char> badData = hack(data, "He-he-he");
    writeToFile(argv[2], badData);
  } catch (std::exception &ex) {
    std::cerr << ex.what() << '\n';
    return 2;
  }
  return 0;
}
