#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
} LIST;
LIST *head=NULL;
void insertBegin(){
    int value;
    printf("Enter a number: ");
    scanf("%d",&value);
    LIST *node=(LIST*)malloc(sizeof(LIST));
    node->data=value;
    if(head==NULL){
        node->prev=node;
        node->next=node;
        head=node;
        return;
    }
    node->prev=head->prev;
    node->next=head;
    head->prev->next=node;
    head->prev=node;
    head=node;
}
void insertEnd(){
    if(head==NULL){
        insertBegin();
        return;
    }
    int value;
    printf("Enter a number: ");
    scanf("%d",&value);
    LIST *node=(LIST*)malloc(sizeof(LIST));

    node->data=value;
    LIST *trav=head->prev;
    trav->next=node;
    node->prev=trav;
    node->next=head;
    head->prev=node;
}
void insertSelected(){
    int nodeNumber,value;
    printf("Enter the Node Number: ");
    scanf("%d",&nodeNumber);
    LIST *trav=head;
    if(trav==NULL||nodeNumber==1){
        insertBegin();
    }
    else{
        printf("Enter a number: ");
        scanf("%d",&value);
        LIST *node=(LIST*)malloc(sizeof(LIST));
        node->data=value;
        int i;
        for(i=1;i<nodeNumber-1;i++)
            trav=trav->next;
        node->next=trav->next;
        node->prev=trav;
        trav->next=node;
        node->next->prev=node;
    }
}
void deleteBegin(){
    if(head==NULL)
        printf("Under flow\n");
    else{
        head->prev->next=head->next;
        head->next=head->prev->next;
        head=head->next;
    }
}
void deleteEnd(){
    if(head==NULL)
        printf("Under flow\n");
    else{
        LIST *trav=head->prev;
        trav->prev->next=head;
        head->prev=trav->prev;
        free(trav);
    }
}
void deleteSelected(){
    int nodeNumber;
    printf("Enter the node Number: ");
    scanf("%d",&nodeNumber);
    LIST *trav=head;
    int i;
    for(i=1;i<nodeNumber-1;i++)
        trav=trav->next;
    trav->next=trav->next->next;
    trav->next->prev=trav;
}
void display(LIST *trav){
    if(trav==NULL)
        printf("NO element\n");
    else{
    while(1){
        printf("%d ",trav->data);
        trav=trav->next;
        if(trav==head)
            return;
    }
    printf("\n");
    }
}

int main(){
        printf("1.insert from beginning\n2.insert from end\n3.insert in selected node\n");
        printf("4.delet from beginning \n5.delete from end\n6.delete node after specified location\n");
        printf("7.show\n8.exit\n");
    int choice;
    while(1){
        printf("Enter a choice: ");
    scanf("%d",&choice);
   switch(choice){
case 1:
    insertBegin();
    break;
case 2:
    insertEnd();
    break;
case 3:
    insertSelected();
    break;
case 4:
    deleteBegin();
    break;
case 5:
    deleteEnd();
    break;
case 6:
    deleteSelected();
    break;
case 7:
    display(head);
    break;
case 8:
    return 0;
    }
    }

}