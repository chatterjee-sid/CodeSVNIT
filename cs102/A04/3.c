//3. Write a program to convert infix – prefix – postfix expression.
//Infix to Postfix
//Rule 1. Operand are simply printed
//Rule 2. Element should not be over another element not from lower priority in opstack
//Rule 3. Rule 2 can be avoided if there is a bracket
//Rule 4. Pop out everything from opstack until open bracket is not encountered, when you
find a close bracket
//Rule 5. Pop out everything, when input ends
#include<stdio.h>
#define MAX 30
#define MIN -1
struct stack{
    int top;
    char exp[MAX];
}op;
void push(char E){
    if(op.top==MAX-1){
        printf("Overflow\n");
        return;
    }
    op.top++;
    op.exp[op.top]=E;
}
char pop(){
    char p = op.exp[op.top];
    op.exp[op.top]='_';
    op.top--;
    return p;
}
void main(){
    op.top=MIN;
    for(int i=0;i<MAX;i++){
        op.exp[i]='_';
    }
    char expr[40];
    printf("Expression: ");
    scanf("%s",expr);
    int i=0;
    do{
        while(1){
            int CN1 = (expr[i]=='+' || expr[i]=='-') && (op.exp[op.top]=='+' || op.exp[op.top]=='-' || op.exp[op.top]=='*' || op.exp[op.top]=='/') && op.top>MIN;
            int CN2 = (expr[i]=='*' || expr[i]=='/') && (op.exp[op.top]=='*' || op.exp[op.top]=='/') && op.top>MIN;
            if(CN1 || CN2){
                printf("%c",pop());
            } else{
                break;
            }
        }
        if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/' || expr[i]=='(' || expr[i]=='{' || expr[i]=='['){
            push(expr[i]);
        } else if(expr[i]==')'){
            do{
                printf("%c",pop());
            }while(op.exp[op.top]!='(');
            pop();
        } else if(expr[i]=='}'){
            do{
                printf("%c",pop());
            }while(op.exp[op.top]!='{');
            pop();
        } else if(expr[i]==']'){
            do{
                printf("%c",pop());
            }while(op.exp[op.top]!='[');
            pop();
        } else{
            printf("%c",expr[i]);
        }
        i++;
    }while(expr[i]!='\0');
    while(op.top>MIN){
        printf("%c",pop());
    }
}