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

void markRbl(int n, auto& nbr, auto& rbl) {
  if (rbl.at(n)) return;
  rbl.at(n) = true;
  for (int j : nbr.at(n)) markRbl(j, nbr, rbl);
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

  int N, M, P; cin >> N >> M >> P;
  vector<int> A(M), B(M), C(M);
  vector<vector<int>> nbrN(N+1), nbrR(N+1);
  for (int i = 0; i < M; i++)  {
    int a, b, c; cin >> a >> b >> c;
    A.at(i) = a;
    B.at(i) = b;
    C.at(i) = c;
    nbrN.at(a).push_back(b);
    nbrR.at(b).push_back(a);
  }
  vector<bool> rblN(N+1), rblR(N+1);
  markRbl(1, nbrN, rblN);
  markRbl(N, nbrR, rblR);
  assert(rblN.at(N) && rblR.at(1));
  int K = 0;
  for (int i = 1; i <= N; i++) if (rblN.at(i) && rblR.at(i)) K++;
  vector<int> dist(N+1);
  for (int i = 1; i <= N; i++) dist.at(i) = INT_MAX;
  dist.at(1) = 0;
  bool modified;
  for (int k = 0 ; k < K; k++) {
    modified = false;
    for (int i = 0; i < M; i++) {
      int a = A.at(i), b = B.at(i);
      if (! (rblN.at(a) && rblR.at(a) && rblN.at(b) && rblR.at(b))) continue;
      if (dist.at(a) == INT_MAX) continue;
      int newDist = dist.at(a) + P - C.at(i);
      if (newDist >= dist.at(b)) continue;
      dist.at(b) = newDist;
      modified = true;
    }
    if (!modified) break;
  }
  if (modified) cout << "-1\n";
  else          cout << max(0, -dist.at(N)) << "\n";
  return 0;
}

