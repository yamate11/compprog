#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, A, B; cin >> N >> A >> B;
  vector<ll> V;
  for (ll i = 0; i < N; i++) {
    ll v; cin >> v;
    V.push_back(v);
  }
  sort(V.begin(), V.end(), greater<ll>());
  double s = 0;
  for (ll i = 0; i < A; i++) s += V.at(i);
  cout << s / A << endl;
  ll p = -1;
  ll q = 0;
  ll border = V.at(A-1);
  for (ll i = 0; i < N; i++) {
    if (V.at(i) == border) {
      if (p < 0) p = i;
      q = i;
    }
  }
  ll comNum = 0;
  q++;
  if (q == A) {
    comNum = 1;
  }else if (p > 0) {
    // C(q-p, A-p)
    ll n = q-p;
    ll r = A-p;
    comNum = 1;
    for (ll i = 1; i <= r; i++) comNum = comNum * (n-i+1) / i;
  }else {
    comNum = 0;
    ll z = 1;
    for (ll i = 1; i <= min(B, q); i++) {
      z = z * (q-i+1) / i;
      if (A <= i) comNum += z;
    }
  }
  cout << comNum << endl;

  return 0;
}

