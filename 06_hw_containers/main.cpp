#include <iostream>
#include "seq_container.cpp"
#include "list_container.cpp"

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


    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n";
    std::cout << "     Списковый контейнер    \n";
    ListContainer listContainer;

    for (int i = 0; i < 10; ++i) {
        listContainer.push_back(i);
    }
    std::cout << " Добавляем 10 элементов:\n";
    listContainer.print();

    std::cout << "Размер контейнера: " << listContainer.size() << " элементов. "<< std::endl;
    std::cout << "Удаляем элементы 3, 5, 7 и выводим что получилось: \n";
    listContainer.erase(2);
    listContainer.erase(3);
    listContainer.erase(4);
    listContainer.print();

    std::cout << "Добавляем число 10 в нулевую позицию и печатаем: \n";
    listContainer.insert(0, 10);
    listContainer.print();

    std::cout << "Добавляем число 20 на 4-ую)(5ю) позицию и печатаем: \n";
    listContainer.insert(4, 20);
    listContainer.print();

    std::cout << "Добавляем число 30 в конец и печатаем: \n";
    listContainer.push_back(30);
    listContainer.print();


}

