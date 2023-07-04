#include "bits/stdc++.h"
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

//Que 1
void range(Node* root,const pair<int,int> &rg,vector<int>&result){
    if(root==NULL){
        return;
    }
    if(root->data < rg.first){
        range(root->right,rg,result);
    }
    else if(root->data > rg.second){
        range(root->left,rg,result);
    }
    else{
        result.push_back(root->data);
        range(root->left,rg,result);
        range(root->right,rg,result);
    }
}


//Que 2
Node* solve(int s , int e , vector<int>& nums){
    if(s > e)
        return NULL;

    int mid = (s+e)/2;

    Node* root = new Node(nums[mid]);
    root->left = solve(s , mid-1, nums);
    root->right = solve(mid+1 , e , nums);

    return root;
}

Node* sortedArrayToBST(vector<int>& nums) {
    return solve(0 , nums.size()-1 , nums);
}


int main(){
    cout<<"Seems Nice.!"<<endl;
    return 0;
}