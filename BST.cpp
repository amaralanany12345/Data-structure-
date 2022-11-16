#include<bits/stdc++.h>
using namespace std;
class node {
public:
int data ;
node* left;
node* right;
node(){
data=0;
left=right=NULL;
}
};
class bst{
public:
node* root;
bst(){
root=NULL;
}
node * insertnode(node * r,int value){
if (r==NULL){
    node*newnode=new node;
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    r=newnode;
}
else if (value<r->data){
    r->left=insertnode(r->left,value);
}
else {
    r->right=insertnode(r->right,value);
}
return r;
}
void insertnode(int value){
root=insertnode(root,value);
}
void preorder(node* r){
if (r==NULL){
    return;
}
cout<<r->data<<" ";
preorder(r->left);
preorder(r->right);
}
void inorder(node* r){
if (r==NULL){
    return;
}
inorder(r->left);
inorder(r->right);
cout<<r->data<<" ";
}
void postorder(node* r){
if (r==NULL){
    return;
}
postorder(r->left);
cout<<r->data<<" ";
postorder(r->right);
}
node* searching(node* r,int value){
if(r==NULL){
    return NULL;
}
else if (r->data==value){
   return r;
}

else if (r->data>value){
   return searching(r->left,value);
}
else {
    return searching(r->right,value);
}
}
node*findmin(node* r){
if (r==NULL){
    return NULL;
}
else if (r->left==NULL){
    return r;
}
else {
    return findmin(r->left);
}
}
node*findmax(node* r){
if (r==NULL){
    return NULL;
}
else if (r->right==NULL){
    return r;
}
else {
    return findmax(r->right);
}
}
node * Delete(node*r,int value){
if (r==NULL){
    return NULL;
}
else if (r->data>value){
    r->left= Delete(r->left,value);
}
else if (r->data<value){
    r->right= Delete(r->right,value);
}
else {
    if (r->left==NULL&&r->right==NULL){
        r=NULL;
    }
    else if (r->left!=NULL&&r->right==NULL){
        r->data=r->left->data;
        delete r->left;
        r->left=NULL;
    }
    else if(r->right!=NULL&&r->left==NULL){
        r->data=r->right->data;
        delete r->right;
        r->right=NULL;
    }
    else {
        node* pre=findmax(r->left);
        r->data=pre->data;
        r->left=Delete (r->left,pre->data);

    }
}
return r;
}
};
int main (){
bst tree;
tree.insertnode(15);
tree.insertnode(30);
tree.insertnode(28);
tree.insertnode(42);
tree.insertnode(19);
tree.insertnode(17);
tree.insertnode(22);
tree.postorder(tree.root);
cout<<endl;
int x;
cin>>x;
if(tree.searching(tree.root,x)){
    cout<<"True"<<endl;
}
else {
    cout<<"False"<<endl;
}
node*min=tree.findmin(tree.root);
if (min==0){
    cout<<"NO"<<endl;
}
else {
    cout<<min->data<<endl;
}
node*max=tree.findmax(tree.root);
if (max==0){
    cout<<"NO"<<endl;
}
else {
    cout<<max->data<<endl;
}
node* result=tree.Delete(tree.root,22);
tree.postorder(tree.root);
cout<<endl;
result=tree.Delete(tree.root,42);
tree.postorder(tree.root);
}
