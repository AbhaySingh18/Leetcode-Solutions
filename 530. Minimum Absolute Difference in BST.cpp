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
    // Helper function to perform inorder traversal of the binary tree
    void InOrder(TreeNode* root, vector<int>& num){
        // Base case: If the current node is null, return
        if (root == NULL) return ;
        
        // Recursive calls:
        // Visit the left subtree
        InOrder(root->left, num);
        
        // Add the current node's value to the num vector
        num.push_back(root->val);
        
        // Visit the right subtree
        InOrder(root->right, num);
    }
    
    // Main function to calculate the minimum difference between any two nodes in the binary tree
    int getMinimumDifference(TreeNode* root) {
        // Create a vector to store the inorder traversal of the tree
        vector<int> num;
        
        // Perform inorder traversal to populate the num vector
        InOrder(root, num);
        
        // Get the size of the num vector
        int s = num.size();
        
        // Initialize the minimum difference with the difference between the second and first nodes
        int d = abs(num[1] - num[0]);
        
        // Iterate through the num vector starting from the third element
        for(int i = 2; i < s; i++){
            // Calculate the absolute difference between the current element and the previous element
            int dd = abs(num[i] - num[i-1]);
            
            // Update the minimum difference if the current difference is smaller
            if (dd < d) d = dd;
        }
        
        // Return the minimum difference
        return d;
    }  
};

 
