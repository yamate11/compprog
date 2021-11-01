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

#define MAXS 3600000

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, A, B; cin >> N >> A >> B;
  vector<ll> D(N);
  ll S = 0;
  REP(i, N) {
    cin >> D[i];
    S += D[i];
  }
  auto check = [&](ll t) -> bool { return t >= 0 && t % 2 == 0; };
  if (not check(A + B + S) or not check(A - B + S)) {
    cout << "No\n";
    return 0;
  }
  vector<bitset<MAXS + 1>> tbs(N + 1);
  tbs[0][0] = true;
  REP(i, N) {
    tbs[i + 1] = tbs[i] | (tbs[i] << D[i]);
  }
  auto vget = [&](ll t2) -> optional<vector<int>> {
    if (t2 < 0 or (t2 % 2) != 0) return nullopt;
    ll t = t2 / 2;
    if (not tbs[N][t]) return nullopt;
    vector<int> vec(N);
    REP2R(i, N-1, 0) {
      if (tbs[i][t]) vec[i] = 0;
      else if (tbs[i][t - D[i]]) {
        vec[i] = 1;
        t -= D[i];
      }else assert(0);
    }
    return vec;
  };
  auto vec1 = vget(A + B + S);
  auto vec2 = vget(A - B + S);
  auto code = [&](ll b1, ll b2) -> char {
    if (b1) return b2 ? 'R' : 'U';
    else return b2 ? 'D' : 'L';
  };
  if (not vec1 or not vec2) {
    cout << "No\n";
  }else {
    cout << "Yes\n";
    REP(i, N) cout << code((*vec1)[i], (*vec2)[i]);
    cout << endl;
  }
  

  return 0;
}

