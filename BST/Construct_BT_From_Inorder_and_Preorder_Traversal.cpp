// Problem: Construct Binary Tree from Preorder and Inorder Traversal
// Given preorder and inorder traversal of a binary tree, construct the binary tree.

// Intuition:
// - Preorder gives the root first.
// - Inorder helps us split into left and right subtrees.
// - Use a hashmap to quickly find the root index in inorder.
// - Recursively build left and right subtrees.

// Approach:
// 1. Build a map from inorder values to their indices.
// 2. Use a global/preorder index to pick the root from preorder.
// 3. Recursively construct left and right subtrees using inorder segments.
// 4. Base case: if start > end, return NULL.

// Time Complexity: O(N)  (N = number of nodes)
// Space Complexity: O(N) (hashmap + recursion stack)

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
    int idx = 0;                // Preorder index
    unordered_map<int, int> mp; // Map inorder value -> index

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // Store inorder positions in hashmap
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return traversal(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode *traversal(vector<int> &preorder, int st, int end)
    {
        if (st > end)
        {
            return NULL;
        }

        // Pick root from preorder
        int rootVal = preorder[idx++];
        TreeNode *root = new TreeNode(rootVal);

        // Find root in inorder
        int mid = mp[rootVal];

        // Build left and right subtrees
        root->left = traversal(preorder, st, mid - 1);
        root->right = traversal(preorder, mid + 1, end);

        return root;
    }
};

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);

    // Simple check: print inorder of constructed tree
    function<void(TreeNode *)> printInorder = [&](TreeNode *node)
    {
        if (!node)
            return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    };

    cout << "Constructed Tree Inorder: ";
    printInorder(root);
    cout << endl;

    return 0;
}
