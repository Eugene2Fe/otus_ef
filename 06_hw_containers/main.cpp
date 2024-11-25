#include <iostream>
#include "seq_container.cpp"

int main() {
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n";
    std::cout << "     Последовательный контейнер    \n";
    SeqContainer seqContainer;

    for (int i = 0; i < 10; ++i) {
        seqContainer.push_back(i);
    }
    std::cout << " Добавляем 10 элементов:\n";
    seqContainer.print();

    std::cout << "Размер контейнера: " << seqContainer.size() << " элементов. "<< std::endl;
    std::cout << "Удаляем элементы 3, 5, 7 и выводим что получилось: \n";
    seqContainer.erase(2);
    seqContainer.erase(3);
    seqContainer.erase(4);
    seqContainer.print();

    std::cout << "Добавляем число 10 в нулевую позицию и печатаем: \n";
    seqContainer.insert(0, 10);
    seqContainer.print();

    std::cout << "Добавляем число 20 на 4-ую)(5ю) позицию и печатаем: \n";
    seqContainer.insert(4, 20);
    seqContainer.print();

    std::cout << "Добавляем число 30 в конец и печатаем: \n";
    seqContainer.push_back(30);
    seqContainer.print();

    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n";


    // std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n";
    // std::cout << "     Списковый контейнер    \n";
    // SeqContainer seqContainer;

    // for (int i = 0; i < 10; ++i) {
    //     seqContainer.push_back(i);
    // }
    // std::cout << " Добавляем 10 элементов:\n";
    // seqContainer.print();

}

