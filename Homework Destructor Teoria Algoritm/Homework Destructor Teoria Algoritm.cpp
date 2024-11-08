#include <iostream>
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};
class ForwardList {
public:
    Node* head;

    ForwardList() : head(nullptr) {}

    ~ForwardList() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        std::cout << "Список видалено" << std::endl;
    }
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) 
        {
            head = newNode;
        }
        else 
        {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    ForwardList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.display();
}
