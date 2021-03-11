# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <numeric>
#include <tuple>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 100000;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
#define ALL(x)   (x).begin(),(x).end()
#define mp       make_pair
#define eb       emplace_back


int n, m, s;
int dp[50][3001];

int main() {
  cin >> n >> m >> s;
  for (int i = 0; i < 50; i++)for (int j = 0; j < 3000; j++)dp[i][j] = 0;

  dp[0][0] = 1;

  for (int i = 1; i <= n * n; ++i) {
    for (int j = 0; j <= s; ++j) {
      if (j - i >= 0) dp[i][j] += dp[i - 1][j - i] + dp[i][j - i];
      if (j - m - 1 >= 0) dp[i][j] += (MOD - dp[i - 1][j - m - 1]);
      dp[i][j] %= MOD;
    }
  }

  cout << dp[n * n][s] << endl;
}
