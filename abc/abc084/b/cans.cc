#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

bool solve() {
  ll A, B; cin >> A >> B;
  string S; cin >> S;
  if ((ll)S.size() != A + B + 1) return false;
  for (ll i = 0; i < A+B+1; i++) {
    if (i == A) {
      if (S.at(i) != '-') return false;
    }else {
      if (! ('0' <= S.at(i) && S.at(i) <= '9')) return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

