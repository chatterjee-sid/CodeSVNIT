//3. Write a code to implement Tower of Hanoi using stack
#include<stdio.h>
#include<stdlib.h>
#define MIN 0
struct stack{
    int* disc;
    int top;
}source,destination,alternate;
void push(struct stack* K,int max,int arg){
    if(K->top==max){
        printf("Overflow\n");
        return;
    }
    K->disc[K->top]=arg;
    K->top++;
}
int pop(struct stack* K){
    if(K->top==MIN){
        printf("Underflow\n");
        return 0;
    }
    K->top--;
    return K->disc[K->top];
}
void display(){
    printf("S[%d]: ",source.top);
    for(int i=0;i<source.top;i++){
        printf("%d ",source.disc[i]);
    }
    printf("\n");
    printf("A[%d]: ",alternate.top);
    for(int i=0;i<alternate.top;i++){
        printf("%d ",alternate.disc[i]);
    }
    printf("\n");
    printf("D[%d]: ",destination.top);
    for(int i=0;i<destination.top;i++){
        printf("%d ",destination.disc[i]);
    }
    printf("\n\n");
}
void tower(int arg,int max,struct stack* sor,struct stack* alt,struct stack* des){
    if(arg==1){
        push(des,max,pop(sor));
        display();
    }else{
        tower(arg-1,max,sor,des,alt);
        push(des,max,pop(sor));
        display();
        tower(arg-1,max,alt,sor,des);
    }
}
void main(){
    source.top=MIN;
    destination.top=MIN;
    alternate.top=MIN;
    int n;
    printf("Enter number of discs: ");
    scanf("%d",&n);
    const int max = n;
    source.disc=(int*)calloc(max,sizeof(int));
    destination.disc=(int*)calloc(max,sizeof(int));
    alternate.disc=(int*)calloc(max,sizeof(int));
    for(int i=0;i<max;i++){
        push(&source,max,max-i);
    }
    display();
    tower(max,max,&source,&alternate,&destination);
}