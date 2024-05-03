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

  auto f = [](const auto& v1, const auto& v2) -> ll {
    ll q = 0;
    ll ans = abs(v1[0] - v2[0]);
    REP(p, 0, ssize(v1)) {
      if (q == ssize(v2)) break;
      ans = min(ans, abs(v1[p] - v2[q]));
      while (v2[q] < v1[p]) {
        q++;
        if (q == ssize(v2)) break;
        ans = min(ans, abs(v1[p] - v2[q]));
      }
    }
    return ans;
  };

  ll N; cin >> N;
  // @InpMVec(2*N, (A, (C, type=char))) [I7HqOg6X]
  auto A = vector(2*N, ll());
  auto C = vector(2*N, char());
  for (int i = 0; i < 2*N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    char v2; cin >> v2; C[i] = v2;
  }
  // @End [I7HqOg6X]

  map<char, vector<ll>> mp;
  REP(i, 0, 2*N) mp[C[i]].push_back(A[i]);
  char c1 = ' ', c2 = ' ';
  vector<ll> v1, v2, v3;
  for (auto [c, v] : mp) {
    if (ssize(v) % 2 != 0) {
      if (c1 == ' ') { c1 = c; v1 = v; }
      else {
        assert(c2 == ' ');
        c2 = c;
        v2 = v;
      }
    }else {
      v3 = v;
    }
  }
  if (c1 == ' ') {
    cout << 0 << endl;
    return 0;
  }
  sort(ALL(v1));
  sort(ALL(v2));
  sort(ALL(v3));
  ll a = f(v1, v2);
  if (not v3.empty()) {
    ll b = f(v1, v3);
    ll c = f(v2, v3);
    if (b + c < a) a = b + c;
  }
  cout << a << endl;
  


  return 0;
}

