class Solution
{
public:
    int sum = 0;

    bool lastWasRight = false;
    
    int harvestLefties(TreeNode* root)
    {
        if (root->left != nullptr)
        {
            if(root->left->left == nullptr && root->left->right == nullptr)
            {
                sum += root->left->val;
            }
            else
            {
                harvestLefties(root->left);
            }
        }

        if(root->right != nullptr)
        {
            harvestLefties(root->right);
        }
        return 0;
    }
    
    
    int sumOfLeftLeaves(TreeNode* root)
    {
        
        if(root == nullptr)
            return 0;
        
        harvestLefties(root);
        return sum;
    }
};
