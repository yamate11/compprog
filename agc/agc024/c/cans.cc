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

  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  auto getHeight = [&](int& i) -> int {
    int j = i + 1;
    while (j < N && A.at(j-1) + 1 == A.at(j)) j++;
    if (j < N && A.at(j) > A.at(j-1) + 1) throw MyException();
    i = j;
    return A.at(j-1);
  };

  ll ans = 0;
  try {
    if (A.at(0) > 0) throw MyException();
    int i = 0;
    while (i < N) {
      ll h = getHeight(i);
      ans += h;
    }
  } catch (MyException& e) {
    ans = -1;
  }

  cout << ans << endl;

  return 0;
}

