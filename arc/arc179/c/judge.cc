#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

void ac() {
  cout << "# AC" << endl;
  exit(0);
}

void wa(string msg = "") {
  cout << "# WA: " << msg << endl;
  exit(1);
}

int main() {
  ll N; cin >> N;
  ll R; cin >> R;
  // @InpVec(N, A) [f2nP8iZz]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [f2nP8iZz]

  vector<bool> eff(N);
  vector<ll> X(N);
  REP(i, 0, N) {
    X[i] = A[i];
    eff[i] = true;
  }
  ll numeff = N;

  cout << N << endl;
  while (true) {
    char op; cin >> op;
    if (op == '+') {
      ll i, j; cin >> i >> j; i--; j--;
      if (not eff[i] or not eff[j] or abs(X[i] + X[j]) > R) {
        cout << -1 << endl;
        wa();
      }
      eff[i] = eff[j] = false;
      ll p = ssize(X);
      X.push_back(X[i] + X[j]);
      eff.push_back(true);
      numeff--;
      cout << p + 1 << endl;
    }else if (op == '?') {
      ll i, j; cin >> i >> j; i--; j--;
      if (not eff[i] or not eff[j]) {
        cout << -1 << endl;
        wa();
      }
      if (X[i] < X[j]) cout << 1 << endl;
      else cout << 0 << endl;
    }else if (op == '!') {
      if (numeff == 1) {
        ac();
      }else {
        wa();
      }
    }else {
      cout << -1 << endl;
      wa();
    }
  }
  

}
