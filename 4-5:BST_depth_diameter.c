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
void inorder(TREE *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void printlevel(TREE *root,int level){
    if(root==NULL){
        return;
    }
    if(level==0){
        printf("%d ",root->data);
        return;
    }
    printlevel(root->left,level-1);
    printlevel(root->right,level-1);
}
int findDepthTree(TREE* root){
    if(root==NULL){
        return -1;
    }
    int left_height=findDepthTree(root->left);
    int right_height=findDepthTree(root->right);
    if(left_height>=right_height)
        return (left_height+1);
    else
        return (right_height+1);
}
void leveltraversal(TREE *root){
    int i;
    int depth_of_tree=findDepthTree(root);
    for(i=1;i<=depth_of_tree+1;i++){
        printlevel(root,i);
        printf("\n");
    }
}

int findDiameter(TREE* root){
    return(findDepthTree(root->left)+findDepthTree(root->right)+2);
}
int findDepthNode(TREE *root,int data){
    if(root->data==data){
        return 0;
    }
    if(root->data>data)
        return (findDepthNode(root->left,data)+1);
    else
        return (findDepthNode(root->right,data)+1);
}

int main(){
    printf("\n\nsajan\n");
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
    printf("Inorder:");inorder(root);
    printf("\nDepth is : %d\n",findDepthTree(root));
    printf("Diameter: %d\n",findDiameter(root));
    int data=17;
    printf("Depth of %d is %d \n",data,findDepthNode(root,data));
    printf("Height of %d is %d \n",data,findDepthTree(root)-findDepthNode(root,data));
    printf("Level of %d is %d \n",data,findDepthNode(root,data)+1);
}