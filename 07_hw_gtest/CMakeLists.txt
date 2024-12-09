cmake_minimum_required(VERSION 3.10)

project(ContainerTests)

set(CMAKE_CXX_STANDARD 17)

# Добавляем GTest
find_package(GTest REQUIRED)

# Инклудим исходники
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/src) 
# без этого тоже не билдилось, хотя следующей командой были указаны пути к сорцам

set(SOURCES
    src/seq_container.cpp
    src/list_container.cpp
    test/seqContainer_tests.cpp
    test/listContainer_tests.cpp
    test/test_main.cpp
)

# Выбираем имя исполняемому файлу для тестов
add_executable(ContainerTests ${SOURCES})

# Линковка с гугл тест
target_link_libraries(ContainerTests ${GTEST_LIBRARIES} pthread)
