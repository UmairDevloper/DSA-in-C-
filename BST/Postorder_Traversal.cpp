#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// 📝 Problem Statement:
// Given the root of a binary tree, return its nodes' values in postorder traversal.
// Postorder traversal order: Left → Right → Root
// -----------------------------------------------------------------------------

// 💡 Intuition:
// In postorder traversal, we visit all nodes in the left subtree first,
// then all nodes in the right subtree, and finally process the root node.
//
// For example, in a tree:
//        1
//       / \
//      2   3
//     / \
//    4   5
//
// Postorder traversal = [4, 5, 2, 3, 1]

// 📚 Approach (Recursive DFS):
// 1. Define a helper function `postorder(node, res)`.
// 2. Base case: If node is NULL, return.
// 3. Recursively traverse left subtree.
// 4. Recursively traverse right subtree.
// 5. Process the current node (push its value into result vector).
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        postorder(root, res);
        return res;
    }

private:
    void postorder(TreeNode *node, vector<int> &res)
    {
        if (!node)
            return;
        postorder(node->left, res);  // Left
        postorder(node->right, res); // Right
        res.push_back(node->val);    // Root
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
    vector<int> result = sol.postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl; // Output: 4 5 2 3 1

    return 0;
}
