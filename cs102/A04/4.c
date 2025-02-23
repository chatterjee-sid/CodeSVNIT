//4. Write a program to check parenthesis matching using stack.
#include<stdio.h>
#define MAX 30
#define MIN -1
struct stack{
    int top;
    char str[MAX];
};
int length(char str[]){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i-1;
}
void pop(struct stack* K){
    K->top--;
}
void push(struct stack* K, char E){
    K->top++;
    if(K->top >= MAX){
        printf("Overflow\n");
        K->top--;
        return;
    }
    K->str[K->top]=E;
}
char peek(struct stack* K){
    return K->str[K->top];
}
void main(){
    struct stack B;
    B.top=MIN;
    char S[MAX];
    printf("Expression: ");
    scanf("%s",S);
    int i=0,flag=0;
    while(S[i]!='\0'){
        int CN1 = S[i]==')' && peek(&B)=='(';
        int CN2 = S[i]=='}' && peek(&B)=='{';
        int CN3 = S[i]==']' && peek(&B)=='[';
        if(S[i]=='(' || S[i]=='{' || S[i]=='['){
            push(&B,S[i]);
        } else if(S[i]==')' || S[i]=='}' || S[i]==']'){
            if(CN1 || CN2 || CN3){
                pop(&B);
            } else {
                flag=1;
                break;
            }
        }
        i++;
    }
    if(B.top!=MIN || flag){
        printf("Invalid sequence\n");
    } else {
        printf("Valid sequence\n");
    }
}