#include<stdio.h>
#include<algorithm>
using namespace std;
int c[2100];
int dp[2100][2100];
int rem;
int main(){
  int a,b;scanf("%d%d",&a,&b);
  for(int i=0;i<a;i++)scanf("%d",c+i);
  for(int i=0;i<a;i++)rem+=c[i];
  for(int i=0;i<2100;i++)for(int j=0;j<2100;j++)
			   dp[i][j]=1010101010;
  dp[0][0]=0;
  int sum=0;
  for(int i=0;i<a;i++){
    rem-=c[i];
    for(int j=0;j<=i;j++){
      if(dp[i][j]>b)continue;
      //printf("%d %d: %d\n",i,j,dp[i][j]);
      dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
      dp[i+1][j]=max(dp[i+1][j],b-rem);
      long long req;
      if(i==0)req=1;
      else req=((long long)dp[i][j]*c[i])/sum+1;
      if(dp[i][j]+req<=b&&dp[i][j]+req<=sum+c[i])dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+(int)req);
      dp[i+1][j+1]=max(dp[i+1][j+1],b-rem);
    }
    sum+=c[i];
  }
  int ret=0;
  for(int i=0;i<=a;i++)if(dp[a][i]<=b)ret=i;
  printf("%d\n",ret);
}
