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
  vector<ll> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) cin >> B.at(i);
  ll sumA = 0;
  ll sumB = 0;
  for (int i = 0; i < N; i++) {
    sumA += A.at(i);
    sumB += B.at(i);
  }
  ll diff = sumB - sumA;
  if (diff < 0) {
    cout << "No\n";
    return 0;
  }
  ll cnt = 0;
  for (int i = 0; i < N; i++) {
    ll x = B.at(i) - A.at(i);
    if (x <= 0) continue;
    cnt += (x + 1) / 2;
  }
  if (cnt <= diff) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}

