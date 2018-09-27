#include<stdio.h>
#include<malloc.h>
#include "toh_kaustubh.c"

void fillSrc(int n);
void displaySrc(int n);
void displaylevel(int level);
void display(int n);

struct pole
{
    int stack[5];
    int top;
}p[3];
 
void main()
{
    p[2].top = -1;
    p[3].top = -1;
    
    int n;
    
    enter_disks:
        printf("Enter number of disks: ");
        scanf("%d", &n);
        if(n>5)
        {   printf("Please keep the number of disks less than or 5");
            goto enter_disks;
        }
    
    fillSrc(n);
    displaySrc(n);
    printf("\n\n");
    display(n);



}

void fillSrc(int n)
{
    int i,temp = n;
    for(i=0; i<n; i++)
    {
        p[1].stack[p[1].top] = temp--;
        (p[1].top)++;
    }
}

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
}


void displaySrc(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", p[1].stack[i]);
    }
}


void displaylevel(int level)
{
    int i;
    for(i=1; i<=3; i++)
    {
        //if(p[i].stack[level] != 0)
        //{
            printf("%d\t",p[i].stack[level]);
        //}
    }
    printf("\n");         
}    

void display(int n)
{
    int i;
    for(i=n-1; i>=0; i--)
    {
        displaylevel(i);
    }
}    