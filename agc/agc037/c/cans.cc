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
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) cin >> B.at(i);
  auto comp = [&](int i, int j) { return B.at(i) < B.at(j); };
  priority_queue<int, vector<int>, decltype(comp)> pque(comp);
  for (int i = 0; i < N; i++) {
    if (A.at(i) < B.at(i)) pque.push(i);
  }
  ll answer = 0;
  while (!pque.empty()) {
    int i = pque.top(); pque.pop();
    int v = B.at((N+i-1) % N) + B.at((i+1) % N);
    int x = (B.at(i) - A.at(i)) / v;
    if (x == 0) {
      cout << "-1\n";
      return 0;
    }
    answer += x;
    B.at(i) -= v * x;
    if (B.at(i) > A.at(i)) pque.push(i);
  }
  cout << answer << endl;
  return 0;
}

