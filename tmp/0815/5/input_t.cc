#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()



int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  /*
    A1 A2 .. AN
   */

  auto A = inpRow<ll>(N, 0);
  /* equiv */
  vector<ll> A(N);
  REP(i, 0, N) cin >> A[i];

  auto A = inpRow<ll>(N, 1);
  /* equiv */
  vector<ll> A(N);
  REP(i, 0, N) { cin >> A[i]; A[i]--; }

  /*
    s1s2..sN
   */

  auto s = inpRow<char>(N, 0);
  /* equiv */
  vector<char> s(N);
  REP(i, 0, N) cin >> s[i];

  auto A = inpRow<char>(N, 'a');
  /* equiv */
  vector<char> A(N);
  REP(i, 0, N) { cin >> A[i]; A[i] -= 'a'; }

  /*
    s11s12...s1W
    ...
    sH1sH2...sHW
  */
  auto A = inpGrid<char, int>(H, W, '0');
  /* equiv */
  vector A(H, vector<int>(W));
  REP(i, 0, H) REP(j, 0, W) { char c; cin >> c; A[i][j] = c - '0'; }

  /*
    L1 R1 C1
    L2 R2 C2
    ...
    LN RN CN
   */
  auto [L, R, C] = inpCol3<ll, ll, ll>(N, 1, 0, 0);
  /* equiv */
  vector<ll> L(N), R(N), C(N);
  REP(i, N) {
    cin >> L[i] >> R[i] >> C[i];
    L[i] -= 1;
  }

  return 0;
}

// -------------


// @DefStruct(LRS, ((l, dec=1), r, (s, string)), ord=(r, l, (s, GT))) [T5x4e0]
struct LRS_t {
  ll l;
  ll r;
  string s;
  friend istream& operator >>(istream& istr, LRS_t& m) {
    istr >> m.l >> m.r >> m.s;
    m.l -= 1;
    return istr;
  }
  friend ostream& operator <<(ostream& ostr, const LRS_t& m) {
    ostr << "[" << m.l << " " << m.r << " " << m.s;
    return ostr;
  }
  bool operator <(const LRS_t o) const {
    if (r != o.r) return r < o.r;
    if (l != o.l) return l < o.l;
    if (s != o.s) return s > o.s;
    return false;
  }
};
// @End [T5x4e0]

// @DefStruct(XY, (x, y))
struct XY_t {
  ll x;
  ll y;
  friend istream& operator >>(istream& istr, LRS_t& m) { /* ... */ }
  friend ostream& operator <<(ostream& ostr, const LRS_t& m) { /* ... */ }
};
// @End

void foo() {
  // @InpVec(N, A, dec=1)
  vector<ll> A(N);
  REP(i, 0, N) { cin >> A[i]; A[i]--; }
  // @End

  // @InpGrid(H, W, A, (char, int), dec='a')
  vector A(H, vector<int>(W));
  REP(i, 0, H) REP(j, 0, W) { cin >> A[i][j]; A[i][j] = c - 'a'; }
  // @End

  // @InpVec(N, LRS, type=LRS_t) [Fxep4C]
  vector<LRS_t> LRS(N);
  REP(i, 0, N) { cin >> LRS[i]; }
  // @End [Fxep4C]

  // @InpMVec(N, ((L, dec=1), R, (C, (char, bool), dec='0')))
  vector<ll> L(N), R(N);
  vector<bool> C(N);
  REP(i, 0, N) {
    cin >> L[i]; L[i] -= 1;
    cin >> R[i];
    char c; cin >> c; C[i] = c - '0';
  }
  // @End
}

  




