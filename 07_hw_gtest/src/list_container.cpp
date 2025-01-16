#include <iostream>
#include <stdexcept> // lib for exception print

class ListContainer {
private:
    struct Node {
        int value;    // Значение элемента узла
        Node* prev;   // Указатель на предыдущий элем
        Node* next;   // Указатель на следующий элем

        // Конструктор структуры элемента узла
        Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;       // Указатель на начало списка
    Node* tail;       // Указатель на конец списка
    size_t counter;     // Количество элементов в списке

public:
    ListContainer() : head(nullptr), tail(nullptr), counter(0) {
        try {
            // выделяем памяти тестово для тестового узла
            Node* testNode = new Node(0);
            if (!testNode) {
                throw std::runtime_error("Failed to allocate memory for ListContainer!");
            }
            delete testNode;
        } catch (const std::exception& e) {
            std::cerr << "Exception in ListContainer constructor: " << e.what() << std::endl;
            throw;
        }
    }

    // Destr for make free memory
    ~ListContainer() {
        while (head) {
            Node* temp = head; // сейвим текущий узел
            head = head->next; // Переходим к следующему узлу
            delete temp; // и удаляем текущий
        }
    }

    // 1. добавляет элемент в конец списка
    void push_back(int value) {
        Node* newNode = new Node(value); // Создаём новый узел
        if (!tail) { // Если список пуст
            head = tail = newNode;
        } else { // Если есть элементы
            tail->next = newNode; // Привязываем новый узел к концу
            newNode->prev = tail;
            tail = newNode; // Обновляем указатель на конец
        }
        ++counter; // Увеличиваем счётчик
    }

    // 2. вставка элемента на точную указанную позицию
    void insert(size_t index, int value) {
        if (index > counter) {
            throw std::out_of_range("position out of range");
        }

        Node* newNode = new Node(value); // Создание нового узла

        if (index == 0) {
            // в начало
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = head;
        } else if (index == counter) {
            // в конец
            push_back(value);
            return;
        } else {
            // по индексу позиции
            Node* current = head;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
        ++counter;
    }

    // 3. удаление элемента по точной указанной позиции
    void erase(size_t index) {
        if (index >= counter) {
            throw std::out_of_range("position out of range");
        }

        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        if (current->prev) { // Убираем связь с предыдущим узлом
            current->prev->next = current->next;
        } else { // На случай если удаляем первый узел
            head = current->next;
        }

        if (current->next) { // Убираем связь с следующим узлом
            current->next->prev = current->prev;
        } else { // На случай если удаляем последний узел
            tail = current->prev;
        }

        delete current;
        --counter;
    }

    // 4. получение размера контейнера
    size_t size() const {
        return counter;
    }

    void print() const {
        Node* current = head;
        while (current) { // проходим по всем узлам и печать их
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
