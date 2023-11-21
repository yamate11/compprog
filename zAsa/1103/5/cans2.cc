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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };
  
  ll N; cin >> N;
  // @InpVec(N, A) [2jmb3mRP]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [2jmb3mRP]
  // @InpVec(N, B) [x1zmKr1l]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [x1zmKr1l]
  
  ll lim = 1LL << 60;
  map<ll, ll> mp;
  REP(i, 0, N) {
    if (not mp.contains(A[i])) mp[A[i]] = randrange(0, lim);
    if (not mp.contains(B[i])) mp[B[i]] = randrange(0, lim);
  }
  vector<ll> HA(N + 1), HB(N + 1);
  set<ll> SA;
  set<ll> SB;
  REP(i, 0, N) {
    if (not SA.contains(A[i])) {
      HA[i + 1] = HA[i] ^ mp[A[i]];
      SA.insert(A[i]);
    }else {
      HA[i + 1] = HA[i];
    }
    if (not SB.contains(B[i])) {
      HB[i + 1] = HB[i] ^ mp[B[i]];
      SB.insert(B[i]);
    }else {
      HB[i + 1] = HB[i];
    }
  }

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll x, y; cin >> x >> y;
    cout <<  (HA[x] == HB[y] ? "Yes\n" : "No\n");
  }


      

  return 0;
}

