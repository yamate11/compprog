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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

// @DefStruct(req, ((a, bool), (b, bool), (len, ll))) [Z8er9aBP]
struct req_t {
  bool a;
  bool b;
  ll len;
  req_t(bool a_ = bool(), bool b_ = bool(), ll len_ = ll()) : a(a_), b(b_), len(len_) {}
  friend ostream& operator<<(ostream& ostr, const req_t& t) {
    ostr << "(" << t.a << ", " << t.b << ", " << t.len << ")";
    return ostr;
  }
};
// @End [Z8er9aBP]

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    string AA, BB; cin >> AA >> BB;
    vector<bool> A(N), B(N);
    REP(i, 0, N) { A[i] = AA[i] == '1'; B[i] = BB[i] == '1'; }
    if (A[0] != B[0] or A.back() != B.back()) return -1;

    ll ans = 0;
    req_t req;
    REP(i, 1, N) {
      auto prev = req;
      if (prev.len == 0) {
        if (A[i] == B[i]) {
          req = req_t{};
        }else {
          req = req_t(A[i], B[i - 1], 1);
        }
      }else {
        req.a = A[i];
        ll k = prev.len;
        if (prev.b == A[i]) { req.b = not prev.a; k--; }
        else                { req.b =     prev.a;      }
        if ((k % 2 == 0) != (A[i] == B[i])) k++;
        req.len = k;
      }
      ans += req.len;
    }
    if (req.len > 0) return -1;
    return ans;
  };
  
  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

