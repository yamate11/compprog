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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

using rec_t = vector<vector<int>>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;

  auto rot = [&](const auto& v, int r) -> rec_t {
    rec_t ret = v;
    int i0 = r / 2;
    int j0 = r % 2;
    REP(i, 0, (H - 1) / 2) REP(j, 0, W - 1) swap(ret[i0 + i][j0 + j], ret[i0 + H - 2 - i][j0 + j]);
    REP(j, 0, (W - 1) / 2) REP(i, 0, H - 1) swap(ret[i0 + i][j0 + j], ret[i0 + i][j0 + W - 2 - j]);
    return ret;
  };

  vector start(H, vector(W, 0));
  REP(i, 0, H) REP(j, 0, W) {
    cin >> start[i][j]; start[i][j]--;
  }
  vector goal(H, vector(W, 0));
  REP(i, 0, H) REP(j, 0, W) goal[i][j] = i * W + j;
  if (start == goal) {
    cout << 0 << endl;
    return 0;
  }

  set<rec_t> seen;
  seen.insert(start);
  vector<rec_t> cands{start};
  set<rec_t> front;
  REP(cnt, 1, 11) {
    auto prev = move(cands);
    cands = vector<rec_t>();
    for (const auto& v : prev) {
      REP(r, 0, 4) {
        auto v0 = rot(v, r);
        if (v0 == goal) {
          cout << cnt << endl;
          return 0;
        }
        if (not seen.contains(v0)) {
          if (cnt == 10) {
            front.insert(v0);
          }else {
            seen.insert(v0);
            cands.push_back(move(v0));
          }
        }
      }
    }
  }
  seen.clear();
  cands.push_back(goal);
  REP(cnt, 1, 11) {
    auto prev = move(cands);
    cands = vector<rec_t>();
    for (const auto& v : prev) {
      REP(r, 0, 4) {
        auto v0 = rot(v, r);
        if (front.contains(v0)) {
          cout << 10 + cnt << endl;
          return 0;
        }
        if (cnt < 10 and not seen.contains(v0)) {
          seen.insert(v0);
          cands.push_back(move(v0));
        }
      }
    }
  }
  cout << -1 << endl;

  return 0;
}

