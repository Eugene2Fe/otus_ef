#include <gtest/gtest.h>
#include "list_container.cpp"

TEST(ListContainer, CreateListContainer_must_be_FAILED_THIS_TEST) {

    ListContainer listContainer;

    EXPECT_EQ(listContainer.size(), 111);
}

TEST(ListContainer, CreateListContainer) {

    ListContainer listContainer;

    EXPECT_EQ(listContainer.size(), 0);
}

TEST(ListContainer, PushBack) {
    ListContainer listContainer;

    listContainer.push_back(111);
    listContainer.push_back(222);

    EXPECT_EQ(listContainer.size(), 2);  // Запушбечили 2 элемента, значит ожидаем будет размер +2
    EXPECT_EQ(listContainer.get(0), 111); // Конкретная проверка элемента на позиции
    EXPECT_EQ(listContainer.get(1), 222);
}

TEST(ListContainer, InsertAtBeginning) {

    ListContainer listContainer ;
    listContainer.push_back(10); // Записываем первый элемент

    listContainer.insert(0, 333); // Вставляем на нулевую(первую позицию)

    EXPECT_EQ(listContainer.size(), 2); // ожидаем что вставилось 2 элемента в контейнере
    // EXPECT_EQ(listContainer[0], 333); // todo // контейнер не поддерживает вывод определенного элемента
}

TEST(ListContainer, InsertAtMiddle) {

    ListContainer listContainer;
    listContainer.push_back(444);
    listContainer.push_back(555);

    listContainer.insert(1, 666);

    EXPECT_EQ(listContainer.size(), 3);
}

TEST(ListContainer, EraseFromEnd) {

    ListContainer listContainer;
    listContainer.push_back(777);
    listContainer.push_back(888);

    listContainer.erase(1);

    EXPECT_EQ(listContainer.size(), 1);
}

TEST(ListContainer, EraseFromBeginning) {

    ListContainer listContainer;
    listContainer.push_back(777);
    listContainer.push_back(888);

    listContainer.erase(0);

    EXPECT_EQ(listContainer.size(), 1);
}

TEST(ListContainer, EraseFromMiddle) {

    ListContainer listContainer;
    listContainer.push_back(777);
    listContainer.push_back(888);
    listContainer.push_back(999);

    listContainer.erase(1);

    EXPECT_EQ(listContainer.size(), 2);
}

TEST(ListContainer, OutOfRangeInsert) {

    ListContainer listContainer;

    EXPECT_THROW(listContainer.insert(1, 5), std::out_of_range);
}

TEST(ListContainer, OutOfRangeErase) {

    ListContainer listContainer;
    listContainer.push_back(888);
    listContainer.push_back(999);

    EXPECT_THROW(listContainer.erase(2), std::out_of_range);
}

TEST(ListContainer, Size) {
    ListContainer listContainer;

    EXPECT_EQ(listContainer.size(), 0);

    listContainer.push_back(111);
    EXPECT_EQ(listContainer.size(), 1);

    listContainer.push_back(222);
    EXPECT_EQ(listContainer.size(), 2);
}