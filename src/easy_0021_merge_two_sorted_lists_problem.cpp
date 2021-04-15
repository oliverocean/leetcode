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


//----------------------------------------------------------------------------//
//--- [ singly-linked list (given definition) ]---//
class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


//----------------------------------------------------------------------------//
//---[ helper ]---//
void createList(std::vector<ListNode>& aList)
{
    ListNode *nextNode = nullptr;
    for (auto node = aList.rbegin(); node != aList.rend(); ++node)
    {
        node->next = nextNode;
        nextNode = &(*node);
    }
}


//----------------------------------------------------------------------------//
//---[ helper ]---//
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


//----------------------------------------------------------------------------//
//---[ option a ]---//
ListNode* mergeTwoLists(ListNode* listOne, ListNode* listTwo)
{
    //TODO
}


//----------------------------------------------------------------------------//
//---[ driver ]---//
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
//----------------------------------------------------------------------------//
//---[ eof ]---//
