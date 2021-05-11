#include<stdio.h>
#include<string.h>
int match(char[],char[]);
void main()
{
    char text[20],pattern[20];
    printf("Enter text:\n");
    //scanf("%s",&text);
    gets(text);
    printf("Enter patter to search:\n");
    gets(pattern);
    //scanf("%s",&pattern);
    
    int pos=match(text,pattern);
    if(pos==-1)
    printf("Pattern not found!\n");
    else
    printf("Pattern found at position %d \n",pos+1);
    
}
int match(char t[],char p[])
{
    int pos,e,d;
    int sizet=strlen(t);
    int sizep=strlen(p);
    if(sizep>sizet)return -1;
    for(int c=0;c<=sizet-sizep;c++)
    {
        pos=c;
        e=c;
        for(d=0;d<sizep;d++)
        {
            if(t[e]==p[d])e++;
            else break;
        }
        if(d==sizep)return pos;
    }
    return -1;
}
