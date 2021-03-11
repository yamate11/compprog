#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K; cin >> K;
  string S; cin >> S;
  if ((ll)S.size() <= K) {
    cout << S << endl;
  }else {
    S.resize(K);
    cout << S << "..." << endl;
  }

  return 0;
}

