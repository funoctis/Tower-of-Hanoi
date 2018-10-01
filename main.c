#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *next;
};

struct node *top1, *top2, *top3;

int count1 = 0 , count2 = 0 , count3 = 0;

/*
void push(int num, struct node* top) {
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new -> data = num;

    if(top == NULL) {
        new -> next = NULL;
        top = new;
    }
    else {
        new -> next = top;
        top = new;
    } 
}*/
/*
int pop(struct node* top) {
    struct node *temp;
    int num;

    if(top ==NULL) {
        printf("Can't move, no disk found.\n");
        return 0;
    }
    else {
        temp = top;
        num = temp -> data;
        top = top->next;
        free(temp);
        return num;
    }
}
*/

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

void display1() {
    struct node *temp;
    temp = top1;
    
    if(temp ==NULL) {
        printf("Pole1 Empty\n");
    }
    else {
        while(temp != NULL) {
            printf("[%d]\n", temp ->data);
            temp = temp -> next;
        }
    }
}

void fill1() {
    push1(3);
    push1(2);
    push1(1);
}

void main() {
    int i;
    fill1();
    /*
    for(i=1; i<4; i++) {
        int num, pole;
        printf("Choose data to push: ");
        scanf("%d", &num);
        printf("Choose pole to push at: ");
        scanf("%d", &pole);
        switch(pole) {
            case 1:
                push1(num);
                break;
            case 2:
                push2(num);
                break;
            case 3:
                push3(num);
                break;
            default:
                printf("This shouldn't happen\n");
        }
    } 
    */
    display1();
}    
