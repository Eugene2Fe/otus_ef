#include <iostream>
#include <stdexcept> // lib for exception print

class SeqContainer {
private:
    int* myData;            // Поинтер на динамический массив элементов
    size_t myDataCapacity;  // Емкость контейнера (размер выделенной памяти типа инт)
    size_t counter;         // Реальное текущее колво элементов в контейнере

    // Приват метод для ресайза контейнера, если что-то не будет влезать
    void resize_old_data_capacity(size_t newCapacity) {
        int* newMyData = new int[newCapacity]; // выделяем новой памяти
        for (size_t i = 0; i < counter; ++i) { // Перезапишем старые данные
            newMyData[i] = myData[i];
        }
        delete[] myData; // Удаляем старую память
        myData = newMyData; // Переназначение поинтера
        myDataCapacity = newCapacity; // Емкость задаем новую
    }

public:
    SeqContainer() : myData(nullptr), myDataCapacity(0), counter(0) {} // default Constr

    ~SeqContainer()   { delete[] myData; } // Destr for make free memory

    // 1. добавляет элемент в конец списка
    void push_back(int val) {
        if (counter == myDataCapacity) {
            resize_old_data_capacity(myDataCapacity == 0 ? 1 : myDataCapacity * 2);
        }
        myData[counter++] = val;
    }

    // 2. вставка элемента на точную указанную позицию
    void insert(size_t position, int val) {
        if (position > counter) { // Проверяем есть ли такая позиция
            throw std::out_of_range("Position out of range");
        }
        if (counter == myDataCapacity) {
            resize_old_data_capacity(myDataCapacity == 0 ? 1 : myDataCapacity * 2);
        }
        for (size_t i = counter; i > position; --i) {
            myData[i] = myData[i - 1];
        }
        myData[position] = val;
        ++counter;
    }

    // 3. удаление элемента по точной указанной позиции
    void erase(size_t position) {
        if (position >= counter) { // Проверка на корректность индекса
            throw std::out_of_range("position out of range");
        }
        for (size_t i = position; i < counter - 1; ++i) {
            myData[i] = myData[i + 1];
        }
        --counter;
    }

    // 4. получение размера контейнера
    size_t size() const {
        return counter;
    }

    // 5. получение элем по индексу (перегрузка оператора [])
    int& operator[](size_t position) {
        if (position >= counter) {
            throw std::out_of_range("position out of range");
        }
        return myData[position];
    }

    void print() const {
        for (size_t i = 0; i < counter; ++i) {
            std::cout << myData[i] << " ";
        }
        std::cout << std::endl;
    }
};
