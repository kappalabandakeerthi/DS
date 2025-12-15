#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp=NULL;
struct node *new_node=NULL;
struct node *next=NULL;
struct node *prev=NULL;
void create_node(int val){
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=val;
    new_node->next=new_node->prev=NULL;
}
void insert_beg(int val){
    create_node(val);
    if(head==NULL){
        head=new_node;
    }
    else{
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
    }
}
void delete_pos(int pos){
    if(head==NULL){
        printf("empty\n");
    }
    else if(pos==0){
        temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        free(temp);
        temp=NULL;
    }
    else{
        temp=head;
        prev=NULL;
        next=NULL;
        for(int i=0;i<pos && temp!=NULL;i++){
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            printf("element not found\n");
        }
        else{
            next=temp->next;
            prev->next=next;
            if(next!=NULL){
                next->prev=prev;
            }
        free(temp);
        temp=NULL;
    }
}
}
void delete_val(int val){
    if(head==NULL){
        printf("empty\n");
    }
    else{
        temp=head;
        int count=0;
        while(temp!=NULL && temp->data!=val){
            temp=temp->next;
            count++;
        }
        if(temp==NULL){
            printf("element not found\n");
        }
        else{
            delete_pos(count);
        }
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
        printf("\n");
    }
}
void main(){
    int n,val;
    while(1){
        printf("1.insert at beg 2.delete by val 3.display : ");
        scanf("%d",&n);
        switch(n){
    case 1:
        printf("enter value to insert : ");
        scanf("%d",&val);
        insert_beg(val);
        break;
    case 2:
        printf("enter value to delete : ");
        scanf("%d",&val);
        delete_val(val);
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
        }
    }
}
