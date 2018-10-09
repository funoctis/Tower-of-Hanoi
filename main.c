#include<stdio.h>

void fillSrc();
void displaylevel(int level);
void display();
void push(int, int);
int pop(int);
int gameWinCondition();

struct pole
{
    int stack[3];
    int top;
}p[3];
 
void main()
{
    int i, old, new, x;
    printf("\n\n");
    p[1].top = -1;
    p[2].top = -1;
    p[3].top = -1;
    
    int n = 3;  //number of disks
    
    
    //initialize pole 2,3 to all zeroes 
    for(i=0; i<3; i++) {
        p[2].stack[i]=0;
        p[3].stack[i]=0;
    }
    
    fillSrc();
    
    display(n);
    
    while(gameWinCondition() != 1)
    printf("Choose your move:\n");
    printf("Enter pole to pop from: ");
    scanf("%d", &old);
    x = pop(old);
    printf("\nEnter pole to push to: ");
    push(new, x);
    printf("\n");
    display(n);

    

}

//fill the source pole according to the number of disks
void fillSrc()
{
    p[1].top = 0;
    int i,temp = 3;
    for(i=0; i<3; i++)   
    {
        p[1].stack[p[1].top] = temp--;
        (p[1].top)++;
    }
}


//push to stack 
void push(int pole, int x)
{
	int top1 = p[pole].top, num;
    
	p[pole].stack[top1]++;
	printf("Enter integer element to push\n");
	scanf("%d",&num);
	s.stk[s.top]=num;
	printf("Element pushed.\n");
	
}

//printing a single level (function is called by display())
void displaylevel(int level)
{
    int i;
    for(i=1; i<=3; i++)
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
    if(p[3].stack[0])
}