#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define pii pair<long long, long long>
using namespace std;
const int maxn = 3e5+5;
vector<pii> a[maxn];
int main()
{
  long long n,x,d,ans=0;
  cin >> n >> x >> d;
  if(d == 0)
    {
      if(x == 0) ans = 1;
      else ans = n+1;
      cout << ans << endl;
      exit(0);
    }
  a[0].push_back({0,0});
  long long cycle = n+1, amount = 0;
  for(int i = 1; i <= n; i++)
    {
      long long y = i * x;
      if(y%d == 0)
	{
	  cycle = i;
	  amount = y / d;
	  break;
	}
    }
  for(long long i = 1; i <= n; i++)
    {
      long long to_add = i/cycle*amount;
      long long l = i * (i-1) / 2, r = i * (n+n-i-1) / 2;
      a[i%cycle].push_back({l+to_add, r+to_add});
    }
  for(int i = 0; i < cycle; i++)
    {
      if(a[i].empty())continue;
      sort(a[i].begin(),a[i].end());
      long long base = a[i][0].first, bound = a[i][0].second;
      for(int j = 1; j < a[i].size(); j++)
	{
	  if(a[i][j].first > bound)
	    {
	      ans += bound - base + 1;
	      base = a[i][j].first;
	    }
	  bound = max(bound, a[i][j].second);
	}
      ans += bound - base + 1;
    }
  cout << ans << endl;
}
