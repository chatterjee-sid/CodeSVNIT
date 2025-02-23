//1. Write a program to reverse a string using Stack.
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
char pop(struct stack* K){
    K->top--;
    return K->str[K->top+1];
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
void main(){
    struct stack S,R;
    S.top=MIN;
    R.top=MIN;
    printf("Enter string: ");
    scanf("%s",S.str);
    S.top=length(S.str);
    while(S.top>=0){
        push(&R,pop(&S));
    }
    push(&R,'\0');
    printf("%s",R.str);
}