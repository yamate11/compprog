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

vector<int> zAlg(string s) {
  int n = s.size();
  vector<int> z(n);
  z.at(0) = n;
  int i = 1;
  int j = 0;
  while (i < n) {
    for ( ; i+j < n && s.at(j) == s.at(i+j); j++) {}
    z.at(i++) = j;
    if (j > 0) {
      for (int k = 1; i < n && z.at(k) < j-1; k++, j--, i++) z.at(i) = z.at(k);
      j--;
    }
  }
  return z;
}

// matches("abab", "xababab") --> [1,3]
vector<int> matches(string p, string s, char sepChar = '\xff') {
  auto v = zAlg(p + string(1, sepChar) + s);
  int n = p.size();
  vector<int> res;
  for (size_t i = 0; i < s.size() - (n-1); i++) {
    if (v.at(n+1 + i) == n) res.push_back(i);
  }
  return res;
}

int out(int x) {
  cout << x << endl;
  return 0;
}

int sch(int i, int stop, const string& s, const string& t, auto& vm) {
  int j = (i + t.size()) % s.size();
  if (j == stop) return -1;
  if (vm.at(j) < 0) {
    if (sch(j, stop, s, t, vm) < 0) return -1;
  }
  vm.at(i) = vm.at(j) + 1;
  return vm.at(i);
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

  string s;
  string t;
  cin >> s >> t;
  int r = 1 + (s.size() - 1 + t.size()) / s.size();
  string reps = "";
  reps.reserve(r * s.size());
  for (int i = 0; i < r; i++) reps += s;
  auto vec = matches(t, reps);
  vector<int> vm(s.size());
  for (size_t i : vec) {
    if (i >= s.size()) break;
    vm.at(i) = -1;
  }
  int maxSize = 0;
  for (size_t i : vec) {
    if (i >= s.size()) break;
    int x = sch(i, i, s, t, vm);
    if (x == -1) return out(-1);
    maxSize = max(maxSize, x);
  }
  return out(maxSize);


}

