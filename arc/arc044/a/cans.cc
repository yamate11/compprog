#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

bool solve() {
  int N; cin >> N;
  if (N == 1) return false;
  if (N == 2) return true;
  if (N == 3) return true;
  if (N == 4) return false;
  if (N == 5) return true;
  if (N % 2 == 0) return false;
  if (N % 3 == 0) return false;
  if (N % 5 == 0) return false;
  return true;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "Prime" : "Not Prime") << endl;
  return 0;
}

