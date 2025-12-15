#include <stdio.h>
#include <stdlib.h>
#define maxsize 4
int f=-1,r=-1;
int queue[maxsize];
void insert(){
    if(r==maxsize-1){
        printf("full\n");
    }
    else if(r==-1 && f==-1){
        int a;
        printf("enter element to insert :");
        scanf("%d",&a);
        r++;
        f++;
        queue[r]=a;
    }
    else{
        int a;
        printf("enter element to insert :");
        scanf("%d",&a);
        queue[++r]=a;
    }
}
void delete(){
    if(r==-1 && f==-1){
        printf("empty\n");
    }
    else if(r==f){
        r=-1;
        f=-1;
    }
    else{
       f++;
    }
}
void display(){
    if(r==-1 && f==-1){
        printf("empty\n");
    }
    else{
        printf("elements are:");
        for(int i=f;i<=r;i++){
            printf("%d",queue[i]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    while(1){
        printf("1.insert 2.delete 3.delete :");
        scanf("%d",&n);
        switch(n){
        case 1:
            insert();
            break;
        case 2:
            delete();
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
