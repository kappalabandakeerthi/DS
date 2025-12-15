#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define maxsize 30
char stack[maxsize];
int top=-1;
void push(char ch){
    if(top==maxsize-1){
        printf("overflow \n");
    }
    else{
        stack[++top]=ch;
    }
}
char pop(){
    if(top==-1){
        printf("underflow\n");
        return '\0';
    }
    else{
        return stack[top--];
    }
}
int precedence(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    char infix[maxsize];
    char postfix[maxsize];
    printf("enter infix expression:");
    scanf("%s",infix);
    int i=0,j=0;
    char ch;
    while((ch=infix[i++])!='\0'){
        if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(top!=-1 && stack[top--]!='('){
                postfix[j++]=pop();
            }
            postfix[j]=stack[top];
        }
        else if(ch=='/' || ch=='*' || ch=='+' || ch== '-'){
            precedence(ch);
            if(top!=-1 && precedence(stack[top])>=precedence(ch)){
                postfix[j++]=pop();
            }
            push(ch);
        }
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
       postfix[j]='\0';
       printf("postfix is:");
        printf("%s",postfix);
        printf("\n");
    return 0;
}
