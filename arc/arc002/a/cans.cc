#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

bool solve() {
  ll Y; cin >> Y;
  if (Y % 400 == 0) return true;
  if (Y % 100 == 0) return false;
  if (Y % 4 == 0) return true;
  return false;
}  

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

