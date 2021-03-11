#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int solve() {
  int N; cin >> N;
  vector<int> A(N), B(N), ordA(N), ordB(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) cin >> B.at(i);
  iota(ordA.begin(), ordA.end(), 0);
  sort(ordA.begin(), ordA.end(),
       [&](int p, int q) { return A.at(p) < A.at(q); });
  iota(ordB.begin(), ordB.end(), 0);
  sort(ordB.begin(), ordB.end(),
       [&](int p, int q) { return B.at(p) < B.at(q); });
  for (int i = 0; i < N; i++) {
    if (A.at(ordA.at(i)) > B.at(ordB.at(i))) return 0;
  }
  for (int i = 0; i < N-1; i++) {
    if (A.at(ordA.at(i+1)) <= B.at(ordB.at(i))) return 1;
  }

  vector<int> vA(N), ordVA(N);
  for (int i = 0; i < N; i++) vA.at(i) = A.at(ordB.at(i));
  iota(ordVA.begin(), ordVA.end(), 0);
  sort(ordVA.begin(), ordVA.end(),
       [&](int p, int q) { return vA.at(p) < vA.at(q); });
  int cnt = 0;
  int i = 0;
  while (ordVA.at(i) != 0) {
    i = ordVA.at(i);
    cnt++;
  }
  if (cnt == N-1) return 0;
  return 1;
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string ans = solve() ? "Yes\n" : "No\n";
  cout << ans;
  return 0;
}



