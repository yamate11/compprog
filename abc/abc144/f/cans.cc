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

  int N, M; cin >> N >> M;
  vector<vector<int>> nxt(N);
  for (int i = 0; i < M; i++) {
    int s, t; cin >> s >> t; s--; t--;
    nxt.at(s).push_back(t);
  }
  vector<double> orig(N);
  for (int i = N-2; i >= 0; i--) {
    double s = 0;
    for (int j : nxt.at(i)) s += 1.0 + orig.at(j);
    orig.at(i) = s / nxt.at(i).size();
  }
  double answer = orig.at(0);
  for (int k = 0; k < N-1; k++) {
    int br = nxt.at(k).size();
    if (br <= 1) continue;
    vector<double> alter = orig;
    double m = -100.0;
    for (int j : nxt.at(k)) m = max(m, 1.0 + orig.at(j));
    alter.at(k) = (orig.at(k) * br - m) / (br - 1);
    for (int i = k-1; i >= 0; i--) {
      double s = 0;
      for (int j : nxt.at(i)) s += 1.0 + alter.at(j);
      alter.at(i) = s / nxt.at(i).size();
    }
    answer = min(answer, alter.at(0));
  }
  cout << answer << endl;

  return 0;
}

