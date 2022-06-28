#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, b) REP2(i, 0, b)
#define EXISTS(i, a, c) ([&]() { REP(i, a) if (c) return true; return false; }())
#define FORALL(i, a, c) (not EXISTS(i, a, not (c)))

int main() {
  ll N, M; cin >> N >> M;
  vector<string> A(N); REP(i, N) cin >> A[i];
  vector<string> B(M); REP(i, M) cin >> B[i];
  cout << (EXISTS(p, N - M + 1,
           EXISTS(q, N - M + 1,
           FORALL(i, M,
           FORALL(j, M, B[i][j] == A[p + i][q + j]))))
           ? "Yes\n" : "No\n");
  return 0;
}

