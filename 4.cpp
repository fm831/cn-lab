#include<stdio.h>
#include<string.h>
char t[28],temp[28],cs[28],g[]="10001000000100001";
int a,i,j,flag,N;
void xor()
{
for(j = 0;j < N; j++)
cs[j] = (( cs[j] == g[j])?'0':'1');
}
void crc()
{
for(i=0;i<N;i++)
cs[i]=t[i];
do
{
if(cs[0]=='1')
xor();
for(j=0;j<N-1;j++)
cs[j]=cs[j+1];
cs[j]=t[i++];
}
while(i<=a+N-1);
}
void main()
{
printf("\nEnter data : ");
scanf("%s",t);
strcpy(temp,t); /* Keep a copy of Message */
printf("\nGenerator polynomial : %s",g);
a=strlen(t);
N=strlen(g);
for(i=a;i<a+N-1;i++)
t[i]='0';
printf("\nModified data is : %s",t);
crc();
printf("\nChecksum is : %s",cs);
strcat(temp,cs); /* Trx Code word is a combination of original message
and Remainder */
printf("\nFinal codeword is : %s",temp);
printf("\nEnter the received message : ");
scanf("%s",t);
crc();
printf("\n remainder: %s",cs);
flag=0;
for(i=0;i<N-1;i++) /* Scan entire remainder for all zeros*/
{
if (cs[i]=='1')
{
flag=1;
break;
}
}
if(flag==1)
printf("\nError detected\n\n");
else
printf("\nNo error detected\n\n");
getch();
}