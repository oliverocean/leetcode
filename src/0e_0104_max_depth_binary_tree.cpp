/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Max Depth of Binary Tree
 * @index: 104
 * @difficulty: easy
 * @topic: tree, depth-first search
 * @reqs: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * @brief:
 *     Given a binary tree, find its maximum depth.
 *     The maximum depth is the number of nodes along the longest path from
 *     the root node down to the farthest leaf node.
 * @example:
 *     > Given binary tree [3, 9, 20, null, null, 15, 7]
 *               3
 *              / \
 *             9  20
 *               /  \
 *              15   7
 *     > Return  its depth = 3
 * @note: a leaf is a node with no children
 */

#include <iostream>
#include <vector>

/* ---[ binary node (given definition) ]--- */
struct BinaryNode
{
    int data;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode() : data(0), left(nullptr), right(nullptr) {}
    BinaryNode(int x) : data(x), left(nullptr), right(nullptr) {}
    BinaryNode(int x, BinaryNode* left, BinaryNode* right) : data(x), left(left), right(right) {}
 };

/* ---[ function prototypes ]--- */
BinaryNode* insertItem(BinaryNode*, int);
void preOrderDisplay(BinaryNode*);
void inOrderDisplay(BinaryNode*);
void postOrderDisplay(BinaryNode*);
int maxDepth(BinaryNode*);
int maxDepthAltOne(BinaryNode*);
int maxDepthAltTwo(BinaryNode*);

/* ---[ function test driver ]--- */
int main()
{
    std::cout << "\n---[ input ]---\n";
    std::cout << "<< creating new tree...\n";
    auto aTree = new BinaryNode(60);
    insertItem(aTree, 20);
    insertItem(aTree, 70);
    insertItem(aTree, 10);
    insertItem(aTree, 40);
    insertItem(aTree, 30);
    insertItem(aTree, 50);
    std::cout << "> tree (preorder) [ ";
    preOrderDisplay(aTree);
    std::cout << "]\n";
    std::cout << "> tree (inorder) [ ";
    inOrderDisplay(aTree);
    std::cout << "]\n";
    std::cout << "> tree (postorder) [ ";
    postOrderDisplay(aTree);
    std::cout << "]\n";

    std::cout << "\n---[ output ]---\n";
    std::cout << "> depth (dfs) [ " << maxDepth(aTree) << " ]\n";

    return 0;
}

/* ---[ dfs approach using max() ]--- */
/* runtime: 16ms @ 12%, memory: 19.2mb @ 96% */
int maxDepth(BinaryNode* root)
{
    if (!root) { return 0; }
    return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
}

/* came across this notation on LC; I don't think it works right but worth investigating */
int maxDepthAltOne(BinaryNode* root)
{
    if (!root) { return 0; }
    return root ? 1 + std::max(maxDepth(root->left), maxDepth(root->right)) : 0;
}

/* came across this notation on LC; I don't think it works right but worth investigating */
int maxDepthAltTwo(BinaryNode* root)
{
    if (!root) { return 0; }
    return root == nullptr ? 0 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

/* ---[ helper function for testing ]--- */
BinaryNode* insertItem(BinaryNode* aRoot, int item)
{
   if (aRoot == nullptr)
   {
       aRoot = new BinaryNode(item);
   }
   else if (item < aRoot->data)
   {
       aRoot->left = insertItem(aRoot->left, item);
   }
   else
   {
       aRoot->right = insertItem(aRoot->right, item);
   }
   return aRoot;
}

/* ---[ helper function for testing ]--- */
void preOrderDisplay(BinaryNode* aNode)
{
    if (aNode != nullptr)
    {
        std::cout << aNode->data << ", ";
        preOrderDisplay(aNode->left);
        preOrderDisplay(aNode->right);
    }
}

/* ---[ helper function for testing ]--- */
void inOrderDisplay(BinaryNode* aNode)
{
    if (aNode != nullptr)
    {
        inOrderDisplay(aNode->left);
        std::cout << aNode->data << ", ";
        inOrderDisplay(aNode->right);
    }
}

/* ---[ helper function for testing ]--- */
void postOrderDisplay(BinaryNode* aNode)
{
    if (aNode != nullptr)
    {
        postOrderDisplay(aNode->left);
        postOrderDisplay(aNode->right);
        std::cout << aNode->data << ", ";
    }
}

// EOF
