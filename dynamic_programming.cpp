#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
int list[50],count=0;
int check[50];
int max(int a, int b) { return (a > b) ? a : b; }
void printknapSack(int W, int wt[], int val[], int n)
{
int i, w;
int K[n + 1][W + 1];
for (i = 0; i <= n; i++) {
for (w = 0; w <= W; w++) {
if (i == 0 || w == 0)
K[i][w] = 0;
else if (wt[i - 1] <= w)
K[i][w] = max(val[i - 1] +
K[i - 1][w - wt[i - 1]], K[i - 1][w]);
else
K[i][w] = K[i - 1][w];
}
}
int res = K[n][W];
printf("The maximum Mineral content is : %d\n", res);
w = W;
for (i = n; i > 0 && res > 0; i--) {
if (res == K[i - 1][w])
continue;
else {
//printf("%d ", wt[i - 1]);
list[count]=wt[i - 1];
count++;
res = res - val[i - 1];
w = w - wt[i - 1];
}
}
}
int main()
{
int i,j,p,n,vol_2[50][3],
volume[50],mineral[50],count_1=0,name[50],num,r0,r1,r2,r3;char
result[50],a0[5],a1[5],a2[5],a3[5];
long int V;
int P[]={20,20,20};
V=P[0]*P[1]*P[2];
printf("The number of astroids are : 5\n");
int val[]={2,3,4,5,7};
int vol_1[][3]={{2,3,4},{2,3,2},{2,2,2},{3,1,1},{1,2,1}};
for(i = 0;i < 5; i++)
{
if(vol_1[i][0]>P[0] && vol_1[i][1]>P[1] && vol_1[i][2]>P[2])
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
printf("The included Asteroids are :");
for(int i=0;i<count;i++)
{
for (j=0;j<count_1;j++)
{
if(list[i]==volume[j])
{
num= name[j];
sprintf(result, "%d", num);
fputs("\nAsteroid ", fp);
printf("\nAsteroid %d : ",j+1);
fputs(result, fp);fputs(" : ",fp);
r0=vol_2[j][0];
r1=vol_2[j][1];
r2=vol_2[j][2];
r3=mineral[j];
printf("%d %d %d %d\n",r0,r1,r2,r3);
sprintf(a0,"%d",r0);fputs(a0,fp);fputs(" ",fp);
sprintf(a1,"%d",r1);fputs(a1,fp);fputs(" ",fp);
sprintf(a2,"%d",r2);fputs(a2,fp);fputs(" ",fp);
sprintf(a3,"%d",r3);fputs(a3,fp);fputs("\n",fp);
}
}
}
puts("\nDone");
fclose(fp);
}
return 0;
}