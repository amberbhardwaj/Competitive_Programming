/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* node = root;
        while (node != nullptr)
        {
            if (p->val < node->val && q->val < node->val)
            {
                node = node->left;
                //cout << "Moved to left =" << node->val << "\n";
            }
            else if (p->val > node->val && q->val > node->val)
            {
                node = node->right;
                //cout << "Moved to right =" << node->val << "\n";
            }
            else
            {
                //cout << "Kahi Nahi Gya =" << node->val <<"\n";
                return node;   
            }
        }
        return nullptr;
    }
};
