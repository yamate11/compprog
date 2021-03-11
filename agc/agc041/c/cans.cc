#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

vector<vector<char>> tovv(int k, string s) {
  vector<vector<char>> ret(k, vector<char>(k));
  for (int j = 0; j < k; j++) {
    for (int i = 0; i < k; i++) ret.at(j).at(i) = s.at(1 + j*(k+1) + i);
  }
  return ret;
}

const vector<string> bb = {
  "", "", "",
  R"(
.aa
a..
a..
)", R"(
aacd
bbcd
cdaa
cdbb
)", R"(
aabee
c.bff
cddee
efe..
efe..
)", R"(
aab.ee
c.bf..
cddf..
.eeaab
f..c.b
f..cdd
)", R"(
.ccaabb
c..bbaa
c..aabb
aba....
aba....
bab....
bab....
)"
};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  if (N == 2) {
    cout << "-1\n";
    return 0;
  }

  vector<vector<char>> ans(N, vector<char>(N, '.'));

  auto copy = [&](int j0, int i0, auto brd, int w) -> void {
    for (int j = 0; j < w; j++) {
      for (int i = 0; i < w; i++) {
	ans.at(j0 + j).at(i0 + i) = brd.at(j).at(i);
      }
    }
  };

  if (N == 3) {
    auto brd = tovv(3, bb.at(3));
    copy(0, 0, brd, 3);
  }else {
    int k = 4 + ((N-4) % 4);
    auto brdK = tovv(k, bb.at(k));
    auto brd4 = tovv(4, bb.at(4));
    for (int t = 0; t < (N - k) / 4; t++) copy(4*t, 4*t, brd4, 4);
    copy(N-k, N-k, brdK, k);
  }
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) cout << ans.at(j).at(i);
    cout << "\n";
  }
}

