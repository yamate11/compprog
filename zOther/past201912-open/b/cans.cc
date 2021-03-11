#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  int prev = 0;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    if (i == 0) {
      prev = a;
      continue;
    }
    int x = a - prev;
    if (x == 0) {
      cout << "stay\n";
    }else if (x > 0) {
      cout << "up " << x << "\n";
    }else {
      cout << "down " << -x << "\n";
    }
    prev = a;
  }

  return 0;
}

