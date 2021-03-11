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

void showvec(auto v) {
  for (auto x : v) {
    cerr << x << " ";
  }
  cerr << endl;
}

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

  int N;
  cin >> N;
  int K = 1 << N;
  vector<int> S(K);
  for (int i = 0; i < K; i++) cin >> S.at(i);
  sort(S.begin(), S.end(), greater<int>());
  vector<int> cur({S.at(0)});
  vector<bool> used(K);
  used.at(0) = true;

  for (int i = 0; i < N; i++) {
    DLOG("i = %d", i);
    DCALL(showvec, cur);
    vector<int> nxt;
    int idx = 0;
    for (int x : cur) {
      while (idx < K && (used.at(idx) || x == S.at(idx))) idx++;
      if (idx == K) {
	cout << "No\n";
	return 0;
      }
      used.at(idx) = true;
      nxt.push_back(x);
      nxt.push_back(S.at(idx));
    }
    cur = nxt;
    sort(cur.begin(), cur.end(), greater<int>());
  }
  cout << "Yes\n";
  return 0;
}
