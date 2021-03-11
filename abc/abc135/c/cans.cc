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
  vector<int> A(N+1), B(N);
  for (int i = 0; i < N+1; i++)  cin >> A.at(i);
  for (int i = 0; i < N; i++) cin >> B.at(i);
  ll num = 0;
  ll carry = A.at(0);
  for (int i = 0; i < N; i++) {
    if (carry >= B.at(i)) {
      num += B.at(i);
      carry = A.at(i+1);
    }else {
      num += carry;
      int x = B.at(i) - carry;
      if (A.at(i+1) >= x) {
	num += x;
	carry = A.at(i+1) - x;
      }else {
	num += A.at(i+1);
	carry = 0;
      }
    }
  }
  cout << num << endl;

  return 0;
}

