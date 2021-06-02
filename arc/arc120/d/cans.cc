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
  vector<ll> A(2*N); cin >> A;
  using sta = pair<ll, ll>;
  vector<sta> P;
  for (ll i = 0; i < 2*N; i++) {
    P.emplace_back(A[i], i);
  }
  sort(P.begin(), P.end());
  vector<ll> ord(2*N);
  for (ll i = 0; i < 2*N; i++) {
    auto [a, j] = P[i];
    ord[j] = i;
  }
  string ans = "";
  ll exc = 0;
  bool flag = false;
  for (ll i = 0; i < 2*N; i++) {
    if (exc > 0) {
      ll inc = (flag == (bool)(ord[i] < N));
      if (inc) {
        ans += '(';
        exc++;
      }else {
        ans += ')';
        exc--;
      }
    }else {
      if (ord[i] < N) {
        flag = true;
      }else {
        flag = false;
      }
      ans += '(';
      exc++;
    }
  }
  cout << ans << endl;

  return 0;
}

