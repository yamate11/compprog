#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>


using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
const string FILENAME = "input";
const int MAXN = 200228;


int n, m;
int a[MAXN];



bool check(int x) {
  if (x == 0) {
    return 0;
  }
  for (int i = 2 * n - 1; i >= 2 * n - x; i--) {
    int len = 2 * n - 1 - i;
    if (a[2 * n - 2 * x + len] + a[i] < m) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  //read(FILENAME);
  cin >> n >> m;
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a, a + 2 * n);
  int l = 0;
  int r = n;
  while (l != r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  int x = l;
  int ans = 0;
  for (int i = 0; i < 2 * n - 2 * x; i++) {
    chkmax(ans, a[i] + a[2 * n - 2 * x - 1 - i]);
  }
  for (int i = 2 * n - 1; i >= 2 * n - x; i--) {
    int len = 2 * n - 1 - i;
    chkmax(ans, a[2 * n - 2 * x + len] + a[i] - m);
  }
  cout << ans << '\n';
  return 0;
}
