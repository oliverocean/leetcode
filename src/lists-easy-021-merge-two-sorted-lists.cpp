#include <iostream>
#include <vector>

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// function prototypes
void createList(std::vector<ListNode> &list);
void printList(ListNode *l);
ListNode* mergeTwoLists(ListNode*, ListNode*);


int main() {

    // useful test harness found on LC
    std::vector<ListNode> l1{1, 2, 4, 6};
    std::vector<ListNode> l2{1, 3, 4, 8};
    createList(l1);
    std::cout << "1: ";
    printList(&l1[0]);
    createList(l2);
    std::cout << "2: ";
    printList(&l2[0]);
    mergeTwoLists(&l1[0], &l2[0]);
    std::cout << "3: ";
    printList(&l1[0]);
    std::cout << "4: ";
    printList(&l2[0]);

    return 0;
}

// approach:
// make a dummy node, use a 'tail' pointer to move back and forth
// across the two lists, swap the pointers according to size,
// repoint the list nodes to the next item (and 'seize' the evaluated nodes)
// and keep the tail pointed to the last node of the 'new' list
// after one list runs out, add the remaining list to the end and done

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    // head to be returned at end (using dummy node)
    auto head = new ListNode(INT_MIN);

    // pointer to traverse the lists
    ListNode* tail = head;

    // note, the first round points head/dummy node to the smallest item
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Add the (larger) item(s) from the remaining list
    // if l1 points to nullptr, 'tail->next' = l2, otherwise l1 has items left over to add
    // can also do:
    // tail->next = l1 ? l1 : l2
    tail->next = (l1 == nullptr) ? l2 : l1;

    return head->next; // skips dummy node - is there a memory leak concern?
}


// useful test harness found on LC
void createList(std::vector<ListNode>& list) {
    ListNode *nnode = nullptr;
    for (auto node = list.rbegin(); node != list.rend(); ++node) {
        node->next = nnode;
        nnode = &(*node);
    }
}

void printList(ListNode* l) {
    std::cout << "• ";
    while (l) {
        std::cout << l->val << " • ";
        l = l->next;
    }
    std::cout << "\n";
}