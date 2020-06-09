/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Reverse Linked List
 * @index: 206
 * @difficulty: easy
 * @topic: linked lists
 * @reqs: https://leetcode.com/problems/reverse-linked-list/
 * @brief:
 *     Reverse a singly linked list.
 * @example:
 *     Input: 1->2->3->4->5->NULL
 *     Output: 5->4->3->2->1->NULL
 */

#include <iostream>
#include <vector>

/* --- [ singly-linked list (given definition) ]--- */
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

/* ---[ function prototypes ]--- */
ListNode* reverseList(ListNode*);
void createList(std::vector<ListNode>&);
void printList(ListNode*);

/* ---[ function test driver ]--- */
int main()
{
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

/* ---[ revised approach ]--- */
/* runtime: 8ms @ 94.88%, memory: 9mb @ 100% */
/* Note: rather than abandon 'head', use as a 'current' pointer (jumps back and forth) */
ListNode* reverseList(ListNode* head)
{
    ListNode* reversed = nullptr;
    ListNode* origin = nullptr;

    while (head)
    {
        origin = head->next;
        head->next = reversed;
        reversed = head; // don't forget this step!
        head = origin;
    }
    return reversed;
}

/* ---[ initial approach ]--- */
/* Note: passed some unit tests but not all... encountered a runtime
 * error :( "member access within null pointer of type "struct ListNode" */
ListNode* reverseListAltOne(ListNode* head)
{
    ListNode* reversed = head;
    ListNode* current = head->next;

    // split lists
    head = head->next;
    reversed->next = nullptr;

    while (head != nullptr)
    {
        head = head->next;
        current->next = reversed;
        reversed = current; // don't forget to move reverse ('head') to first node!!
        current = head;
    }
    return reversed;
}

/* ---[ modified test function found on LC ]--- */
void createList(std::vector<ListNode>& aList)
{
    ListNode *nextNode = nullptr;
    for (auto node = aList.rbegin(); node != aList.rend(); ++node)
    {
        node->next = nextNode;
        nextNode = &(*node);
    }
}

/* ---[ test helper function ]--- */
void printList(ListNode* aList)
{
    std::cout << "[ ";
    while (aList)
    {
        std::cout << aList->val << ", ";
        aList = aList->next;
    }
    std::cout << "]\n";
}

// EOF