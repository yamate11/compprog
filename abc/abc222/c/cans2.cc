#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<string> hand(2*N);
  REP(i, 2*N) cin >> hand[i];
  vector<ll> order(2*N), rev(2*N), win(2*N);
  REP(i, 2*N) { order[i] = i; rev[i] = i; }
  REP(j, M) {
    REP(k, N) {
      auto game = [&](ll x, ll y) -> ll {
        ll p = hand[x][j];
        ll q = hand[y][j];
        if (p == q) return 0;
        if (p == 'G') {
          if (q == 'C') return 1;
          if (q == 'P') return -1;
        }else if (p == 'C') {
          if (q == 'P') return 1;
          if (q == 'G') return -1;
        }else if (p == 'P') {
          if (q == 'G') return 1;
          if (q == 'C') return -1;
        }
        assert(0);
      };
      ll res = game(order[2*k], order[2*k + 1]);
      if (res == 1) win[order[2*k]]++;
      else if (res == -1) win[order[2*k + 1]]++;
    }
    sort(order.begin(), order.end(),
         [&](ll x, ll y) -> bool {
           if (win[x] != win[y]) return win[x] > win[y];
           else return x < y;
         });
  }
  REP(i, 2*N) {
    cout << order[i] + 1 << "\n";
  }
  

  return 0;
}

