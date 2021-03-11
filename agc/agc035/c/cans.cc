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

int N;

int lsb(int x) { return x & (-x); }

bool isPower2(int x) {
  return (x ^ lsb(x)) == 0;
}

void out(int x, int y) {
  cout << x << " " << y << "\n";
}

void printOdd(int n) {
  out(1, 2);
  out(2, 3);
  out(N+1, N+2);
  out(N+2, N+3);
  out(N+3, 1);
  for (int k = 4; k < n; k += 2) {
    out(1, k);
    out(k, k+1);
    out(N+k, N+k+1);
    out(N+k+1, 1);
  }
}

void printEven(int n) {
  printOdd(n-1);
  int x = n ^ lsb(n);
  int y = n - x;
  out(y, n);
  out(N + x + 1, N + n);
}

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
  if (isPower2(N)) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  if (N % 2 == 1) {
    printOdd(N);
  }else {
    printEven(N);
  }

  return 0;
}

