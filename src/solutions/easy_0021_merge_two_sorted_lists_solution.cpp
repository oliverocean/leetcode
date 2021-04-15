/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Merge Two Sorted Lists
 * @index: 021
 * @difficulty: easy
 * @topic: linked lists
 * @reqs: https://leetcode.com/problems/merge-two-sorted-lists/
 * @brief:
 *     Merge two sorted linked lists and return it as a new sorted list. The new
 *     list should be made by splicing together the nodes of the first two lists.
 * @example:
 *         Input: 1->2->4, 1->3->4
 *         Output: 1->1->2->3->4->4
 */

#include <iostream>
#include <vector>
#include <climits>

/* --- [ singly-linked list (given definition) ]--- */
class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/* ---[ function prototypes ]--- */
void createList(std::vector<ListNode> &aList);
void printList(ListNode *aList);
ListNode* mergeTwoLists(ListNode*, ListNode*);
ListNode* mergeTwoListsDebug(ListNode*, ListNode*);

/* ---[ function test driver ]--- */
int main()
{
    std::vector<ListNode> listOne{1, 2, 4, 6};
    std::vector<ListNode> listTwo{1, 3, 4, 8};

    createList(listOne);
    createList(listTwo);

    std::cout << "\n";
    std::cout << "> List One: ";
    printList(&listOne[0]);
    std::cout << "> List Two: ";
    printList(&listTwo[0]);

    std::cout << "\n<< merging lists...\n\n";
    mergeTwoLists(&listOne[0], &listTwo[0]);

    std::cout << "> List One: ";
    printList(&listOne[0]);
    std::cout << "> List Two: ";
    printList(&listTwo[0]);

    return 0;
}

/* ---[ final approach ]--- */
ListNode* mergeTwoLists(ListNode* listOne, ListNode* listTwo)
{
    auto head = new ListNode(INT_MIN);
    ListNode* tail = head;

    while (listOne && listTwo)
    {
        if (listOne->val < listTwo->val)
        {
            tail->next = listOne;
            listOne = listOne->next;
        }
        else
        {
            tail->next = listTwo;
            listTwo = listTwo->next;
        }
        tail = tail->next;
    }
    return head->next;
}


/* ---[ final approach with notes ]--- */
ListNode* mergeTwoListsDebug(ListNode* listOne, ListNode* listTwo)
{
    /* Notes: make a dummy node, use a 'tail' pointer to move back and forth
     * across the two lists, swap the pointers according to size,
     * repoint the list nodes to the next item (and 'seize' the evaluated nodes)
     * and keep the tail pointed to the last node of the 'new' list
     * after one list runs out, add the remaining list to the end and done*/

    // return head at end (using dummy node)
    auto head = new ListNode(INT_MIN);

    // pointer to traverse the lists
    ListNode* tail = head;

    // note: first iteration points head/dummy node to the smallest item
    while (listOne && listTwo)
    {
        if (listOne->val < listTwo->val)
        {
            tail->next = listOne;
            listOne = listOne->next;
        }
        else
        {
            tail->next = listTwo;
            listTwo = listTwo->next;
        }
        tail = tail->next;
    }

    /* Add the (larger) item(s) from the remaining list if listOne points to nullptr,
     * 'tail->next' = listTwo, otherwise listOne has items left over to add
     * can also do:
     * tail->next = listOne ? listOne : listTwo
     * tail->next = (listOne == nullptr) ? listTwo : listOne; */

    return head->next; // skips dummy node - is there a memory leak concern?
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