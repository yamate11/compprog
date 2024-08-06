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

  auto f = [&](string S) -> vector<ll> {
    vector<ll> ret(26);
    REP(i, 0, ssize(S)) ret[S[i] - 'A']++;
    return ret;
  };

  string S1, S2, S3; cin >> S1 >> S2 >> S3;
  auto vec1 = f(S1);
  auto vec2 = f(S2);
  auto vec3 = f(S3);
  ll N = ssize(S1);
  ll used1 = 0;
  ll used2 = 0;
  auto g = [&]() -> bool {
    REP(i, 0, 26) {
      if (vec1[i] + vec2[i] < vec3[i]) return false;
      if (vec1[i] < vec3[i]) {
        ll d = vec3[i] - vec1[i];
        used2 += d;
        vec2[i] -= d;
        vec3[i] -= d;
      }
      if (vec2[i] < vec3[i]) {
        ll d = vec3[i] - vec2[i];
        used1 += d;
        vec2[i] -= d;
        vec3[i] -= d;
      }
    }
    return used1 <= N / 2 and used2 <= N / 2;
  };
  if (g()) {
    cout << "YES\n";
  }else {
    cout << "NO\n";
  }


  return 0;
}

