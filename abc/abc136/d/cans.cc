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

vector<int> ans;

void pout(int n, int k) {
  for (int i = 0; i < k; i++) {
    ans.push_back(n);
  }
}

int block(const string& S, int i) {
  int r = 0, l = 0;
  for (; i < S.size() && S.at(i) == 'R'; i++, r++);
  for (; i < S.size() && S.at(i) == 'L'; i++, l++);
  int p1 = r / 2;
  int p2 = r - p1;
  int q1 = l / 2;
  int q2 = l -q1;
  pout(0, r - 1);
  pout(p2 + q1, 1);
  pout(p1 + q2, 1);
  pout(0, l - 1);
  return i;
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

  string S; cin >> S;
  for (int i = 0; i < S.size(); i = block(S, i));
  for (int i = 0; i < ans.size(); i++) {
    if (i > 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;

  return 0;
}

