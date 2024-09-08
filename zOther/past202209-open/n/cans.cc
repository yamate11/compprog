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

  ll H, W, Q; cin >> H >> W >> Q;
  // @InpVec(H, A, type=string) [IuX9zavq]
  auto A = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; A[i] = v; }
  // @End [IuX9zavq]

  bool swapped = false;
  vector<deque<char>> tbl;
  if (H > W) {
    REP(i, 0, W) {
      tbl.push_back(deque<char>());
      REP(j, 0, H) tbl[i].push_back(A[j][i]);
    }
    swap(H, W);
    swapped = true;
  }else {
    REP(i, 0, H) {
      tbl.push_back(deque<char>());
      REP(j, 0, W) tbl[i].push_back(A[i][j]);
    }
  }
  assert(H <= W);
  assert(ssize(tbl) == H);
  string S;
  REP(_q, 0, Q) {
    ll tp, p; cin >> tp >> p; p--;
    char c; cin >> c;
    if ((tp == 1) == (not swapped)) {
      char e = tbl[p].back(); tbl[p].pop_back();
      tbl[p].push_front(c);
      S += e;
    }else {
      S += tbl[H - 1][p];
      REPrev(i, H - 2, 0) tbl[i + 1][p] = tbl[i][p];
      tbl[0][p] = c;
    }
  }
  cout << S << endl;

  return 0;
}

