#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

string solve() {
  ll N, A, B; cin >> N >> A >> B;
  ll x = N % (A + B);
  if (x == 0) return "Bug";
  if (x <= A) return "Ant";
  return "Bug";
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;
  

  return 0;
}

