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
    vector<vector<int>> paths;
    vector<int> current_path;

    void backtrack(TreeNode* root){
        if (root->left == NULL && root->right == NULL){
            current_path.push_back(root->val);
            paths.push_back(current_path);
            current_path.pop_back();
            return;
        }
        current_path.push_back(root->val);
        if (root->left){
            backtrack(root->left);
        }
        if (root->right){
            backtrack(root->right);
        }
        current_path.pop_back();
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        backtrack(root);
        vector<string> answer;
        
        if(root == NULL) return answer;
        
        for(int i = 0; i < (int)paths.size(); i++){
            vector<int> ss = paths[i];
            string aux = "";
            for(int j = 0; j < (int)ss.size(); j++){
                if(j != ss.size() - 1){
                    aux += to_string(ss[j]);
                    aux += "->";
                }else{
                    aux += to_string(ss[j]);
                }
            }
            answer.push_back(aux);
        }
        
        return answer;
    }
};