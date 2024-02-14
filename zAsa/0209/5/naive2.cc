#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<vector<int>> dp(35, vector<int> (2000));
  dp[0][0] = 1;
  for (int i = 0; i < 35; ++i)
  {
    for (int j = 0; j < 2000; ++j)
    {
      if (i + a < 35) dp[i + a][j] |= dp[i][j];
      if (i + b < 35) dp[i + b][j] |= dp[i][j];
      if (j + c < 2000) dp[i][j + c] |= dp[i][j];
      if (j + d < 2000) dp[i][j + d] |= dp[i][j];
    }
  }
  int answ = 100 * a, anss = 0;
  for (int i = 1; i < 35; ++i)
  {
    for (int j = 1; j < 2000; ++j)
    {
      if (dp[i][j] == 0) continue;
      if (i * e < j || 100 * i + j > f) continue;
      if (anss * (100 * i + j) < (answ + anss) * j)
      {
        anss = j;
        answ = 100 * i;
      }
    }
  }
  
  cout << answ + anss << " " << anss << endl;

  /*
  using ll = long long;
  ll xx, yy; cin >> xx >> yy;
  ll err = (answ + anss) * yy - anss * xx;
  if (err == 0) cout << "OK\n";
  else cout << "NG\n";
  */

}
