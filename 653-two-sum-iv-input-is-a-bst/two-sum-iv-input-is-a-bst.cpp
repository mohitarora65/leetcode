/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* temp = curr->left;
                while (temp->right != nullptr) {
                    temp = temp->right;
                }
                temp->right = curr;

                TreeNode* temp2 = curr;
                curr = curr->left;
                temp2->left = nullptr;
            }
        }

        int l = 0;
        int r = ans.size() - 1;
        while (l < r) {
            if (ans[l] + ans[r] == k)
                return true;
            else if (ans[l] + ans[r] < k)
                l++;
            else
                r--;
        }
        return false;
    }
};