#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

template<typename F>
class FixPoint : private F {
public:
  explicit constexpr FixPoint(F&& f) noexcept : F(forward<F>(f)) {}

  template<typename... Args>
  constexpr decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template<typename F>
static inline constexpr decltype(auto) fix(F&& f) noexcept {
  return FixPoint<F>{forward<F>(f)};
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  ll K; cin >> K;
  ll N = s.size();

  vector<ll> vec(N, -1);
  stack<char> pos;

  vector<vector<int>> nxt(26, vector<int>(N));
  for (char c = 'a'; c <= 'z'; c++) {
    int x = N;
    for (int i = N-1; i >= 0; i--) {
      if (s.at(i) == c) x = i;
      nxt.at(c - 'a').at(i) = x;
    }
  }

  auto func = fix([&](auto recF, int n, ll ord, ll& cnt) -> bool {
      if (n >= N) {
	cnt = 0;
	return false;
      }
      ll& ref = vec.at(n);
      if (0 <= ref && ref < ord) {
	cnt = ref;
	return false;
      }
      cnt = 0;
      for (char c = 'a'; c <= 'z'; c++) {
      // for (char c = 'a'; c <= 'b'; c++) {
	int k = nxt.at(c - 'a').at(n);
	// int k = n; 
	// while (k < N && s.at(k) != c) k++;
	if (k == N) continue;
	if (ord == 1) {
	  pos.push(c);
	  return true;
	}
	cnt++;
	ord--;
	ll lcnt;
	if (recF(k+1, ord, lcnt)) {
	  pos.push(c);
	  return true;
	}else {
	  cnt += lcnt;
	  ord -= lcnt;
	}
      }
      ref = cnt;
      return false;
    });

  ll gcnt;
  if (func(0, K, gcnt)) {
    char x[1000010];
    int i = 0;
    while (!pos.empty()) {
      x[i++] = pos.top();
      pos.pop();
    }
    x[i] = 0;
    cout << string(x) << endl;
  }else {
    cout << "Eel\n";
  }

  return 0;
}

