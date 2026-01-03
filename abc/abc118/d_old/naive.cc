#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

bool ok[15];
int c[]{0,2,5,5,4,5,6,3,7,6};

int dp[15][20000];

int main(){
  int n,m;cin>>n>>m;
  rep(i,m){
    int a;scanf("%d",&a);
    ok[a]=true;
  }
  memset(dp,-1,sizeof(dp));
  dp[1][0]=0;
  for(int i=1;i<10;i++){
    rep(j,12000){
      if(dp[i][j]==-1)continue;
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
      if(ok[i])dp[i][j+c[i]]=max(dp[i][j+c[i]],dp[i][j]+1);
    }
  }
  string ans;
  for(int i=9;i>=1;i--){
    if(!ok[i])continue;
    while(n>=c[i]&&dp[i][n-c[i]]==dp[i][n]-1){
      n-=c[i];
      char c='0'+i;
      ans+=c;
    }
  }
  cout<<ans<<endl;
}
