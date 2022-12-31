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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM(input)

vector<vector<T>> v_group(const vector<T>& vec, auto key) {
  vector<vector<T>> ret;
  ?? prev_key = ?;
  vector<T> cur;
  for (const T& v : vec) {
    ?? k = key(v);
    if (k == prev_key) cur.push_back(v);
    else {
      ret.push_back(move(cur));
      cur = vector<T>();
    }
  }
  ret.push_back(move(cur));
  return ret;
}


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpStructVec(N, A, ((r, dec=1), (c, dec=1), a, (idx, forIdx=True)), ord=((N, True)))
  struct A_t {
    ll r;
    ll c;
    ll a;
    int idx;
    A_t() {}
    A_t(ll H_, ll W_, ll N_) : H(H_), W(W_), N(N_) {}
    A_t(ll H_, ll W_, ll N_, int idx_) : H(H_), W(W_), N(N_), idx(idx_) {}
    bool operator<(const A_t& o) const {
      if (N > o.N) return true;
      return false;
    }
  };
  ostream& operator<<(ostream& os, const A_t& a) {
    
  }


  return 0;
}
