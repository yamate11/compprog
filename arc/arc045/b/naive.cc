#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, M; cin >> N >> M;
  vector<int> S(M), T(M);
  vector<int> w(N+1);
  for (int i = 0; i < M; i++) {
    int s, t; cin >> s >> t;
    S.at(i) = s;
    T.at(i) = t;
    for (int j = s; j <= t; j++) w.at(j)++;
  }
  int cnt = 0;
  vector<bool> vecok(M);
  for (int i = 0; i < M; i++) {
    bool ok = true;
    for (int j = S.at(i); j <= T.at(i); j++) {
      if (w.at(j) == 1) {
	ok = false;
	break;
      }
    }
    if (ok) {
      vecok.at(i) = true;
      cnt++;
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < M; i++) {
    if (vecok.at(i)) cout << i+1 << "\n";
  }
  return 0;
}

