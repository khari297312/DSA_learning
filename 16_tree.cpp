//tree is a non linear data structure
//tree is a collection of nodes connected by edges
//Node: A node is a structure that may contain a value or condition, or represent a separate data structure
//Root: The top node in a tree
//children: A node directly connected to another node when moving away from the root
//parent: The converse notion of a child
//siblings: A group of nodes with the same parent
//ancestor: A node reachable by repeated proceeding from child to parent
//descendant: A node reachable by repeated proceeding from parent to child
//leaf: A node with no children
#include <iostream>
#include<queue>
#include<stack>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* buildTree(node *root){
    int data;
    cin>>data;
    //-1 to stop
    if(data==-1){return NULL;}
    root=new node(data);
    cout<<"Enter left child of "<<data<<": "<<endl;
    root->left=buildTree(root->left);//recursive call to build left subtree
    cout<<"Enter right child of "<<data<<": "<<endl;
    root->right=buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root,queue<int> &q1){
    queue<node*> q;
    q.push(root);
    q.push(NULL);//to print level wise
    while(!q.empty()){
        node* temp=q.front();
        if(temp!=NULL){cout<<temp->data<<" ";
        q1.push(temp->data);
        }
        q.pop();
        if(temp==NULL){cout<<endl;if(!q.empty()){q.push(NULL);}}//to print level wise
        else {if(temp->left!=NULL){q.push(temp->left);}
        if(temp->right!=NULL){q.push(temp->right);}}
    }
}
void ReverselevelOrderTraversal(node* root,stack<node*> &s){
    queue<node*> q;

    q.push(root);
    q.push(NULL);//to print level wise
    s.push(root);
    s.push(nullptr );
    while(!q.empty()){
        node* temp=q.front();
        // if(temp!=NULL){s.push(temp);
        // }
        q.pop();
        if(temp==NULL){cout<<endl;if(!q.empty()){q.push(NULL);s.push(nullptr);}}//to print level wise
        else {if(temp->left!=NULL){q.push(temp->left);s.push(temp->left);}
        if(temp->right!=NULL){q.push(temp->right);s.push(temp->right);}}
    }
}


void buildLeveltree(node *& root){
    queue<node*> q;
    int data;cin>>data;
    root=new node(data);q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"Enter left child of "<<temp->data<<": "<<endl;
        cin>>data;
        if(data!=-1){temp->left=new node(data);q.push(temp->left);}
        cout<<"Enter right child of "<<temp->data<<": "<<endl;
        cin>>data;
        if(data!=-1){temp->right=new node(data);q.push(temp->right);}
    }
}
void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

void print(stack<node*> s){
    while(!s.empty()){
        if(s.top()==nullptr){cout<<endl;}
        else{cout<<s.top()->data<<" ";}
        s.pop();
    }
}



int leaf(node *root){
    int count=0;
    if(root->left==NULL and root->right==NULL){return 1;}//leaf node
    if(root->left!=NULL){count+= leaf(root->left);}
    if(root->right!=NULL){count+= leaf(root->right);}

    return count;
}
// int main() {
//      node* root=NULL;
//         root=buildTree(root);
//         // queue<int> q;
//         // levelOrderTraversal(root,q);
//         // stack<node*> s;
//         // ReverselevelOrderTraversal(root,s);
//         // print(s);
//         // print(q);
//         cout<<leaf(root);
//     return 0;
// }