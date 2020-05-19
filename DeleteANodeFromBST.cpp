


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Input
// [5,3,6,2,4,null,7]
// 3
//

class Solution {
public:
    
    TreeNode* searchNode (TreeNode* root, int val)
    {
        if (root == nullptr) return root;
        if (val < root->val)
        {
            return searchNode (root->left, val);
        }
        return searchNode (root->right, val);
    }
    TreeNode * findSuccessor(TreeNode *root)
    {
        root = root->right;
        while(root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }
    TreeNode * findPredecesor(TreeNode *root)
    {
        root = root->left;
        while(root->right != nullptr)
        {
            root = root->right;
        }
        return root;
    }
//    5
//   / \
//  3   (6)
// / \   \
//2   4    7
   
    TreeNode* deleteNode(TreeNode* root, int val) {
       // TreeNode *node = searchNode(root, key);
        if (root == nullptr) return root;
        if (val < root->val)
        {
            root->left = deleteNode (root->left, val);
        }
        else if (val > root->val)
            root->right = deleteNode (root->right, val);
        else
        {
            // If node doesn't have any child
            if ((root->left == nullptr && root->right == nullptr))
            {
                delete root;
                root = nullptr;
                return root;
            }
            // If Node has only one child (either Left or Right)
            else if ( (root->left == nullptr) && (root->right != nullptr) )
            {
                    TreeNode*  temp = root;
                    root = root->right;
                    delete temp;
                    return root;
            }
            // If Node has only one child (either Left or Right)
            else if ( (root->left != nullptr) && (root->right == nullptr) )
            {
                     TreeNode*  temp = root;
                     root = root->left;
                     delete temp;
                     return root;
            }
            else //When there are two children
            {
                // Find the successor or Find minimum in right subtree
                TreeNode* temp = findSuccessor(root);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
         
};
