#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
} TREE;
TREE *root=NULL;
int level;
TREE* insert(int data, TREE* root){
    if(root==NULL){
        TREE *node=(TREE*)malloc(sizeof(TREE));
        node->data=data;
        node->left=NULL;
        node->right=NULL;
        root=node;
    }
    else if(data<root->data)
        root->left=insert(data,root->left);
    else if(data>root->data)
        root->right=insert(data,root->right);
    return root;
}
void inorder(TREE *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(TREE *root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(TREE *root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int main(){
    root=insert(20,root);
    root=insert(10,root);
    root=insert(30,root);
    root=insert(5,root);
    root=insert(15,root);
    root=insert(25,root);
    root=insert(35,root);
    root=insert(23,root);
    root=insert(21,root);
    root=insert(27,root);
    root=insert(17,root);
    root=insert(0,root);
    root=insert(7,root);
printf("\nInorder: ");inorder(root);
printf("\nPreorder:");preorder(root);
printf("\nPost Order");postorder(root);
}