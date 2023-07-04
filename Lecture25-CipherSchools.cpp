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


//Que 1
bool isLeaf(TreeNode* root){
    return (root!=NULL && root->left==NULL && root->right==NULL);
}

void maxSumPath(TreeNode* root,int sum,int &maxsum){
    if(root==NULL){
        return;
    }
    sum+=root->val;
    if(isLeaf(root)){
        maxsum = max(maxsum,sum);
        return;
    }
    maxSumPath(root->left,sum,maxsum);
    maxSumPath(root->right,sum,maxsum);
}

void maxSumPath(TreeNode* root){
    int maxsum=0;
    maxSumPath(root,0, maxsum);
    return maxsum;
}



//Que 2
int dfs(TreeNode* root,int &res){
    if(root==NULL){
        return NULL;
    }
    int left = max(dfs(root->left,res),0);
    int right = max(dfs(root->right,res),0);

    res = max(res,left+right+root->val);
    return max(left,right)+root->val;
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    dfs(root,res);
    return res;
}

int main(){
    cout<<"Seems Nice.!"<<endl;
    return 0;
}