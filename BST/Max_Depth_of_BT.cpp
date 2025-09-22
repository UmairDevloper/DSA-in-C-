/*
Problem Statement:
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.

Intuition:
The maximum depth of a binary tree can be found by exploring both the left and right
subtrees recursively. At each node, the maximum depth is 1 (for the current node)
plus the maximum of the depths of its left and right subtrees.

Theory Approach:
1. If the root is NULL, the depth is 0.
2. Recursively find the depth of the left subtree.
3. Recursively find the depth of the right subtree.
4. The answer for the current node is:
   1 + max(depth of left subtree, depth of right subtree).

Time Complexity: O(n)
   - Each node is visited once.
Space Complexity: O(h)
   - h = height of the tree (due to recursion stack).
*/

// Your solution code starts here
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    int maxDepth(TreeNode *root)
    {
        int ans = 0;
        if (root == NULL)
        {
            return ans;
        }
        int lheight = maxDepth(root->left);
        int rheight = maxDepth(root->right);
        return ans + 1 + max(lheight, rheight);
    }
};

// Driver code
int main()
{
    /*
        Example Tree:
               1
              / \
             2   3
            / \
           4   5

        Expected Output: 3 (path: 1 -> 2 -> 4 or 1 -> 2 -> 5)
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Maximum Depth: " << sol.maxDepth(root) << endl;

    return 0;
}
