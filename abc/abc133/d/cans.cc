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

ll N;
vector<ll> A, X;

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

  cin >> N;
  A.resize(N);
  X.resize(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  ll s = 0;
  for (ll i = 0; i < N; i++) s += A.at(i);
  ll e = 0;
  for (ll i = 0; i < N-1; i += 2) e += A.at(i);
  X.at(N-1) = s/2 - e;
  X.at(0) = A.at(N-1) - X.at(N-1);
  for (ll i = 1; i < N-1; i++) X.at(i) = A.at(i-1) - X.at(i-1);
  for (ll i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << 2 * X.at(i);
  }
  cout << endl;

  return 0;
}

