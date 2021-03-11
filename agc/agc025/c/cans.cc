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
  vector<int> L(N), R(N), oL(N), oR(N);
  // vector<bool> done(N);
  for (int i = 0; i < N; i++) cin >> L.at(i) >> R.at(i);
  iota(oL.begin(), oL.end(), 0);
  iota(oR.begin(), oR.end(), 0);
  sort(oL.begin(), oL.end(), [&](int i, int j) { return L.at(i) > L.at(j); });
  sort(oR.begin(), oR.end(), [&](int i, int j) { return R.at(i) < R.at(j); });
  ll K1 = 0;
  int cur = 0;
  {
    int pos = L.at(oL.at(0));
    if (pos > 0) {
      cur = K1 = pos;
    }
  }
  int idx = 0;
  while (true) {
    int pos = R.at(oR.at(idx));
    if (cur <= pos) break;
    K1 += cur - pos;
    cur = pos;
    idx++;
    pos = L.at(oL.at(idx));
    if (pos <= cur) break;
    K1 += pos - cur;
    cur = pos;
  }
  K1 += abs(cur);
  ll K2 = 0;
  cur = 0;
  {
    int pos = R.at(oR.at(0));
    if (pos < 0) {
      cur = pos;
      K2 = -cur;
    }
  }
  idx = 0;
  while (true) {
    int pos = L.at(oL.at(idx));
    if (pos <= cur) break;
    K2 += pos - cur;
    cur = pos;
    idx++;
    pos = R.at(oR.at(idx));
    if (cur <= pos) break;
    K2 += cur - pos;
    cur = pos;
  }
  K2 += abs(cur);
  ll K = max(K1, K2);
  cout << K << endl;
  return 0;
}

