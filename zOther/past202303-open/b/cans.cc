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

  ll D; cin >> D;
  auto f = [&](const string& s) -> pair<ll, string> {
    ll len = ssize(s);
    ll x = stoll(s.substr(0, len - (D + 1)));
    return {x, s.substr(len - D, D)};
  };

  string A, B; cin >> A >> B;
  auto [a1, a2] = f(A);
  auto [b1, b2] = f(B);
  ll carry = 0;
  vector<ll> vec(D);
  REPrev(i, D - 1, 0) {
    ll x = carry + (a2[i] - '0') + (b2[i] - '0');
    carry = x / 10;
    vec[i] = x % 10;
  }
  ll dig = a1 + b1 + carry;
  cout << dig << ".";
  REP(i, 0, D) cout << vec[i];
  cout << endl;

  return 0;
}

