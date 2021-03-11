#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, M; cin >> N >> M;
  vector<int> num(N);
  vector<bool> possible(N);
  possible.at(0) = true;
  for (int i = 0; i < N; i++) num.at(i) = 1;
  for (int i = 0; i < M; i++) {
    int x, y; cin >> x >> y; x--; y--;
    if (num.at(x) == 0) assert(false);
    if (possible.at(x)) {
      possible.at(y) = true;
    }
    if (num.at(x) == 1) {
      possible.at(x) = false;
    }
    num.at(x)--;
    num.at(y)++;
  }
  int cnt = 0;
  for (int i = 0; i < N; i++) if (possible.at(i)) cnt++;
  cout << cnt << endl;

  return 0;
}

