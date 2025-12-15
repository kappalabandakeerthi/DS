#include <stdio.h>
#include <stdlib.h>
#define maxsize 3
int queue[maxsize];
int f=-1,r=-1;
void insert(){
    if((r+1)%maxsize==f){
        printf("full\n");
    }
    else if(r==-1 && f==-1){
        int a;
        printf("enter element to insert:");
        scanf("%d",&a);
        r++;
        f++;
        queue[r]=a;
    }
    else{
        int a;
        printf("enter element to insert:");
        scanf("%d",&a);
        r=(r+1)%maxsize;
        queue[r]=a;
    }
}
void delete(){
    if(r==-1 && f==-1){
        printf("empty\n");
    }
    else if(f==r){
        f=r=-1;
    }
    else{
        f=(f+1)%maxsize;
    }
}
void display(){
    if(r==-1 && f==-1){
        printf("empty\n");
    }
    else if(r==f){
        printf("element is %d\n",queue[r]);
    }
    else{
        printf("elements are : ");
        int i=f;
        while(1){
            printf("%d",queue[i]);
            if(i==r) break;
            i=(i+1)%maxsize;
        }
        printf("\n");
    }
}
int main(){
    int n;
    while(1){
        printf("1.insert 2.delete 3.display : ");
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
