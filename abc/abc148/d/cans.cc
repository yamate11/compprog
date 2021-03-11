#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  int exp = 1;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    if (a == exp) exp++;
  }
  if (exp == 1) {
    cout << -1 << endl;
  }else {
    cout << N - exp + 1 << endl;
  }

  return 0;
}

