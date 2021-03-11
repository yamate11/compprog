#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  set<ll> seen;
  ll numO = 0, numE = 0;
  vector<ll> repl(n);
  for (ll i = 0; i < n; i++) {
    ll& num = A[i] % 2 == 0 ? numE : numO;
    if (num >= n / 2) {
      repl[i] = -1;
    }else {
      if (seen.find(A[i]) == seen.end()) {
	seen.insert(A[i]);
	num++;
	repl[i] = A[i];
      }else {
	repl[i] = -1;
      }
    }
  }
  ll numChg = n - (numE + numO);
  ll pE = 2, pO = 1;
  for (ll i = 0; i < n; i++) {
    if (repl[i] >= 0) continue;
    if (numE < n / 2) {
      while (pE <= m && seen.find(pE) != seen.end()) pE += 2;
      if (pE > m) {
	cout << -1 << endl;
	return 0;
      }
      repl[i] = pE;
      pE += 2;
      numE++;
    }else if (numO < n / 2) {
      while (pO <= m && seen.find(pO) != seen.end()) pO += 2;
      if (pO > m) {
	cout << -1 << endl;
	return 0;
      }
      repl[i] = pO;
      pO += 2;
      numO++;
    }else assert(0);
  }
  cout << numChg << endl;
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << repl[i];
  }
  cout << endl;

  return 0;
}

