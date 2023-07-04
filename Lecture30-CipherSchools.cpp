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
void Inorder(TreeNode* root, vector<int>&vec){
    if(root == NULL)
        return;
    Inorder(root->left,vec);
    vec.push_back(root->val);
    Inorder(root->right,vec);
}
int kthSmallest(TreeNode* root, int k) {
    vector<int>vec;
    Inorder(root,vec);
    return vec[k-1];
}


//Que 2
class MedianFinder {
public:
    priority_queue<int> sh, lh;
    MedianFinder() { }

    void addNum(int num)
    {
        lh.push(-num);
        sh.push(-lh.top());
        lh.pop();

        if (sh.size() > lh.size())
            lh.push(-sh.top()), sh.pop();
    }

    double findMedian()
    {
        if (sh.size() == lh.size())
            return (sh.top() - lh.top()) / 2.0;
        return -lh.top();
    }
};

int main(){
    cout<<"Seems Nice.!"<<endl;
    return 0;
}