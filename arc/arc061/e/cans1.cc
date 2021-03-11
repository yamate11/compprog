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

struct Group {
  int id;
  int com;
  vector<int> stns;
  Group(int i, int c) : id(i), com(c) {}
  static int seq;
  static vector<Group> instances;
  static Group& create(int c) {
    instances.emplace_back(seq++, c);
    return instances[instances.size() - 1];
  }
  static Group& get(int i) { return instances[i]; }
  
};

int Group::seq;
vector<Group> Group::instances;


int N, M;
unordered_map<int, int> mGrp;
vector<unordered_map<int, vector<int>>> peer;
unordered_set<bool> visited;
unordered_set<int> goal;

struct DQI {
  int gid;
  int dist;
  DQI(int g, int d) : gid(g), dist(d) {}
};
deque<DQI> deq;

int enc(int com, int stn) { return com * (N+1) + stn; }

void mkGrp(int g, int com, int stn) {
  int e = enc(com, stn);
  auto it = mGrp.find(e);
  if (it != mGrp.end()) return;
  Group& grp = (g == -1) ? Group::create(com) : Group::get(g);
  grp.stns.push_back(stn);
  mGrp[e] = grp.id;
  for (int p : peer.at(stn)[com]) mkGrp(grp.id, com, p);
}

int bfs() {
  while (!deq.empty()) {
    DQI di = deq.front(); deq.pop_front();
    int g = di.gid;
    if (goal.count(g)) return di.dist;
    if (visited.count(g)) continue;
    visited.insert(g);
    Group& grp = Group::get(g);
    int com = grp.com;
    for (int stn : grp.stns) {
      for (auto t : peer.at(stn)) {
	if (t.first != com) {
	  int g1 = mGrp[enc(t.first, stn)];
	  if (! visited.count(g1)) deq.emplace_back(g1, di.dist + 1);
	}
      }
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
  vector<int> P(M), Q(M), C(M);
  peer.resize(N+1);

  for (int i = 0; i < M; i++) {
    int p, q, c; cin >> p >> q >> c;
    cin >> p >> q >> c;
    P.at(i) = p;
    Q.at(i) = q;
    C.at(i) = c;
    peer.at(p)[c].push_back(q);
    peer.at(q)[c].push_back(p);
  }

  for (int j = 0; j < M; j++) {
    mkGrp(-1, C.at(j), P.at(j));
  }
  
  for (auto t : peer.at(N)) goal.insert(mGrp[enc(t.first, N)]);
  for (auto t : peer.at(1)) deq.emplace_back(mGrp[enc(t.first, 1)], 1);
  cout << bfs() << endl;

  return 0;
}

