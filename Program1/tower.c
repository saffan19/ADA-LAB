#include<stdio.h>

void tower(int n,char s,char t,char d)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",s,d);
        return;
    }
    tower(n-1,s,d,t);
    printf("Move disk %d from %c to %c\n",n,s,d);
    tower(n-1,t,s,d);
}


void main()
{
    int n;
    printf("Enter the number of disks:\n");
    scanf("%d",&n);
    printf("Moves:\n");
    tower(n,'S','T','D');
}