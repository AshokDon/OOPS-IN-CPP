#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    // Creating a linked list of integers
    LinkedList<int> intList;
    intList.append(1);
    intList.append(2);
    intList.append(3);

    std::cout << "Integer Linked List: ";
    intList.display();

    // Creating a linked list of strings
    LinkedList<std::string> strList;
    strList.append("Hello");
    strList.append("World");
    strList.append("!");

    std::cout << "String Linked List: ";
    strList.display();

    return 0;
}
