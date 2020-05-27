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

/*
Input:
For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6

Output:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/
class Solution {
public:
    void flatten(TreeNode* root) {
     
        /* As you can see the output of the code is on the right side of the tree 
            and it is similar to preorder traversal so just implement a iterative 
            solution. 
        */
        if (root == nullptr) return;
        //Similar to recursion but explicit
        stack<TreeNode*> stk;
        stk.push(root); //1
        
        while(!stk.empty())
        {
            TreeNode * curr_node = stk.top(); //1, 2
            stk.pop(); // empty, 5
         
            // We will take right subtree first because we need left subtree on the top
            if (curr_node->right != nullptr)
                stk.push(curr_node->right); //5, 4
            
            if (curr_node->left != nullptr)
                stk.push(curr_node->left); //2, 3
            
            // Assign the right/left values to create the resultant tree
            if(!stk.empty())
                curr_node->right = stk.top(); //2, 3 and so on
            curr_node->left = nullptr;
        }
        
    }
};
