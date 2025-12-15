#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *new_node=NULL;
struct node *head=NULL;
struct node *temp=NULL;
void create_node(int val){
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=val;
    new_node->next=NULL;
}
void push(int val){
    create_node(val);
    if(head==NULL){
        head=new_node;
    }
    else{
        new_node->next=head;
        head=new_node;
    }
}
void pop(){
    if(head==NULL){
        printf("empty\n");
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
}
void display(){
    if(head==NULL){
        printf("empty\n");
    }
    else{
        temp=head;
    printf("elements are : ");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    }
    printf("\n");
}
int main(){
    int n,a;
    while(1){
        printf("1.push 2.pop 3.display : ");
        scanf("%d",&n);
        switch(n){
    case 1:
        printf("enter element to push : ");
        scanf("%d",&a);
        push(a);
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
}
