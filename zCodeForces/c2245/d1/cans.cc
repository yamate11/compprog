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

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    vector C(N, vector(N, 0LL));
    REP(i0, 0, M) {
      ll o, i, j; cin >> o >> i >> j; i--; j--;
      C[i][j] = o;
      C[j][i] = o;
    }
    vector<ll> pos, neg;
    REP(i, 0, N) {
      if (C[i][i] == 1) pos.push_back(i);
      else neg.push_back(i);
    }
    vector<ll> cnt(N, 0LL);
    REP(i, 0, N) {
      if (C[i][i] == 1) {
        for (ll j : neg) if (C[i][j] == 1) cnt[i]++;
      }else {
        for (ll j : pos) if (C[i][j] == 1) cnt[i]++;
      }
    }
    ranges::sort(pos, [&](ll i, ll j) -> bool { return cnt[i] < cnt[j]; });
    ranges::sort(neg, [&](ll i, ll j) -> bool { return cnt[i] < cnt[j]; });
    REP(i, 0, ssize(pos)) REP(j, i + 1, ssize(pos)) {
      if (C[pos[i]][pos[j]] == 2) {
        cout << "NO\n";
        return;
      }
    }
    REP(i, 0, ssize(neg)) REP(j, i + 1, ssize(neg)) {
      if (C[neg[i]][neg[j]] == 1) {
        cout << "NO\n";
        return;
      }
    }

    for (ll x : pos) {
      ll st = 1;
      for (ll y : neg) {
        if (st == 1) {
          if (C[x][y] == 1) st = 2;
        }else if (st == 2) {
          if (C[x][y] == 2) {
            cout << "NO\n";
            return;
          }
        }
      }
    }
    for (ll y : neg) {
      ll st = 1;
      for (ll x: pos) {
        if (st == 1) {
          if (C[y][x] == 1) st = 2;
        }else if (st == 2) {
          if (C[y][x] == 2) {
            cout << "NO\n";
            return;
          }
        }
      }
    }
    ranges::reverse(neg);
    ll idxP = 0, idxN = 0;
    vector<ll> ans(N);
    ll seq = 1;
    while (true) {
      if (idxP < ssize(pos) and idxN < ssize(neg)) {
        if (C[pos[idxP]][neg[idxN]] == 1) {
          ans[neg[idxN]] = -seq;
          idxN++;
        }else {
          ans[pos[idxP]] = seq;
          idxP++;
        }
      }else if (idxP == ssize(pos) and idxN < ssize(neg)) {
        ans[neg[idxN]] = -seq;
        idxN++;
      }else if (idxP < ssize(pos) and idxN == ssize(neg)) {
        ans[pos[idxP]] = seq;
        idxP++;
      }else {
        break;
      }
      seq++;
    }
    cout << "YES\n";
    REPOUT(i, 0, N, ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

