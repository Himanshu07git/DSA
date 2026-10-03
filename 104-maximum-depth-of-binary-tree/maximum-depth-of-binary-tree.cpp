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
        if(root==NULL) return 0;

        // return  1+ max(maxDepth(root->left), maxDepth(root->right)); 
        // this will recursively find depth of left and right side, take max of these two, 1 is for root node;


        queue< TreeNode*> q;
        q.push(root);
        int depth=0;

        while(!q.empty()){
            int n=q.size();
            depth++;

            for(int i=0; i<n; i++){
                TreeNode*node= q.front();
                q.pop();

                if(node->left)
                   q.push(node->left);
                if(node->right)
                   q.push(node->right);
            }
        }
        return depth;
    }
};