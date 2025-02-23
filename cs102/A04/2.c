//2. Write a program to check whether a given string is palindrome or not.
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
int palcompare(char K1[],char K2[]){
    int i=0;
    while(K1[i]!='\0' || K2[i]!='\0'){
        if(K1[i]!=K2[i]){
            return 0;
        }
        i++;
    }
    return 1;
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
    if(palcompare(S.str,R.str)){
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
}