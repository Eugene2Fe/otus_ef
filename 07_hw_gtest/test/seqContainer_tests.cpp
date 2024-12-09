#include <gtest/gtest.h>
#include "seq_container.cpp"

TEST(SeqContainer, DefaultConstructor) {
    // Arrange
    SeqContainer seqContainer;

    // Assert
    EXPECT_EQ(seqContainer.size(), 0);
}

TEST(SeqContainer, PushBack) {
    // Arrange
    SeqContainer seqContainer;

    // Act
    seqContainer.push_back(11);
    seqContainer.push_back(22);

    // Assert
    EXPECT_EQ(seqContainer.size(), 2);
    EXPECT_EQ(seqContainer[0], 11); // Not important in this test
    EXPECT_EQ(seqContainer[1], 22); // Not important in this test
}

TEST(SeqContainer, InsertAtBeginning) {
    // Arrange
    SeqContainer seqContainer;
    seqContainer.push_back(11);

    // Act
    seqContainer.insert(0, 22);

    // Assert
    EXPECT_EQ(seqContainer.size(), 2);
    EXPECT_EQ(seqContainer[0], 22);
    EXPECT_EQ(seqContainer[1], 11);
}

TEST(SeqContainer, InsertAtMiddle) {
    // Arrange
    SeqContainer seqContainer;
    seqContainer.push_back(11);
    seqContainer.push_back(33);

    // Act
    seqContainer.insert(1, 22);

    // Assert
    EXPECT_EQ(seqContainer.size(), 3);
    EXPECT_EQ(seqContainer[1], 22); // Check middle posiiton
}

TEST(SeqContainer, EraseFromEnd) {
    // Arrange
    SeqContainer seqContainer;
    seqContainer.push_back(11);
    seqContainer.push_back(22);

    // Act
    seqContainer.erase(1);

    // Assert
    EXPECT_EQ(seqContainer.size(), 1);
    EXPECT_EQ(seqContainer[0], 11);
}

TEST(SeqContainer, EraseFromBeginning) {
    // Arrange
    SeqContainer seqContainer;
    seqContainer.push_back(11);
    seqContainer.push_back(22);

    // Act
    seqContainer.erase(0);

    // Assert
    EXPECT_EQ(seqContainer.size(), 1);
    EXPECT_EQ(seqContainer[0], 22);
}

TEST(SeqContainer, EraseFromMiddle) {
    // Arrange
    SeqContainer seqContainer;
    seqContainer.push_back(11);
    seqContainer.push_back(22);
    seqContainer.push_back(33);

    // Act
    seqContainer.erase(1);

    // Assert
    EXPECT_EQ(seqContainer.size(), 2);
    EXPECT_EQ(seqContainer[0], 11);
    EXPECT_EQ(seqContainer[1], 33);
}

TEST(SeqContainer, OutOfRangeInsert) {
    // Arrange
    SeqContainer seqContainer;

    // Act and Assert
    EXPECT_THROW(seqContainer.insert(1, 5), std::out_of_range);
}

TEST(SeqContainer, OutOfRangeErase) {
    // Arrange
    SeqContainer seqContainer;
    seqContainer.push_back(11);

    // Act and Assert
    EXPECT_THROW(seqContainer.erase(1), std::out_of_range);
}

TEST(SeqContainer, AccessOutOfRange) {
    // Arrange
    SeqContainer seqContainer;
    seqContainer.push_back(11);

    // Act & Assert
    EXPECT_THROW(seqContainer[1], std::out_of_range);
}
