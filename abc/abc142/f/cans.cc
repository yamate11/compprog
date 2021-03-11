#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#if defined(DEBUG)

#include <unistd.h>
#include <sys/fcntl.h>
#define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
#define DCALL(func, ...) func(__VA_ARGS__)

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#else  // defined(DEBUG)

#define DLOG(...)
#define DCALL(func, ...)

#endif // defined(DEBUG)
// ----------------------------------------------------------------------

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

// ----------------------------------------------------------------------
struct MyException : exception {};

int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cout << setprecision(20);

  int N, M; cin >> N >> M;
  vector<vector<int>> nbr(N);
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b; a--; b--;
    nbr.at(a).push_back(b);
  }
  vector<bool> visited(N);
  vector<int> stack;
  unordered_set<int> stset;

  auto dfs = fix([&](auto f, int n) -> void {
    if (stset.find(n) != stset.end()) {
      int ssize = stack.size();
      vector<int> ord(N);
      for (int i = 0; i < ssize; i++) ord.at(stack.at(i)) = i;
      vector<int> diff(N, 1);
      int startIdx = 0;
      int idx = 0;
      while (1) {
	int x = stack.at(idx);
	int stp = 0;
	for (int z : nbr.at(x)) {
	  if (stset.find(z) == stset.end()) continue;
	  int ii = ord.at(z);
	  int d = ii - idx > 0 ? ii - idx : ii - idx + ssize;
	  stp = max(stp, d);
	}
	int nxtIdx = (idx + stp) % ssize;
	if (stp > diff.at(idx)) {
	  diff.at(idx) = stp;
	  startIdx = idx;
	}else if (nxtIdx == startIdx) {
	  break;
	}
	idx = nxtIdx;
      }
      vector<int> ans;
      idx = startIdx;
      while (1) {
	ans.push_back(stack.at(idx));
	idx = (idx + diff.at(idx)) % ssize;
	if (idx == startIdx) break;
      }
      cout << ans.size() << "\n";
      for (int k : ans) {
	cout << k+1 << "\n";
      }
      throw MyException();
    }
    if (visited.at(n)) return;
    visited.at(n) = true;
    int sz = stack.size();
    stack.push_back(n);
    stset.insert(n);
    for (int m : nbr.at(n)) {
      f(m);
    }
    auto it = stset.find(n);
    assert(it != stset.end());
    stset.erase(it);
    stack.resize(sz);
    });

  try {
    for (int i = 0; i < N; i++) {
      if (visited.at(i)) continue;
      dfs(i);
    }
    cout << -1 << endl;
  }catch(const MyException& e) {
  }

  return 0;
}

