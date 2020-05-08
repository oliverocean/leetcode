/**
 * @file: 104-max-depth-binary-tree.cpp
 * @author: Oliver Ocean <code@oliver.work>
 * @brief: Given an binary tree, find its maximum depth
 * @note: A leaf is a node with no children
 * @example:
 *  Given binary tree [3, 9, 20, null, null, 15, 7]
 *        3
 *       / \
 *      9  20
 *        /  \
 *       15   7
 *  Return  its depth = 3
 *
 */

#include <iostream>
#include <vector>

// Given definition for a binary tree node:
struct BinaryNode
{
    int data;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode() : data(0), left(nullptr), right(nullptr) {}
    BinaryNode(int x) : data(x), left(nullptr), right(nullptr) {}
    BinaryNode(int x, BinaryNode* left, BinaryNode* right) : data(x), left(left), right(right) {}
 };

// functions for testing
BinaryNode* insertItem(BinaryNode*, int);
void preOrderDisplay(BinaryNode*);
void inOrderDisplay(BinaryNode*);
void postOrderDisplay(BinaryNode*);

// function prototype (from requirements)
int maxDepth(BinaryNode*);

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

// dfs approach
// runtime 16ms @ 12%, memory 19.2mb @ 96%
int maxDepth(BinaryNode* root)
{
    if (!root) { return 0; }
    return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);

    // // alternate notations
    // return root ? 1 + std::max(maxDepth(root->left), maxDepth(root->right)) : 0;
    // return root == nullptr ? 0 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// <-- [ functions for testing ]--> //
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

void preOrderDisplay(BinaryNode* aNode)
{
    if (aNode != nullptr)
    {
        std::cout << aNode->data << ", ";
        preOrderDisplay(aNode->left);
        preOrderDisplay(aNode->right);
    }
}

void inOrderDisplay(BinaryNode* aNode)
{
    if (aNode != nullptr)
    {
        inOrderDisplay(aNode->left);
        std::cout << aNode->data << ", ";
        inOrderDisplay(aNode->right);
    }
}

void postOrderDisplay(BinaryNode* aNode)
{
    if (aNode != nullptr)
    {
        postOrderDisplay(aNode->left);
        postOrderDisplay(aNode->right);
        std::cout << aNode->data << ", ";
    }
}
