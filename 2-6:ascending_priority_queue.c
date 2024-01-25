#include<stdio.h>
#include<stdlib.h>
int queue[100];
int front=0,rear=-1;
void enqueue(int n){
    int i;
        rear++;
    for(i=rear;i>=front;i--){
        if(n<queue[i-1]){
            queue[i]=queue[i-1];
            continue;
        }
        queue[i]=n;
        break;
    }
}
void dequeue(){
    front++;
}
void display(){
    int i;
    printf("\nqueue: ");
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("\n");
}
int main(){
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    while(1){
        int choice;
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter element: ");
            int data;
            scanf("%d",&data);
            enqueue(data);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}