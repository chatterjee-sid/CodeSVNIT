//1. Write a program to implement factorial using recursion.
#include<stdio.h>
#define MAX 20
#define MIN -1
struct stack{
    int top;
    int fact[MAX];
}K;
void push(int arg){
    K.top++;
    K.fact[K.top]=arg;
}
int factorial(int arg){
    if(arg==0){
        push(1);
    } else{
        factorial(arg-1);
        push(arg*K.fact[K.top]);
    }
    return K.fact[K.top];
}
void main(){
    K.top=MIN;
    int num;
    printf("Enter number: ");
    scanf("%d",&num);
    printf("Factorial: %d",factorial(num));
}