#include<stdio.h>

void fillSrc();
void displaylevel(int level);
void display();
void push(int x);
int pop();
int gameWinCondition();

struct pole
{
    int stack[3];
};

struct pole p[3];

int top[3];
 
void main()
{
    int win = 0;
    int x;
    fillSrc();
    display();
    while(win != 1) {
        x = pop();
        printf("Popped %d\n", x);
        push(x);
        printf("Pushed %d", x);
        win = gameWinCondition();
        printf("Evaluated win\n");
    }
    printf("Congratulations, you win!\n");
}

//fill the source pole according to the number of disks
void fillSrc()
{
    p[0].stack[0] = 3;
    p[0].stack[1] = 2;
    p[0].stack[2] = 1;
    top[0] = 2;
}


//push to stack 
void push(int x)
{
	int pl;
    chooseWhereToPush:
    printf("Choose pole to push to: ");
    scanf("%d", pl);
    printf("\n");
    if(p[pl].stack[top[pl]] > x) {
        top[pl]++;
        p[pl].stack[top[pl]] = x;
        printf("Pushed.\n");
    }
    else {
        printf("Cannot push here. Try again.\n");
        goto chooseWhereToPush;
    }
}

int pop() {
    int pl, x;
    chooseWhereToPop:
    printf("Choose pole to pop from: ");
    scanf("%d", &pl);
    printf("\n");
    if(p[pl].stack[top[pl]] == -1) {
        printf("Pole empty, cannot pop. Try again.\n");
        goto chooseWhereToPop;
    }
    
    x = p[pl].stack[top[pl]];
    p[pl].stack[top[pl]] = 0;
    top[pl]--;
    return x;
}

//printing a single level (function is called by display())
void displaylevel(int level)
{
    int i;
    for(i=0; i<3; i++)
    {
        printf("[%d]\t",p[i].stack[level]);
    }
    printf("\n");         
}    

//printing the stacks by calling displaylevel()
void display()
{
    
    int i;
    for(i=2; i>=0; i--)
    {
        displaylevel(i);
    }
}    


int gameWinCondition() {
    if(p[2].stack[0]==3 && p[2].stack[1]==2 && p[2].stack[2]==1) {
        return 1;
    }
    else {
        return 0;
    }
}
