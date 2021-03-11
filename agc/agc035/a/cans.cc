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
vector<int> cnt(3);
vector<int> p(3);

int foo(int x, int t) {
  for (int j = 0; j < t; j++) {
    if (p.at(j) == x) {
      cnt.at(j)++;
      return t;
    }
  }
  if (t < 3) {
    p.at(t) = x;
    cnt.at(t) = 1;
    return t+1;
  }else {
    return -1;
  }
}

int answer(bool isOK) {
  cout << (isOK ? "Yes" : "No") << endl;
  exit(0);
}

void vSwap(int i) {
  swap(p.at(0), p.at(i));
  swap(cnt.at(0), cnt.at(i));
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
  int t = 0;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    t = foo(x, t);
    if (t < 0)  answer(false);
  }
  if (t == 1 && p.at(0) == 0)  answer(true);
  if (t == 2 && p.at(1) == 0)  vSwap(1);
  if (t == 2 && p.at(0) == 0 && cnt.at(1) == 2 * cnt.at(0)) answer(true);
  if (t == 3 && p.at(0) == (p.at(1) ^ p.at(2)) &&
      cnt.at(0) == cnt.at(1) && cnt.at(0) == cnt.at(2)) answer(true);
  answer(false);
  return 0;
}

