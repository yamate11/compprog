#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K; cin >> N >> M >> K;
  if (K > 4 * N * M - 2 * N - 2 * M) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  using sta = pair<ll, string>;
  vector<sta> rec;
  ll rem = K;
  auto build = [&]() -> void {
    if (M == 1) {
      rec.emplace_back(min(rem, N-1), "D");
      rem -= N-1;
      if (rem <= 0) return;
      rec.emplace_back(rem, "U");
      return;
    }

    for (ll j = 0; j < N; j++) {
      rec.emplace_back(min(rem, M-1), "R");
      rem -= M-1;
      if (rem <= 0) return;
      if (j < N-1) {
	string s = "DUL";
	ll x = min(rem / 3, M-1);
	if (x > 0) {
	  rec.emplace_back(x, s);
	  rem -= 3 * x;
	  if (rem <= 0) return;
	}
	if (x < M-1) {
	  rec.emplace_back(1, s.substr(0, min(3LL, rem)));
	  rem -= 3;
	  if (rem <= 0) return;
	}
	rec.emplace_back(1, "D");
	rem -= 1;
	if (rem <= 0) return;
      }else {
	rec.emplace_back(min(rem, M-1), "L");
	rem -= M-1;
	if (rem <= 0) return;
      }
    }
    rec.emplace_back(rem, "U");
  };
  build();
  cout << rec.size() << "\n";
  for (auto [t, s] : rec) {
    cout << t << " " << s << "\n";
  }

  return 0;
}

