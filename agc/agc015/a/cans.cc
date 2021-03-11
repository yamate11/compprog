#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll solve() {
  ll N, A, B; cin >> N >> A >> B;
  if (A > B) return 0;
  if (A == B) return 1;
  if (N == 1) return 0;
  if (N == 2) return 1;
  return (B*(N-1) + A) - (A*(N-1) + B) + 1;
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cout << solve() << endl;

  return 0;
}

