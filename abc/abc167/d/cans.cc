#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

// ad-hoc power function
template<typename T, typename Op>
T ah_power(T a, ll b, const T& unit_t, Op op) {
  T two_pow = a;
  T ret = unit_t;
  while (b > 0) {
    if (b & 1LL) ret = op(ret, two_pow);
    two_pow = op(two_pow, two_pow);
    b >>= 1;
  }
  return ret;
}

vector<ll> comp(const vector<ll>& v1, const vector<ll>& v2) {
  vector<ll> ret(v1.size());
  for (ll i = 0; i < (ll)v1.size(); i++) ret.at(i) = v2.at(v1.at(i));
  return ret;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector vec(N+1, 0LL);
  for (ll i = 1; i <= N; i++) {
    cin >> vec.at(i);
  }
  vector unit(N+1, 0LL);
  iota(unit.begin(), unit.end(), 0);
  auto fin = ah_power(vec, K, unit, comp);
  cout << fin.at(1) << endl;

  return 0;
}

