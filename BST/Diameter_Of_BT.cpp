/*
Problem Statement:
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes.
This path may or may not pass through the root.

Note:
- The length of a path is the number of edges between nodes.

Intuition:
The diameter can be found by computing the height of left and right subtrees
for each node. At every node:
- Path through that node = left height + right height.
- Update the maximum diameter if this path is longer than the current best.
Finally, return the maximum diameter found.

Theory Approach:
1. Perform a DFS recursion.
2. For each node:
   - Recursively compute left subtree height.
   - Recursively compute right subtree height.
   - Update global result = max(result, left height + right height).
3. Return 1 + max(left height, right height) as the height for recursion.
4. At the end, result will hold the diameter.

Time Complexity: O(n)
   - Each node is visited once.
Space Complexity: O(h)
   - h = height of the tree (recursion stack).
*/

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
    int diameterRecur(TreeNode *root, int &res)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lheight = diameterRecur(root->left, res);
        int rheight = diameterRecur(root->right, res);

        // Update diameter if a larger path is found
        res = max(res, lheight + rheight);

        return 1 + max(rheight, lheight);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int res = 0;
        diameterRecur(root, res);
        return res;
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

        Longest Path: 4 -> 2 -> 5 (or 4 -> 2 -> 1 -> 3)
        Diameter: 3 edges
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Diameter of Binary Tree: " << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}
