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
long long first = LLONG_MAX;
long long second = LLONG_MAX;

void dfs(TreeNode* root){
    if(root == NULL)
    return;

    if(root->val < first){
        second = first;
        first = root->val;
    }
    else if(root->val > first && root->val < second){
        second = root->val;
    }
    dfs(root->left);
    dfs(root->right);
}
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);

        if(second == LLONG_MAX)
        return -1;

        return second;
    }
};