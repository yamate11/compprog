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

  ll N, M, Q; cin >> N >> M >> Q;
  string S; cin >> S;
  // @InpMVec(M, ((L, dec=1), R)) [KRbjDuNV]
  auto L = vector(M, ll());
  auto R = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
  }
  // @End [KRbjDuNV]

  set<ll> ss;
  vector<ll> A;
  vector<ll> orig;
  REP(i, 0, N) ss.insert(i);
  REP(i, 0, M) {
    auto it = ss.lower_bound(L[i]);
    while (it != ss.end() and *it < R[i]) {
      A.push_back(S[*it] - '0');
      orig.push_back(*it);
      it = ss.erase(it);
    }
  }
  ll K = SIZE(orig);
  for (ll i : ss) {
    A.push_back(S[i] - '0');
    orig.push_back(i);
  }
  vector rev_orig(N, 0LL);
  REP(i, 0, N) rev_orig[orig[i]] = i;
  ll tot1 = 0;
  REP(i, 0, N) if (A[i] == 1) tot1++;
  ll ans = 0;
  REP(i, 0, min(K, tot1)) if (A[i] == 0) ans++;

  REP(_q, 0, Q) {
    ll y; cin >> y; y--;
    ll x = rev_orig[y];
    ll old_th = min(tot1, K);
    A[x] = 1 - A[x];
    if (x < old_th) {
      ans += A[x] == 0 ? 1 : -1;
    }
    tot1 += A[x] == 0 ? -1 : 1;
    ll new_th = min(tot1, K);
    if (old_th < new_th) {
      if (A[old_th] == 0) ans++;
    }else if (new_th < old_th) {
      if (A[new_th] == 0) ans--;
    }
    cout << ans << "\n";
  }

  return 0;
}

