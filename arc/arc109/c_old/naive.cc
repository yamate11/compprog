#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
  return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 111;
char s[N];
int n, k;
char dp[N][N];
int p2[N];

char S[] = "SRP";
int getId(char t) {
  int p = 0;
  while(S[p] != t) p++;
  return p;
}

char ch(char x, char y) {
  int xx = getId(x);
  int yy = getId(y);
  int w = yy - xx;
  w %= 3;
  if (w < 0) w += 3;
  if (w == 1)
    return y;
  else
    return x;
}

int main()
{
  startTime = clock();
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  scanf("%d%d", &n, &k);
  scanf("%s", s);
  p2[0] = 1 % n;
  for (int i = 0; i < N - 1; i++)
    p2[i + 1] = (p2[i] * 2) % n;
  for (int i = 0; i < n; i++)
    dp[0][i] = s[i];
  for (int j = 0; j < k; j++)
    for (int i = 0; i < n; i++) {
      int t = (i + p2[j]) % n;
      dp[j + 1][i] = ch(dp[j][i], dp[j][t]);
    }
  printf("%c\n", dp[k][0]);

  return 0;
}
