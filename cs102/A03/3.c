// Q3. Create dynamic list of N cities of dynamic name. Display the list before and after deleting nth city name from the list.
#include<stdio.h>
#include<stdlib.h>
void show(char* ptr[], int len) {
    for (int i = 0;i < len;i++) {
        printf("%s ", ptr[i]);
    }
    printf("\n");
}
void append(char* ptr[], int len, char str[]) {
    int i = 0;
    char* p;
    p = malloc(15 * sizeof(char));
    ptr[len] = p;
    do {
        ptr[len][i] = str[i];
        i++;
    } while (str[i - 1] != '\0');
}
int insert(char* ptr[], int len, char str[], int pos) {
    if (pos > len) {
        printf("Index out of bound.\n");
        return 0;
    }
    else {
        for (int i = len;i > pos;i--) {
            ptr[i] = ptr[i - 1];
        }
        append(ptr, pos, str);
        printf("String inserted.\n");
        return 1;
    }
}
int search(char* ptr[], int len, char str[]) {
    int flag = 0;
    int i;
    for (i = 0;i < len;i++) {
        int j = 0;

        while (str[j] != '\0') {
            if (ptr[i][j] != str[j]) {
                break;
            }
            else {
                j++;
            }
        }
        if (str[j] == '\0') {
            flag = 1;
            break;
        }
    }
    if (flag) {
        return i;
    }
    else {
        return -1;
    }
}
int delete(char* ptr[], int len, char str[]) {
    int Q = search(ptr, len, str);
    if (Q == -1) {
        printf("String does not exist.\n");
    }
    else {
        for (int i = Q;i < len - 1;i++) {
            ptr[i] = ptr[i + 1];
        }
    }
    return Q;
}
void main() {
    char* city[10];
    for (int i = 0;i < 10;i++) {
        city[i] = (char*)malloc(15 * sizeof(char));
    }
    city[0] = "Gandhinagar";
    city[1] = "Ahmedabad";
    city[2] = "Surat";
    city[3] = "Vadodara";
    city[4] = "Anand";
    int strcnt = 5;
    while (1) {
        printf("Menu\n");
        printf("\t1. Append\n");
        printf("\t2. Insert\n");
        printf("\t3. Search\n");
        printf("\t4. Delete\n");
        printf("\t0. Exit\n");
        printf("No. of elements in array: %d\n", strcnt);
        printf("Enter choice: ");
        int choice;
        char str[15];
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter String: ");
            scanf("%s", str);
            append(city, strcnt, str);
            printf("String appended.\n");
            strcnt++;
            show(city, strcnt);
        }
        else if (choice == 2) {
            int index;
            printf("Enter String: ");
            scanf("%s", str);
            printf("Enter index value: ");
            scanf("%d", &index);
            if (insert(city, strcnt, str, index)) {
                strcnt++;
            }
            show(city, strcnt);
        }
        else if (choice == 3) {
            printf("Enter String: ");
            scanf("%s", str);
            int Q = search(city, strcnt, str);
            if (Q == -1) {
                printf("Your string does not exist in the array.\n");
            }
            else {
                printf("Your string exists in the array at\n\tindex %d\n\tlocation % d\n",Q,city[Q]);
            }
        }
        else if (choice == 4) {
            printf("Enter String: ");
            scanf("%s", str);
            int Q = delete(city, strcnt, str);
            if (Q != -1) {
                strcnt--;
            }
            show(city, strcnt);
        }
        else if (choice == 0) {
            for (int i = 0;i < strcnt;i++) {
                free(city[strcnt]);
            }
            printf("Thank you.");
            break;
        }
        else {
            printf("Invalid option...\n");
        }
    }
}