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

// ----------------------------------------------------------------------
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

  int N; cin >> N;
  vector<vector<int>> nbr(N);
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    for (int j = 0; j < N; j++) {
      if (s.at(j) == '1') nbr.at(i).push_back(j);
    }
  }

  auto func = [&](int i) -> int {
    vector<int> bp(N, -1);
    bp.at(i) = 0;
    int idx = 1;
    vector<int> prev;
    prev.push_back(i);
    while (true) {
      vector<int> recent;
      for (int p : prev) {
	for (int x : nbr.at(p)) {
	  if (bp.at(x) == -1) {
	    bp.at(x) = idx;
	    recent.push_back(x);
	  }else if (bp.at(x) % 2 != idx % 2) {
	    return -1;
	  }
	}
      }
      if (recent.size() == 0) return idx;
      prev = move(recent);
      idx ++;
    }
  };


  int ans = 0;
  for (int i = 0; i < N; i++) {
    int x = func(i);
    if (x < 0) {
      cout << "-1\n";
      return 0;
    }
    ans = max(ans, x);
  }
  cout << ans << endl;
  return 0;
}

