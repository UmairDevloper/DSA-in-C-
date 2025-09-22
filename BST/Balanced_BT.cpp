// Problem: Balanced Binary Tree
// Link: LeetCode 110
// Statement: Given a binary tree, determine if it is height-balanced.
// A binary tree is height-balanced if the depths of the two subtrees of every node
// never differ by more than 1.

// Intuition:
// - At each node, check if its left and right subtrees are balanced.
// - A node is balanced if:
//     (1) Left subtree is balanced
//     (2) Right subtree is balanced
//     (3) The difference in their heights <= 1
// - We compute balance and height simultaneously in a bottom-up recursion.

// Approach:
// 1. Use DFS recursion that returns both whether the subtree is balanced and its height.
// 2. Base case: null node is balanced with height = 0.
// 3. Recursively get (balanced, height) from left and right children.
// 4. A node is balanced if left and right are balanced AND |lh - rh| <= 1.
// 5. Return this info up the recursion stack.

// Time Complexity: O(N)  (N = number of nodes, each visited once)
// Space Complexity: O(H) (H = height of tree, recursion stack; O(logN) for balanced tree, O(N) worst case)

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
public:
    bool isBalanced(TreeNode *root)
    {
        return dfs(root).first;
    }

private:
    // Return pair<isBalanced, height>
    pair<bool, int> dfs(TreeNode *node)
    {
        if (!node)
            return make_pair(true, 0);

        pair<bool, int> leftRes = dfs(node->left);
        pair<bool, int> rightRes = dfs(node->right);

        bool currBalanced = leftRes.first && rightRes.first && abs(leftRes.second - rightRes.second) <= 1;
        int currHeight = 1 + max(leftRes.second, rightRes.second);

        return make_pair(currBalanced, currHeight);
    }
};

int main()
{
    // Example 1: Balanced Tree
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    Solution sol;
    cout << "Tree 1 is balanced? " << (sol.isBalanced(root1) ? "Yes" : "No") << endl;

    // Example 2: Unbalanced Tree
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);

    cout << "Tree 2 is balanced? " << (sol.isBalanced(root2) ? "Yes" : "No") << endl;

    return 0;
}
