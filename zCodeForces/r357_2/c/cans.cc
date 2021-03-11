#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  const int INS = 0;
  const int GET = 1;
  const int REM = 2;
  vector<string> lab({"insert", "getMin", "removeMin"});
  using sta = pair<ll, ll>;
  vector<sta> ans;
  for (ll i = 0; i < n; i++) {
    string s; cin >> s;
    if (s == "insert") {
      ll x; cin >> x;
      pque.push(x);
      ans.emplace_back(INS, x);
    }else if (s == "getMin") {
      ll x; cin >> x;
      while (!pque.empty() && pque.top() < x) {
	pque.pop();
	ans.emplace_back(REM, 0);
      }
      if (!pque.empty() && pque.top() == x) {
	ans.emplace_back(GET, x);
      }else {
	pque.emplace(x);
	ans.emplace_back(INS, x);
	ans.emplace_back(GET, x);
      }
    }else if (s == "removeMin") {
      if (pque.empty()) {
	ans.emplace_back(INS, 1);
	ans.emplace_back(REM, 0);
      }else {
	pque.pop();
	ans.emplace_back(REM, 0);
      }
    }else assert(0);
  }
  cout << ans.size() << endl;
  for (auto [x, y] : ans) {
    cout << lab[x];
    if (x != 2) cout << " " << y;
    cout << "\n";
  }

  return 0;
}

