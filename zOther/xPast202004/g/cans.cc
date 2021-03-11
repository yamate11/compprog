#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll Q; cin >> Q;
  using Pair = pair<char, ll>;
  deque<Pair> deq;
  for (ll q = 0; q < Q; q++) {
    ll type; cin >> type;
    if (type == 1) {
      char c; ll x; cin >> c >> x;
      deq.emplace_back(c, x);
    }else {
      ll d; cin >> d;
      ll cnt = 0;
      vector<ll>vec(128);
      while (cnt < d && !deq.empty()) {
	Pair p = deq.front(); deq.pop_front();
	char c; ll m; tie(c, m) = p;
	if (cnt + m > d) {
	  deq.emplace_front(c, cnt + m - d);
	  vec.at(c) += d - cnt;
	  cnt = d;
	  break;
	}else {
	  vec.at(c) += m;
	  cnt += m;
	}
      }
      ll sum = 0;
      for (char c = 'a'; c <= 'z'; c++) sum += vec.at(c) * vec.at(c);
      cout << sum << "\n";
    }
  }

  return 0;
}

