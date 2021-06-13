#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:>>)

// ---- inserted function f:>> from util.cc
template <typename T1, typename T2>
istream& operator>> (istream& is, pair<T1,T2>& p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T1, typename T2, typename T3>
istream& operator>> (istream& is, tuple<T1,T2,T3>& t) {
  is >> get<0>(t) >> get<1>(t) >> get<2>(t);
  return is;
}

template <typename T1, typename T2, typename T3, typename T4>
istream& operator>> (istream& is, tuple<T1,T2,T3,T4>& t) {
  is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t);
  return is;
}

template <typename T>
istream& operator>> (istream& is, vector<T>& v) {
  for (size_t i = 0; i < v.size(); i++) { is >> v[i]; }
  return is;
}

template <typename T>
vector<T> read_vector_n(istream& is, size_t n) {
  vector<T> ret(n);
  for (size_t i = 0; i < n; i++) {
    is >> ret[i];
  }
  return ret;
}

template <typename T>
vector<T> read_vector(istream& is) {
  size_t n; is >> n;
  return read_vector_n<T>(is, n);
}
// ---- end f:>>

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  auto func = [&](const auto& A) -> vector<ll> {
    vector<ll> ret(N);
    vector<ll> cur;
    for (ll i = 0; i < N; i++) {
      ll idx = lower_bound(cur.begin(), cur.end(), A[i]) - cur.begin();
      if ((ll)cur.size() <= idx) cur.push_back(A[i]);
      else cur[idx] = A[i];
      ret[i] = idx + 1;
    }
    return ret;
  };

  vector<ll> A(N); cin >> A;
  auto x = func(A);
  reverse(A.begin(), A.end());
  auto y = func(A);
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ans = max(ans, x[i] + y[N - 1 - i] - 1);
  }
  cout << ans << endl;

  return 0;
}

