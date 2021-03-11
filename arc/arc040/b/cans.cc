#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll solve() {
  ll N, R; cin >> N >> R;
  string S; cin >> S;
  ll term = N;
  for ( ; term - 1 >= 0 && S.at(term - 1) == 'o'; term--);
  if (term == 0) return 0;
  ll t = 0;
  ll i = 0;
  while (true) {
    for ( ; i + R < term && S.at(i) == 'o'; i++) t++;
    t++;
    ll proc = min(term - R - i, R);
    if (proc <= 0) return t;
    i += proc;
    t += proc;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

