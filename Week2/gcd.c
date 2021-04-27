#include<stdio.h>
int it_gcd(int n1,int n2)
{
    int gcd,i;
    for(i=1;i<=n1&&i<=n2;i++)
    {
        if(n1%i==0&&n2%i==0)
        gcd=i;
    }
    return gcd;
}
int rec_gcd(int n1, int n2) {
    if (n2 != 0)
        return rec_gcd(n2, n1 % n2);
    else
        return n1;
}
void main()
{
    int gcd,n1,n2,choice,c=1;
    while(c==1)
    {
        printf("1)Iterative GCD\n2)Recursive GCD\n3)Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter two numbers:\n");
            scanf("%d%d",&n1,&n2);
            gcd=it_gcd(n1,n2);
            printf("GCD(iterative): %d\n",gcd);
            break;
            case 2:
            printf("Enter two numbers:\n");
            scanf("%d%d",&n1,&n2);
            gcd=rec_gcd(n1,n2);
            printf("GCD(recursive): %d\n",gcd);
            break;
            case 3:
            c=0;break;
            default:printf("Invalid Input\n");
        }
    }
}