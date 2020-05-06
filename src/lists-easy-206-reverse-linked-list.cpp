#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

// function prototypes
ListNode* reverseList(ListNode*);
void createList(std::vector<ListNode>&);
void printList(ListNode*);

int main() {

    ListNode* prev = nullptr;

    std::vector<ListNode> rawList{1, 2, 3, 4, 5, 6, 7, 8};
    createList(rawList);
    ListNode* list = &rawList[0];

    std::cout << "\n---[ input ]---\n";
    printList(list);

    std::cout << "\n---[ debug ]---\n";
    prev = reverseList(list);

    std::cout << "\n---[ output ]---\n";
    printList(prev);

    return 0;
}

// revised submission, runtime: 8ms @ 94.88%, memory: 9mb @ 100%
// rather than abandon 'head', use as a 'current' pointer (jumps back and forth)
ListNode* reverseList(ListNode* head) {

    ListNode* reversed = nullptr;
    ListNode* origin = nullptr;

    while (head) {
        origin = head->next;
        head->next = reversed;
        reversed = head; // don't forget this step!
        head = origin;
    }

    return reversed;
}


//// initial attempt: runtime error "member access within null pointer of type "struct ListNode"
//ListNode* reverseList(ListNode* head) {
//
//    ListNode* reversed = head;
//    ListNode* current = head->next;
//
//    // split lists
//    head = head->next;
//    reversed->next = nullptr;
//
//    while (head != nullptr) {
//        head = head->next;
//        current->next = reversed;
//        reversed = current; // don't forget to move reverse ('head') to first node!!
//        current = head;
//    }
//
//    return reversed;
//}


void createList(std::vector<ListNode>& list) {
    ListNode *nnode = nullptr;
    for (auto node = list.rbegin(); node != list.rend(); ++node) {
        node->next = nnode;
        nnode = &(*node);
    }
}

void printList(ListNode* list) {
    std::cout << "[ ";
    while (list) {
        std::cout << list->val << " ";
        list = list->next;
    }
    std::cout << "]\n";
}

