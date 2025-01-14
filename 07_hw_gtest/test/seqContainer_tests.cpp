#include <gtest/gtest.h>
#include "seq_container.cpp"

TEST(SeqContainer, DefaultConstructor) {
    SeqContainer seqContainer;

    EXPECT_EQ(seqContainer.size(), 0);
}

TEST(SeqContainer, PushBack) {
    SeqContainer seqContainer;

    seqContainer.push_back(11);
    seqContainer.push_back(22);

    EXPECT_EQ(seqContainer.size(), 2);
    EXPECT_EQ(seqContainer[0], 11); // Not important in this test
    EXPECT_EQ(seqContainer[1], 22); // Not important in this test
}

TEST(SeqContainer, InsertAtBeginning) {
    SeqContainer seqContainer;
    seqContainer.push_back(11);

    seqContainer.insert(0, 22);

    EXPECT_EQ(seqContainer.size(), 2);
    EXPECT_EQ(seqContainer[0], 22);
    EXPECT_EQ(seqContainer[1], 11);
}

TEST(SeqContainer, InsertAtMiddle) {
    SeqContainer seqContainer;
    seqContainer.push_back(11);
    seqContainer.push_back(33);

    seqContainer.insert(1, 22);

    EXPECT_EQ(seqContainer.size(), 3);
    EXPECT_EQ(seqContainer[1], 22); // Check middle posiiton
}

TEST(SeqContainer, EraseFromEnd) {
    SeqContainer seqContainer;
    seqContainer.push_back(11);
    seqContainer.push_back(22);

    seqContainer.erase(1);

    EXPECT_EQ(seqContainer.size(), 1);
    EXPECT_EQ(seqContainer[0], 11);
}

TEST(SeqContainer, EraseFromBeginning) {
    SeqContainer seqContainer;
    seqContainer.push_back(11);
    seqContainer.push_back(22);

    seqContainer.erase(0);

    EXPECT_EQ(seqContainer.size(), 1);
    EXPECT_EQ(seqContainer[0], 22);
}

TEST(SeqContainer, EraseFromMiddle) {
    SeqContainer seqContainer;
    seqContainer.push_back(11);
    seqContainer.push_back(22);
    seqContainer.push_back(33);

    seqContainer.erase(1);

    EXPECT_EQ(seqContainer.size(), 2);
    EXPECT_EQ(seqContainer[0], 11);
    EXPECT_EQ(seqContainer[1], 33);
}

TEST(SeqContainer, OutOfRangeInsert) {
    SeqContainer seqContainer;

    EXPECT_THROW(seqContainer.insert(1, 5), std::out_of_range);
}

TEST(SeqContainer, OutOfRangeErase) {
    SeqContainer seqContainer;
    seqContainer.push_back(11);

    EXPECT_THROW(seqContainer.erase(1), std::out_of_range);
}

TEST(SeqContainer, AccessOutOfRange) {
    SeqContainer seqContainer;
    seqContainer.push_back(11);

    EXPECT_THROW(seqContainer[1], std::out_of_range);
}
