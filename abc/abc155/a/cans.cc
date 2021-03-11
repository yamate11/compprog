#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

bool solve() {
  ll A, B, C; cin >> A >> B >> C;
  if (A == B) {
    if (A != C) return true;
    else return false;
  }else {
    if (B == C) return true;
    if (A == C) return true;
    return false;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "Yes" : "No") << endl;


  return 0;
}

