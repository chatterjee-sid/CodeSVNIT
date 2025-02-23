#include<stdio.h>
void show(char arr[50][15], int arrsize) {
    for (int i = 0;i < arrsize;i++) {
        printf("%s ", *(arr + i));
    }
    printf("\n");
}
void append(char arr[50][15], int arrsize, char str[15]) {
    char* p = *(arr + arrsize);
    int i = 0;
    while (str[i] != '\0') {
        *p = str[i];
        p++;
        i++;
    }
    *p = '\0';
}
int insert(char arr[50][15], int arrsize, char str[15], int index) {
    if (index > arrsize) {
        printf("Index out of bound!\n");
        return -1;
    }
    else {
        int i = arrsize;
        while (i > index) {
            append(arr, i, *(arr + i - 1));
            i--;
        }
        append(arr, index, str);
        printf("Your string has been inserted at desired location.\n");
        return 1;
    }
}

int search(char arr[50][15], int arrsize, char str[15]) {
    for (int i = 0;i < arrsize;i++) {
        int j;
        for (j = 0;str[j] != '\0';j++) {
            if (arr[i][j] != str[j]) {
                break;
            }
        }
        if (str[j] == '\0') {
            return i;
        }
    }
    return -1;
}
int delete(char arr[50][15], int arrsize, char str[15]) {
    int q = search(arr, arrsize, str);
    if (q == -1) {
        printf("No string deleted as the mentioned string does not exist in the array.\n");
    }
    else {
        int i = q;
        while (i < arrsize) {
            append(arr, i, *(arr + i + 1));
            i++;
        }
        **(arr + arrsize) = '\0';
        printf("Your string has been removed from the array.\n");
    }
    return q;
}
void main() {
    char stud[10][15] = { "Rajan","Manav","Mansi","Akshat","Farida","Dharm","Trisha" };
    int strcnt = 7;
    int choice = 5;
    while (choice != 0) {
        printf("Menu\n\t1. Append\n\t2. Insert\n\t3. Search\n\t4. Delete\n\t0. Exit\n");
        printf("No. of elements in array: %d\n", strcnt);
        printf("Enter choice: ");
        scanf("%d", &choice);
        char str[15];
        if (choice == 1) {
            printf("Enter String: ");
            scanf("%s", str);
            append(stud, strcnt, str);
            printf("Your string has been appended.\n");
            strcnt++;
            show(stud, strcnt);
        }
        else if (choice == 2) {
            int index;
            printf("Enter String: ");
            scanf("%s", str);

            printf("Enter index value: ");
            scanf("%d", &index);
            int Q = insert(stud, strcnt, str, index);
            if (Q == 1) {
                strcnt++;
            }
            show(stud, strcnt);
        }
        else if (choice == 3) {
            printf("Enter String: ");
            scanf("%s", str);
            int q = search(stud, strcnt, str);
            if (q == -1) {
                printf("Your string does not exist in the array.\n");
            }
            else {
                printf("Your string exists in the array at\n\tindex %d\n\tlocation % d\n",q,stud+q);
            }
        }
        else if (choice == 4) {
            printf("Enter String: ");
            scanf("%s", str);
            int Q = delete(stud, strcnt, str);
            if (Q != -1) {
                strcnt--;
            }
            show(stud, strcnt);
        }
        else if (choice == 0) {
            break;
        }
        else {
            printf("Invalid option...\n");
        }
    }
}