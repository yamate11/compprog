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

// @@ !! LIM(f:perfmeas)

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  double coeff = stold(argv[1]);

  double tm1 = get_time_sec();
  int N; cin >> N;
  vector<int> A(N); REP(i, N) {cin >> A[i]; A[i]--; }
  int Q; cin >> Q;
  using sta = tuple<int, int, int, int>; // block, R, L, q
  vector<sta> LR;
  int B = max(1LL, llround(coeff * N / sqrt(Q)));
  REP(q, Q) {
    int l, r; cin >> l >> r; l--;
    int block = l / B;
    LR.emplace_back(block, r, l, q);
  }
  double tm2 = get_time_sec();
  sort(ALL(LR), [&](const sta& u, const sta& v) -> bool {
    const auto& [u_bl, u_r, _1, _2] = u;
    const auto& [v_bl, v_r, _3, _4] = v;
    if (u_bl != v_bl) return u_bl < v_bl;
    if ((u_bl & 1) == 0) return u_r < v_r;
    return u_r > v_r;
  });
  double tm3 = get_time_sec();
  vector<int> rec(N);
  int cnt = 0;
  int cl = 0, cr = 0;
  int pchk = 0;
  vector<int> ans(Q);
  for (auto [dummy, r, l, q] : LR) {
    while (cr < r) {
      int a = A[cr];
      cnt += rec[a];
      rec[a] ^= 1;
      // rec[a]++;
      // if ((rec[a] & 1) == 0) cnt++;
      cr++;
      pchk++;
    }
    while (l < cl) {
      cl--;
      int a = A[cl];
      cnt += rec[a];
      rec[a] ^= 1;
      // rec[a]++;
      // if ((rec[a] & 1) == 0) cnt++;
      pchk++;
    }
    while (r < cr) {
      cr--;
      int a = A[cr];
      rec[a] ^= 1;
      cnt -= rec[a];
      // rec[a]--;
      // if ((rec[a] & 1) != 0) cnt--;
      pchk++;
    }
    while (cl < l) {
      int a = A[cl];
      rec[a] ^= 1;
      cnt -= rec[a];
      // rec[a]--;
      // if ((rec[a] & 1) != 0) cnt--;
      cl++;
      pchk++;
    }
    ans[q] = cnt;
  }
  double tm4 = get_time_sec();
  REP(q, Q) cout << ans[q] << "\n";
  double tm5 = get_time_sec();

  cerr << tm2 - tm1 << endl;
  cerr << tm3 - tm2 << endl;
  cerr << tm4 - tm3 << endl;
  cerr << tm5 - tm4 << endl;
  cerr << "allt " << tm5 - tm1 << endl;
  cerr << "pchk " << pchk << endl;

  return 0;
}

