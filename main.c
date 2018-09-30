#include<stdio.h>
#include<malloc.h>
//#include "toh_kaustubh.c"

void fillSrc(int n);
void displaySrc(int n);
void displaylevel(int level);
void display(int n);
void moveDisk(int n);

struct pole
{
    int stack[5];
    int top;
}p[3];
 
void main()
{
    int i, oldPole, newPole;
    printf("\n\n");
    
    p[2].top = -1;
    p[3].top = -1;
    
    int n;
    
    //ask user for number of disks (n)
    enter_disks:
        printf("Enter number of disks: ");
        scanf("%d", &n);
        if(n>5)
        {   printf("Please keep the number of disks less than or 5");
            goto enter_disks;
        }
    
    //initialize pole 2,3 to all zeroes 
    for(i=0; i<n; i++) {
        p[2].stack[i]=0;
        p[3].stack[i]=0;
    }
    
    /*for(i=0; i<n; i++)
    {
        printf("%d\t", p[3].stack[i]);
    }*/
    //printf("\n\n");
    
    fillSrc(n);
    
    //printf("\n\n");
    
    //displaySrc(n);
    
    //printf("\n\n");
    
    /*for(i=0; i<n; i++)
    {
        printf("%d\t", p[3].stack[i]);
    }*/
    
    //printf("\n\n");
    
    display(n);

    moveDisk(n);

    display(n);

}

//fill the source pole according to the number of disks
void fillSrc(int n)
{
    int i,temp = n;
    for(i=0; i<n; i++)
    {
        p[1].stack[p[1].top] = temp--;
        (p[1].top)++;
    }
}

//moving disks between poles 
void moveDisk(int n)//int oldPole, int newPole, int n)
{
    int oldPole, newPole;
    printf("Enter current pole and then new pole: ");
    scanf("%d%d",&oldPole, &newPole);
    if(p[newPole].stack[p[newPole].top] != n-1 && p[oldPole].stack[p[oldPole].top] < p[newPole].stack[p[newPole].top])
    {
        (p[newPole].top)++;
        p[newPole].stack[p[newPole].top] = p[oldPole].stack[p[oldPole].top]; 
    }
    else 
    {
        printf("Cannot move");
    }
}

/*
void displaySrc(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", p[1].stack[i]);
    }
}
*/

//printing a single level (function is called by the main display fn)
void displaylevel(int level)
{
    int i;
    for(i=1; i<=3; i++)
    {
        if(p[i].stack[level] != 0)
        {
            printf("%d\t",p[i].stack[level]);
        }
    }
    printf("\n");         
}    

//printing the stacks 
void display(int n)
{
    int i;
    for(i=n-1; i>=0; i--)
    {
        displaylevel(i);
    }
}    