#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    string s; cin >> s;
    if (i == N-1) s = s.substr(0, s.size() - 1);
    if (s == "TAKAHASHIKUN" || s == "Takahashikun" || s == "takahashikun") {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}

