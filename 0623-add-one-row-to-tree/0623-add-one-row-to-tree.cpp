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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode *> q;
        q.push(root);
        int d = 1;
        while(!q.empty())
        {
            vector<TreeNode *> temp;
                while(!q.empty())
                {
                    temp.push_back(q.front());
                    q.pop();
                }
            if(d == depth-1)
            {
                for(int i = 0; i<temp.size(); i++)
                {
                    TreeNode * tempo = temp[i];
                    TreeNode * nt1 = new TreeNode(val);
                    TreeNode * nt2 = new TreeNode(val);
                    nt1->left = tempo->left;
                    nt2->right = tempo->right;
                    tempo->left= nt1;
                    tempo->right = nt2;
                }
                break;
            }
            for(TreeNode * i : temp)
            {
                if(i->left) q.push(i->left);
                if(i->right) q.push(i->right);
            }
            d++;
        }
        return root;
    }
};