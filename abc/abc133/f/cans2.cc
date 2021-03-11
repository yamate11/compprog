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
vector<int> A, B, C, D;
vector<vector<int>> ptEdge;
vector<int> X, Y, U, V;
vector<vector<int>> parent;
vector<int> depth;
vector<vector<int>> colPt;
map<Pair, int> numColPt;
map<Pair, int> distColPt;
vector<int> distAllPt;
vector<int> numCol, distCol;
int logN;
int dist;
int N, Q;
int szP2;

int otherPt(int edge, int node) {
  if (A.at(edge) == node) return B.at(edge);
  else if (B.at(edge) == node) return A.at(edge);
  else assert(false);
}

void dfs(int n, int p, int d) {
  parent.at(n).at(0) = p;
  depth.at(n) = d;
  for (int e : ptEdge.at(n)) {
    int m = otherPt(e, n);
    if (m == p) continue;
    dfs(m, n, d+1);
  }
}

int setParentRep() {
  int i = 1;
  while (true) {
    assert(i < logN);
    bool moved = false;
    for (int n = 1; n <= N; n++) {
      int m = parent.at(n).at(i-1);
      int k = parent.at(m).at(i-1);
      parent.at(n).at(i) = k;
      moved = moved || (k != 1);
    }
    i++;
    if (!moved) break;
  }
  return i;
}

int nthParent(int node, int nth) {
  for (int i = 0; nth > 0; i++) {
    int bit = 1 << i;
    if (nth & bit) {
      assert(i < szP2);
      node = parent.at(node).at(i);
      nth = nth ^ bit;
    }
  }
  return node;
}

// Least Common Anscestor
int lca(int n, int m) {
  int dd = depth.at(n) - depth.at(m);
  if (dd > 0)      n = nthParent(n, dd);
  else if (dd < 0) m = nthParent(m, -dd);
  if (n == m) return n;
  for (int i = szP2 - 1; i >= 0; i--) {
    int n1 = parent.at(n).at(i);
    int m1 = parent.at(m).at(i);
    if (n1 != m1) {
      n = n1;
      m = m1;
    }
  }
  int n0 = parent.at(n).at(0);
  int m0 = parent.at(m).at(0);
  assert(n0 == m0);
  return n0;
}

void dfs2(int n, int p) {
  distAllPt.at(n) = dist;
  for (int c : colPt.at(n)) {
    numColPt[make_pair(c, n)] = numCol.at(c);
    distColPt[make_pair(c, n)] = distCol.at(c);
  }
  for (int e : ptEdge.at(n)) {
    int m = otherPt(e, n);
    if (m == p) continue;
    int col = C.at(e);
    numCol.at(col) += 1;
    distCol.at(col) += D.at(e);
    dist += D.at(e);
  
    dfs2(m, n);

    numCol.at(col) -= 1;
    distCol.at(col) -= D.at(e);
    dist -= D.at(e);
  }
}

int modDist(int c, int n, int y) {
  Pair p = make_pair(c, n);
  int z = distAllPt.at(n) + y * numColPt[p] - distColPt[p];
  return z;
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

  cin >> N >> Q;
  logN = 2 + log(N)/log(2);
  A.resize(N-1);
  B.resize(N-1);
  C.resize(N-1);
  D.resize(N-1);
  ptEdge.resize(N+1);
  for (int i = 0; i < N-1; i++) {
    cin >> A.at(i) >> B.at(i) >> C.at(i) >> D.at(i);
    ptEdge.at(A.at(i)).push_back(i);
    ptEdge.at(B.at(i)).push_back(i);
  }
  X.resize(Q);
  Y.resize(Q);
  U.resize(Q);
  V.resize(Q);
  for (int i = 0; i < Q; i++) {
    cin >> X.at(i) >> Y.at(i) >> U.at(i) >> V.at(i);
  }
  parent.resize(N+1, vector<int>(logN));
  depth.resize(N+1);
  
  dfs(1, 1, 0);
  szP2 = setParentRep();

  

  colPt.resize(N+1);
  for (int i = 0; i < Q; i++) {
    int w = lca(U.at(i), V.at(i));
    colPt.at(w).push_back(X.at(i));
    colPt.at(U.at(i)).push_back(X.at(i));
    colPt.at(V.at(i)).push_back(X.at(i));
  }

  distAllPt.resize(N+1);
  numCol.resize(N);
  distCol.resize(N);
  dist = 0;
  dfs2(1, 1);
  
  for (int i = 0; i < Q; i++) {
    int w = lca(U.at(i), V.at(i));
    int z = modDist(X.at(i), U.at(i), Y.at(i)) +
            modDist(X.at(i), V.at(i), Y.at(i)) -
            modDist(X.at(i), w,       Y.at(i)) * 2;
    cout << z << "\n";
  }


  return 0;
}

