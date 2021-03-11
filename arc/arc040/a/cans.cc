#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

string solve() {
  ll N; cin >> N;
  ll R = 0;
  ll B = 0;
  for (ll i = 0; i < N; i++) {
    string S; cin >> S;
    for (ll j = 0; j < N; j++) {
      if (S.at(j) == 'R') R++;
      else if (S.at(j) == 'B') B++;
      else if (S.at(j) == '.') ;
      else assert(0);
    }
  }
  if (R > B) return "TAKAHASHI";
  else if (R == B) return "DRAW";
  else return "AOKI";
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

