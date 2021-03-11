#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

void foo(int n, string prefix, string cand) {
  if (n == 0) {
    cout << prefix << "\n";
    return;
  }
  for (ll i = 0; i < (ll)cand.size(); i++) {
    ll lastIdx = (ll)cand.size() - 1;
    char lastChar = cand.at(lastIdx);
    if (i == lastIdx) {
      char xx[2];
      xx[0] = lastChar + 1;
      xx[1] = 0;
      foo(n - 1, prefix + lastChar, cand + string(xx));
    }else {
      foo(n - 1, prefix + cand.at(i), cand);
    }
  }
  
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  foo(N-1, "a", "ab");

  return 0;
}

