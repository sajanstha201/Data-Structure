#include<stdio.h>
int stack[100],top=-1;
void push(int n){
    stack[++top]=n;
}
int pop(){
    return(stack[top--]);
}
void display(){
    int i;
    for(i=0;i<=top;i++)
        printf("%d ",stack[i]);
    printf("\n");
}
int main(){
    printf("1.push\n2.pop\n3.display\n4.exit\n");
    while(1){
        printf("Enter your choice:");
        int choice,num;
        scanf("%d",&choice);
        switch (choice){
        case 1:
            printf("Enter the element: ");
            scanf("%d",&num);
            push(num);
            break;
        case 2:
            num=pop();
            printf("The deleted element is %d\n",num);
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
    return 0;
}