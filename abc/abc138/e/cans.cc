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

  string s, t; cin >> s >> t;
  vector<vector<int>> nxt(26, vector<int>(s.size()));
  for (size_t i = 0; i < s.size(); i++) {
    int c = s.at(i) - 'a';
    for (int j = i; j >= 0 && nxt.at(c).at(j) == 0; j--) {
      nxt.at(c).at(j) = i - j + 1;
    }
  }
  for (int c = 0; c < 26; c++) {
    int k = nxt.at(c).at(0);
    if (k == 0) continue;
    for (int j = s.size() - 1; j >= 0 && nxt.at(c).at(j) == 0; j--) {
      nxt.at(c).at(j) = k + s.size() - j;
    }
  }
  ll val = 0;
  int pos = 0;
  for (size_t i = 0; i < t.size(); i++) {
    int dist = nxt.at(t.at(i) - 'a').at(pos);
    if (dist == 0) {
      cout << "-1\n";
      return 0;
    }
    val += dist;
    pos = (pos + dist) % s.size();
  }
  cout << val << endl;

  return 0;
}

