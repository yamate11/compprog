#include<bits/stdc++.h>
using namespace std;
const int N=200005;
map<int,int>Map;
struct Ask{
  int x,y;
}A[N];
int cmp(Ask x,Ask y){
  return x.y<y.y;
}
int flag[N],a[N],n;
signed main(){
  scanf("%d",&n);
  for (int i=1;i<=n;i++)scanf("%d",&A[i].x),a[i]=A[i].x;
  for (int i=1;i<=n;i++)scanf("%d",&A[i].y);
  sort(a+1,a+n+1);sort(A+1,A+n+1,cmp);
  for (int i=1;i<=n;i++)
    if (a[i]>A[i].y){
      puts("No");
      return 0;
    }
  for (int i=1;i<n;i++)
    if (a[i+1]<=A[i].y){
      puts("Yes");
      return 0;
    }
  for (int i=1;i<=n;i++)Map[a[i]]=i;
  for (int i=1;i<=n;i++)a[i]=Map[A[i].x];
  int Flag=0,now=1;
  while (!Flag||now!=1){
    flag[now]=1;
    Flag=1;
    now=a[now];
  }
  for (int i=1;i<=n;i++)
    if (!flag[i]){
      puts("Yes");
      return 0;
    }
  puts("No");
}
