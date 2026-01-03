#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<string> S(N, string(N, '.'));
  {
    ll j = 0;
    REP(i, 0, N) {
      REP(k, 0, 3) {
        S[i][j] = '#';
        j = (j + 1) % N;
      }
    }
  }
  if (N % 3 == 1) {
    ll i1 = N / 3;
    ll i2 = i1 + (N / 3 - 1);
    swap(S[i1][N - 1], S[i2][N - 1]);
    swap(S[i1][N - 3], S[i2][N - 3]);
    i1 = N - 1 - i1;
    i2 = N - 1 - i2;
    swap(S[i1][0], S[i2][0]);
    swap(S[i1][2], S[i2][2]);
  }
  if (N % 3 == 2) {
    ll i1 = N / 3;
    ll i2 = 2 * i1;
    swap(S[i1][0    ], S[i2][0    ]);
    swap(S[i1][N - 4], S[i2][N - 4]);
    i1 = N - 1 - i1;
    i2 = N - 1 - i2;
    swap(S[i1][N - 1], S[i2][N - 1]);
    swap(S[i1][3    ], S[i2][3    ]);
  }
  

  REPOUT(i, 0, N, S[i], "\n");

  return 0;
}

