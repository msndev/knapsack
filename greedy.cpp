#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
int list[50],count=0;
int check[50];
int max(int a, int b) { return (a > b) ? a : b; }
void printknapSack(int W, int wt[], int val[], int n)
{
int i,j,w,swap1,swap2,swap3,pro;
int wt_val[n];
for(i=0;i<n;i++)
{
wt_val[i]=val[i]/wt[i];
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(wt_val[j]<wt_val[j+1])
{
swap1=wt_val[j];
wt_val[j]=wt_val[j+1];
wt_val[j+1]=swap1;
swap2=wt[j];
wt[j]=wt[j+1];
wt[j+1]=swap2;
swap3=val[j];
val[j]=val[j+1];
val[j+1]=swap3;
}
}
}
w=W;
for(i=0;i<n;i++)
{
pro=pro+val[i];
w=w-wt[i];
if(w<0)
{
break;
}
}
printf("\n%d",pro);
}
int main()
{
int i,j,p,n,V,vol_2[50][3],
volume[50],mineral[50],count_1=0,name[50],num,r0,r1,r2;char result[50],a0[5],a1[5],a2[5];
int P[]={50,50,30};
V=P[0]*P[1]*P[2];
printf("The number of astroids are : 20");
int val[]={2,3,4,5,7,2,3,4,5,7,2,3,4,5,7,2,3,4,5,7};
int
vol_1[][3]={{2,3,4},{2,3,2},{2,2,2},{3,1,1},{1,2,1},{2,3,4},{2,3,2},{2,2,2},{3,1,1},{1,2,1},{2
,3,4},{2,3,2},{2,2,2},{3,1,1},{1,2,1},{2,3,4},{2,3,2},{2,2,2},{3,1,1},{1,2,1}};
for(i = 0;i < 20; i++)
{
if(vol_1[i][0]>P[0] || vol_1[i][1]>P[1] || vol_1[i][2]>P[2])
{
printf("\tDimensions of asteriod exceeds that of payload! \n");
}
else
{
volume[count_1]=vol_1[i][0]*vol_1[i][1]*vol_1[i][2];
name[count_1]=i+1;
mineral[count_1]=val[i];
vol_2[count_1][0]=vol_1[i][0];
vol_2[count_1][1]=vol_1[i][1];
vol_2[count_1][2]=vol_1[i][2];
count_1++;
}
}
printknapSack(V, volume, mineral, count_1);
FILE *fp = fopen("asteroid.txt", "w");
if (fp == NULL)
{
puts("Couldn't open file");
exit(0);
}
else
{
fputs("The included Asteroids are :" , fp);
for(int i=0;i<count;i++)
{
for (j=0;j<count_1;j++)
{
if(list[i]==volume[j])
{
num= name[j];
sprintf(result, "%d", num);
fputs("\nAsteroid ", fp);
fputs(result, fp);fputs(" : ",fp);
r0=vol_2[j][0];
r1=vol_2[j][1];
r2=vol_2[j][2];
sprintf(a0,"%d",r0);fputs(a0,fp);fputs(" ",fp);
sprintf(a1,"%d",r1);fputs(a1,fp);fputs(" ",fp);
sprintf(a2,"%d",r2);fputs(a2,fp);fputs(" ",fp);
}
}
}
puts("\nDone");
fclose(fp);
}
return 0;
}