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

typedef pair<int, int> Pair;
vector<vector<vector<Pair>>> succ;
vector<vector<int>> numPrev;


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
  succ.resize(N+1, vector<vector<Pair>>(N+1));
  numPrev.resize(N+1, vector<int>(N+1));
  
  for (int i = 1; i <= N; i++) {
    int pr = -1;
    for (int j = 1; j <= N-1; j++) {
      int x; cin >> x;
      if (j > 1) {
	int p1, q1, p2, q2;
	if (i < pr) {
	  p1 = i; q1 = pr;
	}else {
	  p1 = pr; q1 = i;
	}
	if (i < x) {
	  p2 = i; q2 = x;
	}else {
	  p2 = x; q2 = i;
	}
	succ.at(p1).at(q1).emplace_back(p2, q2);
      }
      pr = x;
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = i+1; j <= N; j++) {
      for (Pair p : succ.at(i).at(j)) {
	numPrev.at(p.first).at(p.second) += 1;
      }
    }
  }

  int days = 0;
  int done = 0;
  vector<Pair> top;
  for (int i = 1; i <= N; i++) {
    for (int j = i+1; j <= N; j++) {
      if (numPrev.at(i).at(j) == 0) top.emplace_back(i, j);
    }
  }

  while (top.size() > 0) {
    days += 1;
    done += top.size();
    vector<Pair> nextTop;
    for (Pair p : top) {
      for (Pair q : succ.at(p.first).at(p.second)) {
	numPrev.at(q.first).at(q.second) -= 1;
	if (numPrev.at(q.first).at(q.second) == 0) {
	  nextTop.emplace_back(q.first, q.second);
	}
      }
    }
    top = nextTop;
  }

  if (done < N * (N-1) / 2)  days = -1;
  
  cout << days << endl;

  return 0;
}

