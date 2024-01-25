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
TREE* searchMax(TREE *root){
    if(root->right==NULL)
        return root;
    else
       return searchMax(root->right);
}
TREE* delete(int data,TREE*root){
    if(root==NULL)
        return root;
    else if(root->data==data){
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        else{
            TREE *max=searchMax(root->left);
            root->data=max->data;
            root->left=delete(root->data,root->left);
        }
    }
    else if(data<root->data)
        root->left=delete(data,root->left);
    else if(data>root->data)
        root->right=delete(data,root->right);
    return root;
}
void inorder(TREE *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main(){
    printf("1.insertion\n2.deletion\n3.Display\n4.exit\n");
    while(1){
    printf("Enter a choice: ");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter a number: ");
            int data;
            scanf("%d",&data);
            root=insert(data,root);
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%d",&data);
            root=delete(data,root);
            break;
        case 3:
            printf("\ninorder: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice.\n");
    }
    }

}