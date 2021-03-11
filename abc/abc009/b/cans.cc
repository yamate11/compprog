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
  ll top = -1;
  ll snd = -1;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (top < a) {
      snd = top;
      top = a;
    } else if (snd < a && a < top) {
      snd = a;
    }
  }
  cout << snd << endl;

  return 0;
}

