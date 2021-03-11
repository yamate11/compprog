#include<cstdio>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

long long dp[1100100];

int main()
{
  int N,K;
  scanf("%d%d",&N,&K);
  dp[0]=1;
  dp[1]=0;
  long long sum=1;
  for(int i=2;i<=N-1;i++)
    {
      sum+=dp[i-1];
      if(i-K-1>=0) sum-=dp[i-K-1];
      sum%=mod;
      dp[i]=sum;
    }
  long long ans=0;
  for(int i=N-1;i>=max(0,N-K+1);i--)
    {
      ans+=dp[i];
      ans%=mod;
    }
  ans+=mod;
  ans%=mod;
  printf("%lld\n",ans);
  return 0;
}
