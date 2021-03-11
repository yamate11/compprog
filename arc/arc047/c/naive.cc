#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <functional>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct BIT
{
  int bit[SIZE];

  void init()
  {
    memset(bit,0,sizeof(bit));
  }
  void add(int k,int x)
  {
    while(k<SIZE)
      {
	bit[k]+=x;
	k+=k&-k;
      }
  }
  int get(int k)
  {
    int ret=0;
    while(k>0)
      {
	ret+=bit[k];
	k-=k&-k;
      }
    return ret;
  }
  int pos(int k)//k 番目
  {
    int l=0,r=SIZE;
    while(r-l>1)
      {
	int m=(l+r)/2;
	if(get(m)<k) l=m;
	else r=m;
      }
    return r;
  }
};
BIT bit;
int main()
{
  int n,k;
  scanf("%d %d",&n,&k);
  ll a=1,b=k;
  //a/b
  bit.init();
  for(int i=1;i<=n;i++) bit.add(i,1);
  for(int i=0;i<n;i++)
    {
      a*=(ll) (n-i);
      int pos=(int) ((a-1)/b);
      int nxt=bit.pos(pos+1);
      bit.add(nxt,-1);
      a-=(ll) pos*(ll) b;
      printf("%d\n",nxt);
    }
  return 0;
}
