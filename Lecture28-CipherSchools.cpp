#include "bits/stdc++.h"
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int numTrees(int n) {
    if(n <= 1) return 1;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += numTrees(i-1) * numTrees(n-i);
    return ans;
}

void inorder(TreeNode* root, vector<int> &nums){
    if (root == NULL) return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
}

TreeNode* buildTree(vector<int> &nums, int s , int e){
    if (s > e) return NULL;
    int mid = (s+e)/2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = buildTree(nums, s, mid-1);
    root->right = buildTree(nums, mid+1, e);
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> nums;
    inorder(root, nums);
    int n = nums.size()-1;
    return buildTree(nums, 0, n);
}


//Que 1
vector<int> res;
void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    if(root->left)  inorder(root->left);
    res.push_back(root->val);
    if(root->right)  inorder(root->right);
}

bool isValidBST(TreeNode* root) {
    inorder(root);
    for(int i=1;i<res.size();i++){
        if(res[i]<=res[i-1]) return false;
    }
    return true;
}


//Que 2
int find(TreeNode* root){
    if(!root)return 0;
    return max(find(root->left),find(root->right))+1;
}
bool isBalanced(TreeNode* root) {
    if(!root)return true;
    return abs(find(root->left)-find(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
}


int main(){
    cout<<"Seems Nice.!"<<endl;
    return 0;
}