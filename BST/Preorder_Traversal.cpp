// Problem: Binary Tree Preorder Traversal
// Given the root of a binary tree, return the preorder traversal of its nodes' values.
// Preorder means: Visit Root -> Left Subtree -> Right Subtree

// Intuition:
// In preorder traversal, we always visit the root node first,
// then recursively visit the left child, and finally the right child.

// Approach (Recursive):
// 1. Start from the root node.
// 2. Push the root value into the result vector.
// 3. Recursively call the preorder function for the left subtree.
// 4. Recursively call the preorder function for the right subtree.
// 5. Return the result vector.

// Time Complexity: O(N), where N is the number of nodes (each node is visited once).
// Space Complexity: O(H), where H is the height of the tree (recursive stack).
// In the worst case (skewed tree), H = N.

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void preorder(TreeNode *node, vector<int> &res)
    {
        if (!node)
        {
            return;
        }
        res.push_back(node->val);   // Visit root
        preorder(node->left, res);  // Traverse left
        preorder(node->right, res); // Traverse right
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};

int main()
{
    // Example usage:
    // Constructing binary tree:
    //        1
    //         \
    //          2
    //         /
    //        3
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> ans = sol.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
