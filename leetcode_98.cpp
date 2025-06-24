class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
    
private:
    bool isValid(TreeNode* root, long long lowerBound, long long upperBound) {
        if (root == nullptr) {
            return true;
        }
        
        if (root->val <= lowerBound || root->val >= upperBound) {
            return false;
        }
        
        return isValid(root->left, lowerBound, root->val) && 
               isValid(root->right, root->val, upperBound);
    }
};
