#include <stdio.h>
#include <stdlib.h>
#define maxsize 3
int top=-1;
int stack[maxsize];
void push(){
    if(top==maxsize-1){
        printf("overflow \n");
    }
    else{
        int val;
        printf("enter element to push:");
        scanf("%d",&val);
        stack[++top]=val;
    }
}
void pop(){
    if(top==-1){
        printf("underflow\n");
    }
    else{
        top--;
    }
}
void display(){
    if(top==-1){
        printf("empty\n");
    }
    else{
            printf("elements are:");
        for(int i=0;i<=top;i++){
            printf("%d",stack[i]);
        }
    printf("\n");
    }
}
int main(){
    int n;
    while(1){
        printf("1.push 2.pop 3.display :");
        scanf("%d",&n);
        switch(n){
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    default:
        exit(0);
        }
    }
    return 0;
}
