#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

ll ask(ll i) {
  cout << "? " << i + 1 << endl;   // 0-index 等はここで調整
  ll x; cin >> x;
  return x;
}

void fin(ll i) {
  cout << "! " << (i >= 0 ? i + 1 : -1) << endl;
  exit(0);
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector left(N, vector<ll>());
  vector right(N, vector<ll>());
  ll seq = 0;
  vector<ll> vecP, vecQ;
  {
    for (ll loglen = 0; true; loglen++) {
      ll len = 1LL << loglen;
      if (len > N) break;
      REP(i, 0, N) {
        if (i + len > N) break;
        left[i].push_back(seq);
        right[i + len - 1].push_back(seq);
        vecP.push_back(i);
        vecQ.push_back(i + len - 1);
        seq++;
      }
    }
  }
  ll M = seq;
  cout << M << endl;
  REP(i, 0, seq) cout << vecP[i] + 1 << " " << vecQ[i] + 1 << endl;
  // phase 2
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll L, R; cin >> L >> R; L--; R--;
    ll loglen = 0;
    while ((1LL << (loglen + 1)) <= R - L + 1) loglen++;
    ll a = left[L][loglen];
    ll b = right[R][loglen];
    cout << a + 1 << " " << b + 1 << endl;
  }
    

  return 0;
}

