#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  int cnt = 0;
  int i = 1;
  for (; i <= N; i++) {
    int p; cin >> p;
    if (p == i) {
      cnt++;
      if (i < N) {
	cin >> p;
	i++;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}

