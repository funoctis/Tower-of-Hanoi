#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *next;
};

struct node *top1, *top2, *top3;

int count1 = 0 , count2 = 0 , count3 = 0;

void push1(int n) {
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new -> data = n;
    if(top1 == NULL) {
        new -> next = NULL;
        top1 = new;
    }
    else {
        new -> next = top1;
        top1 = new;
    }
}

void push2(int n) {
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new -> data = n;
    if(top2 == NULL) {
        new -> next = NULL;
        top2 = new;
    }
    else {
        new -> next = top2;
        top2 = new;
    }
}

void push3(int n) {
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new -> data = n;
    if(top3 == NULL) {
        new -> next = NULL;
        top3 = new;
    }
    else {
        new -> next = top3;
        top3 = new;
    }
}

int pop1() {
    struct node *temp;
    int num;

    if(top1 ==NULL) {
        printf("Can't move, no disk found.\n");
        return 0;
    }
    else {
        temp = top1;
        num = temp -> data;
        top1 = top1 ->next;
        free(temp);
        return num;
    }
}

int pop2() {
    struct node *temp;
    int num;

    if(top2 == NULL) {
        printf("Can't move, no disk found.\n");
        return 0;
    }
    else {
        temp = top2;
        num = temp -> data;
        top2 = top2 ->next;
        free(temp);
        return num;
    }
}

int pop3() {
    struct node *temp;
    int num;

    if(top3 == NULL) {
        printf("Can't move, no disk found.\n");
        return 0;
    }
    else {
        temp = top3;
        num = temp -> data;
        top3 = top3 ->next;
        free(temp);
        return num;
    }
}

void display() {
    int i;
    int a1[3], a2[3], a3[3];
    struct node *temp;

    temp = top1;
    for(i=0; i<3; i++) {
        if(temp == NULL) {
            a1[i] = 0;
            continue;
        }
        else {
            a1[i] = temp -> data;
        }
        temp = temp -> next;
    }
    
    temp = top2;
    for(i=0; i<3; i++) {
        if(temp == NULL) {
            a2[i] = 0;
            continue;
        }
        else {
            a2[i] = temp -> data;
        }
        temp = temp -> next;
    }

    temp = top3;
    for(i=0; i<3; i++) {
        if(temp == NULL) {
            a3[i] = 0;
            continue;
        }
        else {
            a3[i] = temp -> data;
        }
        temp = temp -> next;
    }

    printf("[%d]\t[%d]\t[%d]\n", a1[0], a2[0], a3[0]);
    printf("[%d]\t[%d]\t[%d]\n", a1[1], a2[1], a3[1]);
    printf("[%d]\t[%d]\t[%d]\n", a1[2], a2[2], a3[2]);
}

void fill1() {
    push1(3);
    push1(2);
    push1(1);
}

int gameWinCondition() {
    int arr[3], i;
    struct node *temp;
    temp = top3;
    for(i=0; i<3; i++) {
        if(temp == NULL) {
            arr[i] = 0;
            continue;
        }
        else {
            arr[i] = temp -> data;
        }
        temp = temp -> next;
    }
    if(arr[1]==1 && arr[2]==2 && arr[3]==3) {
        return 1;
    }
    else {
        return 0;
    }
}

void main() {
    int i;
    fill1();
    int num, pole;
    
   display();
   while(gameWinCondition()!=1) {
       label1:
            printf("Choose pole to remove from: ");
            scanf("%d", &pole);
            switch(pole) {
                case 1:
                    if(top1==NULL)
                        goto label1;
                    num = pop1();
                    break;
                case 2:
                    if(top2==NULL)
                        goto label1;
                    num = pop2();
                    break;
                case 3:
                    if(top3==NULL)
                        goto label1;
                    num = pop3();
                    break;
                default:
                    printf("Invalid pole name, try again.\n");
                    goto label1;   
            }
        label2:
            printf("Choose pole to add to: ");
            scanf("%d", &pole);
            switch(pole) {
                case 1:
                    if(top1 -> data > num)
                        push1(num);
                    else {
                        printf("Cannot move here.\n");
                        goto label2;
                    }
                    break;
                case 2:
                    if(top2 -> data > num)
                        push2(num);
                    else {
                        printf("Cannot move here.\n");
                        goto label2;
                    }
                    break;
                case 3:
                    if(top3 -> data > num)
                        push3(num);
                    else {
                        printf("Cannot move here.\n");
                        goto label2;
                    }
                    break;
                default:
                    printf("Invalid pole name, try again.\n");
                    goto label2;        
            }
        display();
   }
}    
