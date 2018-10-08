#include<stdio.h>
//#include<malloc.h>
//#include "toh_kaustubh.c"

void fillSrc();
void displaySrc(int n);
void displaylevel(int level);
void display(int n);
void moveDisk(int n);

struct pole
{
    int stack[3];
    int top;
}p[3];
 
void main()
{
    int i, oldPole, newPole;
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
    
    /*for(i=0; i<n; i++)
    {
        printf("%d\t", p[3].stack[i]);
    }*/
    //printf("\n\n");
    
    fillSrc();
    
    display(n);
    printf("n is %d\n", n);
    moveDisk(n);

    display(n);

}

//fill the source pole according to the number of disks
/*
void fillSrc(int n)
{
    int i,temp = n;
    for(i=0; i<3; i++)
    {
        p[1].stack[p[1].top] = temp--;
        (p[1].top)++;
    }
}
*/
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


//moving disks between poles 
void moveDisk(int n)//int oldPole, int newPole, int n)
{
    int oldPole, newPole;
    int top1 = p[oldPole].top, top2 = p[newPole].top;
    printf("Enter current pole and then new pole: ");
    scanf("%d%d",&oldPole, &newPole);
    if(p[newPole].stack[p[newPole].top] != n-1) {
        printf("old.%d\tnew.%d\n", p[oldPole].stack[top1], p[newPole].stack[top2]);
        printf("top1.%d\ttop2.%d\n", p[oldPole].top, p[newPole].top);
        if(p[oldPole].stack[top1] < p[newPole].stack[top2]) {
        (p[newPole].top)++;
        p[newPole].stack[p[newPole].top] = p[oldPole].stack[p[oldPole].top]; 
        }
        else {
            printf("And Mand ka Tola\n");
        }
    }
    else { 
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
        else {
            printf("0\t");
        }
    }
    printf("\n");         
}    

//printing the stacks by calling displaylevel()
void display(int n)
{
    
    int i;
    for(i=n-1; i>=0; i--)
    {
        displaylevel(i);
    }
    
}    