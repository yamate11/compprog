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

vector<string> b6 = {
  "###...",
  "...###",
  "###...",
  "...###",
  "###...",
  "...###",
};
vector<string> b7 = {
  "##....#",
  "...###.",
  "###....",
  "..###..",
  "....###",
  ".###...",
  "#....##",
};
vector<string> b8 = {
  "###.....",
  "#..##...",
  ".....###",
  ".###....",
  "....###.",
  "###.....",
  "...##..#",
  ".....###",
};
vector<string> b9 = {
  "###......",
  "...###...",
  "......###",
  "###......",
  "...###...",
  "......###",
  "###......",
  "...###...",
  "......###",
};
vector<string> b10 = {
  "##.......#",
  "...###....",
  "......###.",
  "###.......",
  "..###.....",
  ".....###..",
  ".......###",
  ".###......",
  "....###...",
  "#.......##",
};
vector<string> b11 = {
  "#........##",
  "...###.....",
  "......###..",
  "###........",
  ".###.......",
  "....###....",
  ".......###.",
  "........###",
  "..###......",
  ".....###...",
  "##........#",
};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector S(N, string(N, '.'));
  auto fill6 = [&](ll t) -> void {
    REP(i, 6) REP(j, 6) S[t + i][t + j] = b6[i][j];
  };
  auto fill0 = [&](ll t) -> void {
    vector<string> b;
    if (t == 7) b = b7;
    if (t == 8) b = b8;
    if (t == 9) b = b9;
    if (t == 10) b = b10;
    if (t == 11) b = b11;
    REP(i, t) REP(j, t) S[i][j] = b[i][j];
  };
  ll t = N % 6;
  if (t == 0) {
    REP(i, N / 6) fill6(i * 6);
  }else {
    fill0(t + 6);
    for (ll i = t + 6; i < N; i += 6) fill6(i);
  }
  REP(i, N) cout << S[i] << "\n";

  return 0;
}

