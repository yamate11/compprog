#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

bool solve() {
  ll A, V, B, W, T; cin >> A >> V >> B >> W >> T;
  if (V <= W) return false;
  ll dist = abs(A - B);
  if (dist <= T * (V - W)) return true;
  return false;


}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "YES" : "NO") << endl;

  return 0;
}

