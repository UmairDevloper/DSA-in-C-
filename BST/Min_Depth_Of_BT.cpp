#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// 📝 Problem Statement:
// Given a binary tree, find its minimum depth. The minimum depth is the number
// of nodes along the shortest path from the root node down to the nearest leaf node.
// -----------------------------------------------------------------------------

// 💡 Intuition:
// The minimum depth is the shortest path from root to a leaf.
// If we traverse level by level (BFS), the first time we hit a leaf node,
// that depth will be the minimum depth.
// This is more efficient than DFS, where we might explore unnecessary deeper paths.

// 📚 Approach (BFS):
// 1. If root is NULL, return 0.
// 2. Use a queue to do level-order traversal.
// 3. Track depth starting from 1 (root level).
// 4. For each node, check if it is a leaf (no left & right child).
//    - If yes, return current depth (shortest path found).
//    - Else, push its children into the queue.
// 5. Increment depth after each level.
// -----------------------------------------------------------------------------

// ⏱️ Time Complexity: O(N)
//   - Each node is visited once in the BFS traversal.
//
// 🛢️ Space Complexity: O(N)
//   - At worst, the queue stores all nodes of the last level.
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
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        queue<TreeNode *> q;
        q.push(root);
        int depth = 1;

        while (!q.empty())
        {
            int lvl = q.size();

            for (int i = 0; i < lvl; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // If it's a leaf node, return current depth
                if (node->left == NULL && node->right == NULL)
                {
                    return depth;
                }

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            depth++;
        }
        return depth;
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
    //    /
    //   4
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution sol;
    cout << sol.minDepth(root) << endl; // Output: 2 (path 1 -> 3)

    return 0;
}
