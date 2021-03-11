#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


bool solve() {
  int N; cin >> N;
  string S; cin >> S;
  if (N % 2 == 1) return false;
  int t = N / 2;
  for (int i = 0; i < t; i++) {
    if (S.at(i) != S.at(t + i)) return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cout << (solve() ? "Yes" : "No") << endl;

  return 0;
}

