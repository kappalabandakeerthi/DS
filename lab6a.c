#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *new_node=NULL;
struct node *head=NULL;
struct node *head1=NULL;
struct node *temp=NULL;
struct node *next=NULL;
struct node *prev=NULL;
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
void insert_list2(int val){
    create_node(val);
    if(head1==NULL){
        head1=new_node;
    }
    else{
        temp=head1;
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
void delete_beg(){
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
void delete_end(){
    if(head==NULL){
        printf("empty\n");
    }
    else{
        temp=head;
        prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
        temp=NULL;
    }
}
void delete_pos(int pos){
    if(head==NULL){
        printf("empty\n");
    }
    else if(pos==0){
        delete_beg();
    }
    else{
        temp=head;
        prev=NULL;
        for(int i=0;i<=pos;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
        temp=NULL;
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
void sort(){
    if(head==NULL){
        printf("empty\n");
    }
    else{
        int val;
        int swapped;
        do{
            swapped=0;
            temp=head->next;
            prev=head;
            while(temp!=NULL){
                if(temp->data < prev->data){
                    val=temp->data;
                    temp->data=prev->data;
                    prev->data=val;
                    swapped=1;
                }
                prev=temp;
                temp=temp->next;
            }
        }while(swapped);
    }
}
void reverse(){
    if(head==NULL){
        printf("empty\n");
    }
    else{
        prev=NULL;
        temp=head;
        while(temp!=NULL){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        head=prev;
    }
}
void concatinate(){
    if(head==NULL){
        head=head1;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head1;
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
        printf("1.insert at beg 2.insert at end 3.insert at position 4.delete beginning 5.delete end 6.delete by value 7.sort 8.reverse 9.concatinate 10.display 11.insert list 2 : ");
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
        delete_beg();
        break;
    case 5:
        delete_end();
        break;
    case 6:
        int val;
        printf("enter value to delete : ");
        scanf("%d",&val);
        delete_val(val);
        break;
    case 7:
        sort();
        break;
    case 8:
        reverse();
        break;
    case 9:
        concatinate();
        break;
    case 10:
        display();
        break;
    case 11:
        printf("enter element to insert at end in list2 : ");
        scanf("%d",&a);
        insert_list2(a);
        break;
        }
    }
    return 0;
}
