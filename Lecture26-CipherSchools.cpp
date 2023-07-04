#include <bits/stdc++.h>
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
int get_pos(vector<int> preorder,vector<int> inorder,int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}

Node* build_tree(vector<int> preorder,vector<int> inorder,int start,int end){
    static int index = 0;
    if(start>end){
        return NULL;
    }
    int curr = preorder[index];
    index++;

    Node* node = new Node(curr);
    if(start==end){
        return node;
    }
    int pos = get_pos(preorder,inorder,start,end,curr);
    node->left = build_tree(preorder,inorder,start,pos-1);
    node->right = build_tree(preorder,inorder,pos+1,end);

    return node;
}

void inorder_traversal(Node* root){
    if(root==NULL){
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}



//Que 2
int get_pos(vector<int> postorder,vector<int> inorder,int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}


Node* buildTree(vector<int> postorder,vector<int> inorder,int start,int end){
    static int index=postorder.size()-1;
    if(start>end){
        return NULL;
    }
    int curr = postorder[index];
    index--;

    Node* node = new Node(curr);
    if(start == end){
        return node;
    }

    int pos = get_pos(postorder,inorder,start,end,curr);
    node->right = buildTree(postorder,inorder,pos+1,end);
    node->left = buildTree(postorder,inorder,start,pos-1);

    return node;
}


//Que 3
void paths(Node* root,vector<string> &path,string curr){
    if(root->left==NULL && root->right==NULL) path.push_back(curr+to_string(root->data));
    if(root->left)  paths(root->left,path,curr+to_string(root->data)+"->");
    if(root->right)  paths(root->right,path,curr+to_string(root->data)+"->");
}

vector<string> binaryTreePaths(Node* root) {
    vector<string> res;
    paths(root,res,"");
    return res;
}



// Que 5
bool printAllAncestors(Node* root, Node* node)
{
    if (root == nullptr) {
        return false;
    }
    if (root == node) {
        return true;
    }
    bool left = printAllAncestors(root->left, node);
    bool right = false;
    if (!left) {
        right = printAllAncestors(root->right, node);
    }
    if (left || right) {
        cout << root->data << " ";
    }
    return left || right;
}



//Que 4
Node* getPath(Node* root,Node* p, Node* q){
    if(root==NULL || root == p || root == q){
        return root;
    }

    Node* left = getPath(root->left,p,q);
    Node* right = getPath(root->right,p,q);

    if(left==NULL){
        return right;
    }
    if(right ==NULL){
        return left;
    }
    return root;
}

Node* lowestCommonAncestor(Node* root,Node* p, Node* q) {
    return getPath(root,p,q);
}



//Que 5
Node* connect(Node* root) {
    if(!root) return nullptr;
    queue<Node*> q;
    q.push(root);
    while(q.size()) {
        Node* rightNode = nullptr;
        for(int i = q.size(); i; i--) {
            auto cur = q.front(); q.pop();
            cur -> next = rightNode;
            rightNode = cur;
            if(cur -> right)
                q.push(cur -> right),
                        q.push(cur -> left);
        }
    }
    return root;
}


//Extra Bonus points
string serialize(Node* root) {
    if (root == 0) return "null";
    string ans = to_string(root->data);
    ans += string(" ") + serialize(root->left);
    ans += string(" ") + serialize(root->right);
    return ans;
}

Node* deserialize(stringstream &CIN) {
    string node; CIN >> node;
    if (node == "null") return 0;
    Node* root = new Node(stoi(node));
    root->left = deserialize(CIN);
    root->right = deserialize(CIN);
    return root;
}

Node* deserialize(string data) {
    stringstream CIN(data);
    return deserialize(CIN);
}


int main() {
    vector<int> preorder = {1,2,4,3,5};
    vector<int> inorder = {4,2,1,5,3};
    Node* root = build_tree(preorder,inorder,0,inorder.size()-1);
    inorder_traversal(root);

    vector<int> postorder = {4,5,2,6,7,3,1};
    vector<int> inorder = {4,2,5,1,6,3,7};

    Node* root = buildTree(postorder,inorder,0,inorder.size()-1);
    inorder_traversal(root);

    return 0;
}
