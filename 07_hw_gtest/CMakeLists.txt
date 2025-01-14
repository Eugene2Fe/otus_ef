cmake_minimum_required(VERSION 3.10)

project(ContainerTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SOURCES
    src/seq_container.cpp
    src/list_container.cpp
    test/seqContainer_tests.cpp
    test/listContainer_tests.cpp
    test/test_main.cpp
)


# Загрузка и настройка Google Tests
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)

# Указываем, что GTest собирается вместе с проектом
set(BUILD_GMOCK OFF) # Выключаем сборку GMock (если не нужен)
set(INSTALL_GTEST OFF) # Выключаем установку GTest
FetchContent_MakeAvailable(googletest)

# Генерим исполняемый файл для тестов
add_executable(ContainerTests ${SOURCES})

# Линковка с GTest и потоками
target_link_libraries(ContainerTests gtest gtest_main pthread)

# Указпли путь к инклудам
target_include_directories(ContainerTests PUBLIC ${PROJECT_SOURCE_DIR}/src)
