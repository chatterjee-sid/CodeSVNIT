//2. Write a program to display first N Fibonacci series using recursion.
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
    printf("%d ",K.fact[K.top]);
}
void fibonacci(int arg){
    if(arg==1){
        push(0);
    } else if(arg==2){
        fibonacci(1);
        push(1);
    } else {
        fibonacci(arg-1);
        push(K.fact[K.top] + K.fact[K.top-1]);
    }
}
void main(){
    K.top=MIN;
    int num;
    printf("Enter number of elements: ");
    scanf("%d",&num);
    fibonacci(num);
}