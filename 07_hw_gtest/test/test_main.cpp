#include <iostream>
// #include "seqContainer_tests.cpp"   // Это зло!!! из-за него не билдится
// #include "listContainer_tests.cpp"  // Это зло!!! из-за него не билдится
#include <gtest/gtest.h>

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
