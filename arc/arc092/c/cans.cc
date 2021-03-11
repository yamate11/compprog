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
typedef pair<int, int> Pair;

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
  vector<int> A(N), B(N), C(N), D(N);
  for (int i = 0; i < N; i++) cin >> C.at(i) >> D.at(i);
  for (int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);
  vector<int> ordAB(N);
  iota(ordAB.begin(), ordAB.end(), 0);
  sort(ordAB.begin(), ordAB.end(),
       [&](int i, int j) { return B.at(i) < B.at(j); });
  int answer = 0;
  vector<bool> used(N);
  for (int i = 0; i < N; i++) {
    int j = ordAB.at(i);
    int x = -1;
    int k0 = -1;
    for (int k = 0; k < N; k++) {
      if (used.at(k)) continue;
      if (C.at(k) >= A.at(j)) continue;
      if (D.at(k) >= B.at(j)) continue;
      if (C.at(k) <= x) continue;
      x = C.at(k);
      k0 = k;
    }
    if (k0 < 0) continue;
    used.at(k0) = true;
    answer++;
  }
  cout << answer << endl;
  return 0;
}

