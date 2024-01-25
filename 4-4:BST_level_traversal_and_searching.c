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
void levelDisplay(int data,TREE *root){
    level++;
if(root->data==data){
    printf("The level is %d.\n",level);
    return;
}
else if(data<root->data){
    levelDisplay(data,root->left);
    level--;
    return;
}
else if(root->data<data){
    levelDisplay(data,root->right);
    level--;
    return;
}
}
TREE* search(int data,TREE *root){
    if(root==NULL){
        return root;
    }
    else if(data<root->data){
        return search(data,root->left);
    }
    else if(root->data<data)
        return search(data,root->right);
    else
        return root;
    
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

    levelDisplay(5,root);
    printf("The memory address is %d\n",search(35,root));
    printf("The level tranversal:\n");
    leveltraversal(root);


}