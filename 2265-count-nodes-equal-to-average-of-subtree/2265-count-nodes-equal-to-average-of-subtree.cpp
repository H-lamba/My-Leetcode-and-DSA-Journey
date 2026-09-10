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
    vector<int> fun(TreeNode * root, int & ans)
    {
        if(root == nullptr)
        return {0,0};
        vector<int> left = fun(root->left, ans);
        vector<int> right = fun(root->right, ans);
        int leftsum = left[0];
        int leftcount = left[1];
        int rightsum = right[0];
        int rightcount = right[1];
        int currsum = root->val+leftsum+rightsum;
        int currcount = leftcount+rightcount+1;
        if(currsum/currcount==root->val) ans++;
        return {currsum, currcount};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        vector<int> net = fun(root, ans);
        return ans;
    }
};