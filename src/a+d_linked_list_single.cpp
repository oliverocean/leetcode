#include <array>
#include <string>
#include <climits>

struct Node {
    int _data;
    struct Node* next;

    Node(int data) : _data(data), next(nullptr) {}
};

struct List {
    Node* head;
    Node* tail;
    Node* current;

    void add_to_head(int data) {

        Node* node = new Node(data);

        if (head == nullptr) {
            tail = node;
        } else {
            node->next = head;
        }
        head = node;
    }

    void add_to_tail(int data) {

        Node* node = new Node(data);

        if (head == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    void add_at_index(int data, int index) {

        Node* node = new Node(data);

        current = head;
        int position = 0;

        while(position != index) {
            current = current->next;
            position++;
        }
        current->next = node;
    }

    void remove_head() {
        Node* node = head;
        head = head->next;
        delete node;
    }

    void remove_tail() {
        //TODO
        // pp 808, D+D
    }

};
