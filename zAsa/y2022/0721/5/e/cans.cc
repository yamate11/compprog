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

// @@ !! LIM()

int main() {
  auto solve = [&]() -> ll {
    ll N; cin >> N;
    vector A(N, vector(N - 1, 0LL));
    REP(i, N) REP(j, N - 1) {
      cin >> A[i][j];
      A[i][j]--;
    }
    vector games(N, 0LL);          // 人 i が行った試合数
    vector day(N, 0LL);            // 人 i が最後に行った試合の日付
    vector<ll> cands;              // 試合をできる (かもしれない) 人
    REP(i, N) cands.push_back(i);  //     最初は全員
    while (not cands.empty()) {    // 試合をできる人がいる間
      ll i = cands.back(); cands.pop_back(); // i に取り出して
      if (games[i] >= N - 1) continue;  // 全試合を行っていたらパス
      ll j = A[i][games[i]];       // 対戦相手を j として
      if (i == A[j][games[j]]) {   // j の相手が i なら試合ができる
        if (++games[i] < N - 1) cands.push_back(i); // i の試合を進め
        if (++games[j] < N - 1) cands.push_back(j); // j の試合も進め
        day[i] = day[j] = max(day[i], day[j]) + 1;  // 日付を更新する
      }
    }
    REP(i, N) if (games[i] < N - 1) return -1;  // 全試合できてない人がいたら -1 を，
    return *max_element(ALL(day));  // そうでなければ最大の日付を返す．
  };
  cout << solve() << endl;

  return 0;
}

