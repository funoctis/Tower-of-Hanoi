#include <stdio.h>
#include<math.h>  
void towers(int, char, char, char);    
void main() 
{
    int num,a,b;  
    printf("\nEnter the number of disks : "); 
    scanf("%d", &num);
    a = pow(2,num);
    b = a-1;
    printf("The total number of moves used for moving the disks in the alternate pole is %d\n",b);
    printf("\nThe sequence of moves involved in the Tower of Hanoi are :\n"); 
    towers(num, 'A', 'C', 'B');
}
 
void towers(int num, char from, char to, char aux)
 
{
  if (num == 1)
    {
        printf("\n Move disk 1 from pole %c to pole %c\n", from, to);
        return;
    } 
    towers(num - 1, from, aux, to);
    printf("\n Move disk %d from pole %c to pole %c\n", num, from, to); 
    towers(num - 1, aux, to, from); 
}
/*
OUTPUT:

student@cyber-1:~/Documents$ gcc -o toh toh.c -lm
student@cyber-1:~/Documents$ ./toh

Enter the number of disks : 3
The total number of moves used for moving the disks in the alternate pole is 7

The sequence of moves involved in the Tower of Hanoi are :

 Move disk 1 from pole A to pole C

 Move disk 2 from pole A to pole B

 Move disk 1 from pole C to pole B

 Move disk 3 from pole A to pole C

 Move disk 1 from pole B to pole A

 Move disk 2 from pole B to pole C

 Move disk 1 from pole A to pole C

*/
