#include<stdio.h>
#define max 100
int queue[max],rear=0,front=-1;
void enqueue(int n){
    if(front>max){
        printf("overflow\n");
        return;
    }
    queue[++front]=n;
}
int dequeue(){
    if(rear>front){
        printf("underflow\n");
        return 0;
    }
    return queue[rear++];
}
void display(){
    int i;
    for(i=rear;i<=front;i++)
        printf("%d ",queue[i]);
    printf("\n");
}
int main(){
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    while(1){
        int choice,x,n;
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element: ");
                scanf("%d",&n);
                enqueue(n);
                break;
            case 2:
                n=dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}