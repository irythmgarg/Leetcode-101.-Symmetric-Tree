/**
 * Definition for a binary tree node.
 * Struct representing each node of a binary tree with integer value and pointers to left and right children.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value only
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value, left and right children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * Helper function to recursively check whether two subtrees are mirror images of each other.
     * @param root1: Root of the first subtree
     * @param root2: Root of the second subtree
     * @return true if both subtrees are mirror images, false otherwise
     */
    bool isSymm(TreeNode* root1, TreeNode* root2)
    {
        // Both nodes are null, so they are symmetric
        if (!root1 && !root2)
            return true;

        // One of the nodes is null or values don't match => not symmetric
        if ((root1 && !root2) || (!root1 && root2) || (root1->val != root2->val))
            return false;

        // Recursively check if left subtree of root1 and right subtree of root2 are mirror,
        // and right subtree of root1 and left subtree of root2 are mirror
        if (isSymm(root1->left, root2->right) && isSymm(root1->right, root2->left))
            return true;

        return false;
    }

    /**
     * Main function to check if a binary tree is symmetric around its center.
     * @param root: Root of the binary tree
     * @return true if tree is symmetric, false otherwise
     */
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return isSymm(root->left, root->right);
    }
};
