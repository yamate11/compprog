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

class UnionFind {
protected:
  int size;
  vector<int> _leader;
  vector<int> _rank;
  
public:
  UnionFind(int s);
  int leader(int i);
  int merge(int i, int j);
};

UnionFind::UnionFind(int s) {
  size = s;
  _leader = vector<int>(size);
  for (int i = 0; i < size; i++) { _leader.at(i) = i; }
  _rank = vector<int>(size, 1);
}

int UnionFind::leader(int i) {
  int cur = i;
  int nxt = _leader.at(cur);
  vector<int> seen;
  while (cur != nxt) {
    seen.push_back(cur);
    cur = nxt;
    nxt = _leader.at(cur);
  }
  for (auto j : seen) _leader.at(j) = cur;
  return cur;
}

int UnionFind::merge(int i0, int j0) {
  int li = leader(i0);
  int lj = leader(j0);
  if (li == lj) return li;
  int ri = _rank.at(li);
  int rj = _rank.at(lj);
  if      (ri < rj)  return _leader.at(li) = lj;
  else if (ri > rj)  return _leader.at(lj) = li;
  else {
    (_rank.at(lj))++;
    return _leader.at(li) = lj;
  }
}

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

  ll N, M, Q; cin >> N >> M >> Q;
  vector<int> A(Q), B(Q), C(Q);
  for (int i = 0; i < Q; i++) cin >> A.at(i) >> B.at(i) >> C.at(i);

  if (M == N-1) {
    if (all_of(C.begin(), C.end(), [&](int c){return c == 0;})) {
      cout << "Yes\n";
      return 0;
    }else {
      cout << "No\n";
      return 0;
    }
  }

  UnionFind uf(N);
  for (int i = 0; i < Q; i++) {
    if (C.at(i) == 0) uf.merge(A.at(i), B.at(i));
  }
  ll ncc = 0;
  for (int i = 0; i < N; i++) if (uf.leader(i) == i) ncc++;
  if ((ll)M <= (ll)N + (ll)ncc * (ll)(ncc - 3LL) / 2LL) {
    for (int i = 0; i < Q; i++) {
      if (C.at(i) == 1 && uf.leader(A.at(i)) == uf.leader(B.at(i))) {
	cout << "No\n";
	return 0;
      }
    }
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

