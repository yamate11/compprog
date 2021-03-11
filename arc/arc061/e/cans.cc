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

struct DI {
  int com;
  int stn;
  int dist;
  DI(int c, int s, int d) : com(c), stn(s), dist(d) {}
};

int N, M;
vector<unordered_map<int, vector<int>>> peer;
deque<DI> deq;
unordered_set<int> visited;

int enc(int com, int stn) {
  return com * (N+1) + stn;
}

int bfs() {
  while (!deq.empty()) {
    DI di(deq.front()); deq.pop_front();
    if (di.stn == N) return di.dist;
    int e = enc(di.com, di.stn);
    if (visited.count(e)) continue;
    visited.insert(e);
    for (int q : peer.at(di.stn)[di.com]) {
      deq.emplace_front(di.com, q, di.dist);
    }
    int e2 = enc(0, di.stn);
    if (visited.count(e2)) continue;
    visited.insert(e2);
    for (auto t : peer.at(di.stn)) {
      int com1 = t.first;
      if (di.com == com1) continue;
      deq.emplace_back(com1, di.stn, di.dist + 1);
    }
  }
  return -1;
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

  cin >> N >> M;
  peer.resize(N+1);
  for (int i = 0; i < M; i++) {
    int p, q, c; cin >> p >> q >> c;
    peer.at(p)[c].push_back(q);
    peer.at(q)[c].push_back(p);
  }

  for (auto t : peer.at(1)) {
    deq.emplace_back(t.first, 1, 1);
  }
  cout << bfs() << endl;

  return 0;
}

