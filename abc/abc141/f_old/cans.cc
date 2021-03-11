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
int K = 60;

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
  vector<ll> A(N);
  for (int i = 0; i < N; i++) { cin >> A.at(i); }

  vector<vector<char>> mat(K, vector<char>(N));
  vector<char> vecOdd(K);
  for (int j = 0; j < K; j++) {
    char x = 0;
    for (int i = 0; i < N; i++) {
      char b = (A.at(i) >> j) & 1;
      mat.at(j).at(i) = b;
      x ^= b;
    }
    if (x) {
      vecOdd.at(j) = 1;
      for (int i = 0; i < N; i++) mat.at(j).at(i) = 0;
    }
  }
  int idp = 0;
  for (int j = K-1; j >= 0 && idp < N; j--) {
    if (vecOdd.at(j)) continue;
    int i0;
    for (i0 = idp ; i0 < N && mat.at(j).at(i0) == 0; i0++);
    if (i0 == N) continue;
    if (i0 > idp) {
      for (int jj = j; jj >= 0; jj--) {
	swap(mat.at(jj).at(i0), mat.at(jj).at(idp));
      }
    }
    for (int i = 0; i < N; i++) {
      if (i == idp) continue;
      if (mat.at(j).at(i) == 0) continue;
      for (int jj = j; jj >= 0; jj--) mat.at(jj).at(i) ^= mat.at(jj).at(idp);
    }
    idp++;
  }
  ll ans = 0;
  for (int i = 0; i < idp; i++) {
    ll x = 0;
    for (int j = K-1; j >= 0; j--) {
      if (mat.at(j).at(i)) x += (1LL << j);
    }
    ans ^= x;
  }
  ll xo = 0;
  for (int j = K-1; j >= 0; j--) {
    if (vecOdd.at(j)) xo += (1LL << j);
  }
  cout << 2 * ans + xo << endl;

  return 0;
}

