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

vector<int> A, B;

class myComp {
public:
  bool operator() (const int& p, const int& q) const {
    return B.at(p) < B.at(q);
  }
};

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
  A.resize(N);
  B.resize(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) cin >> B.at(i);

  priority_queue<int, vector<int>, myComp> que;
  for (int i = 0; i < N; i++) {
    if (A.at(i) < B.at(i)) que.push(i);
    else if (A.at(i) > B.at(i)) {
      cout << "-1" << endl;
      return 0;
    }
  }

  int res = 0;
  while (!que.empty()) {
    int i = que.top(); que.pop();
    int j = (i + N - 1) % N;
    int k = (i + 1) % N;
    int t = B.at(j) + B.at(k);
    if ((B.at(i) - A.at(i)) % t == 0) {
      res += (B.at(i) - A.at(i)) / t;
      B.at(i) = A.at(i);
    }else if (B.at(i) <= t) {
      cout << "-1" << endl;
      return 0;
    }else {
      int r = B.at(i) / t;
      B.at(i) -= t * r;
      res += r;
      if (A.at(i) < B.at(i)) que.push(i);
      else {
	cout << "-1" << endl;
	return 0;
      }
    }
  }
  cout << res << endl;
  
  return 0;
}

