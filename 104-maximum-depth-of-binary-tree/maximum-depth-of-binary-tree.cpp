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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*> t;
        t.push(root);
        int level=0;
        while(!t.empty()){
            int size=t.size();
            level++;
            for(int i=0;i<size;i++){
                TreeNode* parent=t.front();
                t.pop();
                if(parent->left!=nullptr){
                    t.push(parent->left);
                }
                if(parent->right!=nullptr){
                    t.push(parent->right);
                }
            }
        }
        return level;
    }
};