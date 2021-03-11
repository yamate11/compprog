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
  string S; cin >> S;
  vector<string> com;
  vector<string> cs({"A", "B", "X", "Y"});
  for (string p : cs) {
    for (string q : cs) {
      com.push_back(p + q);
    }
  }
  ll ans = LLONG_MAX;
  for (string x : com) {
    for (string y : com) {
      ll hit = 0;
      for (ll i = 0; i < N; ) {
	auto match = [&](string v) -> bool {
	  return i+1 < N && S.at(i) == v.at(0) && S.at(i+1) == v.at(1);
	};
	hit++;
	if (match(x) || match(y)) i += 2;
	else                      i += 1;
      }
      ans = min(ans, hit);
    }
  }
  cout << ans << endl;
  return 0;
}

