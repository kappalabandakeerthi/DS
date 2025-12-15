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
void insert_beg(int val){
    create_node(val);
    if(head==NULL){
        head=new_node;
    }
    else{
        new_node->next=head;
        head=new_node;
    }
}

void insert_end(int val){
    create_node(val);
    if(head==NULL){
        head=new_node;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
void insert_pos(int val,int pos){
    create_node(val);
    temp=head;
    if(pos==0){
        insert_beg(val);
    }
    else{
        for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
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
    int n,a,pos;
    while(1){
        printf("1.insert at beg 2.insert at end 3.insert at position 4.display:");
        scanf("%d",&n);
        switch(n){
    case 1:
        printf("enter element to insert at beginning : ");
        scanf("%d",&a);
        insert_beg(a);
        break;
    case 2:
        printf("enter element to insert at end : ");
        scanf("%d",&a);
        insert_end(a);
        break;
    case 3:
        printf("enter element to insert at position : ");
        scanf("%d",&a);
        printf("enter position : ");
        scanf("%d",&pos);
        insert_pos(a,pos);
        break;
    case 4:
        display();
        break;
        }
    }
    return 0;
}
