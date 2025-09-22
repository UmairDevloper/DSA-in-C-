#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// 📝 Problem Statement:
// Given the root of a binary tree, return its nodes' values in inorder traversal.
// Inorder traversal order: Left → Root → Right
// -----------------------------------------------------------------------------

// 💡 Intuition:
// In inorder traversal, we first visit all nodes in the left subtree,
// then process the root, and finally visit the right subtree.
//
// Example tree:
//        1
//       / \
//      2   3
//     / \
//    4   5
//
// Inorder traversal = [4, 2, 5, 1, 3]

// 📚 Approach (Recursive DFS):
// 1. Define helper function `inorder(node, res)`.
// 2. Base case: If node is NULL, return.
// 3. Recursively traverse left subtree.
// 4. Process current node (push into result).
// 5. Recursively traverse right subtree.
// -----------------------------------------------------------------------------

// ⏱️ Time Complexity: O(N)
//   - Each node is visited once.
// 🛢️ Space Complexity: O(H)
//   - Recursion stack where H = height of tree.
//   - Worst case O(N) for skewed tree, O(logN) for balanced tree.
// -----------------------------------------------------------------------------

// Definition for a binary tree node
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
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        inorder(root, res);
        return res;
    }

private:
    void inorder(TreeNode *node, vector<int> &res)
    {
        if (!node)
        {
            return;
        }
        inorder(node->left, res);  // Left
        res.push_back(node->val);  // Root
        inorder(node->right, res); // Right
    }
};

// -----------------------------------------------------------------------------
// 🖥️ Example usage (for VS Code testing):
// -----------------------------------------------------------------------------
int main()
{
    // Constructing a simple tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl; // Output: 4 2 5 1 3

    return 0;
}
