#include<stdio.h>
#include<string.h>
int main()
{char a[100];
   fgets(a,100,stdin);
   int C=0,c=0,n=0,N=strlen(a),p=0;
if(N<5)
printf("Too weak");
else{
for(int i=0;i<strlen(a);i++)
{
     p=*(a+i);
     if(p<=90 && p>=65)
        C++;
     else if(p>=97 && p<=122)
        c++;
    else if(p>=48 && p<=57)
        n++;
     
}
if(C>0 && c>0 && n>0)
printf("Correct");
else
printf("Too weak");
}

    return 0;
}