#include<stdio.h>

void main(){
    printf("C standard: ");
    if(__STDC_VERSION__ == 201112L) printf("C11\n");
    else if(__STDC_VERSION__ == 199901L) printf("C99\n");
    else if(__STDC_VERSION__ == 199409L) printf("C89\n");
    else printf("pre-standard");
}