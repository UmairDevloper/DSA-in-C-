// Problem: Binary Tree Level Order Traversal
// Given the root of a binary tree, return the level order traversal of its nodes' values.
// (i.e., from left to right, level by level).

// Intuition:
// Level Order Traversal is naturally done using a Queue (BFS).
// We process nodes level by level: first the root, then its children, then grandchildren, etc.

// Approach (BFS):
// 1. If the root is NULL, return an empty result.
// 2. Use a queue to store nodes while traversing.
// 3. For each level, find the size of the queue (number of nodes at that level).
// 4. Process all nodes of that level, pushing their values into a vector.
// 5. Push children (left and right) into the queue for the next level.
// 6. Continue until the queue is empty.

// Time Complexity: O(N), where N is the number of nodes (each node visited once).
// Space Complexity: O(N), for the queue in the worst case (last level of tree).

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        queue<TreeNode *> q;
        vector<vector<int>> res;

        q.push(root);
        int currlvl = 0;

        while (!q.empty())
        {
            int len = q.size();
            res.push_back({});

            for (int i = 0; i < len; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                res[currlvl].push_back(node->val);

                if (node->left != NULL)
                {
                    q.push(node->left);
                }

                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            currlvl++;
        }
        return res;
    }
};

int main()
{
    // Example usage:
    // Construct binary tree:
    //        3
    //       / \
    //      9  20
    //        /  \
    //       15   7
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> ans = sol.levelOrder(root);

    cout << "Level Order Traversal: " << endl;
    for (auto &level : ans)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
