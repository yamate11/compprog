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

int N; 
vector<int> A(4);
vector<vector<int>> o(4);
vector<bool> visited;

int enc(vector<int> is) {
  return is.at(3) + N*(is.at(2) + N*(is.at(1) + N*is.at(0)));
}

int getCand(vector<int> is, vector<int>& ret) {
  vector<int> js(4);
  vector<vector<int>> ns(5);
  for (int i = 0; i < 4; i++) {
    js.at(i) = (is.at(i) == A.at(i)) ? 4 : o.at(i).at(is.at(i));
    ns.at(js.at(i)).push_back(i);
  }
  if (ns.at(4).size() == 4) return 0;
  if (ns.at(1).size() == 1 && ns.at(2).size() == 1 &&
      ns.at(3).size() == 1 && ns.at(4).size() == 1) {
    ret.push_back(ns.at(4).at(0));
    return 1;
  }
  int p = -1;
  for (int n = 1; n <= 3; n++) {
    int s = ns.at(n).size();
    if (s == 1)  continue;
    else if (s == 2)  p = n;
    else return -1;
  }
  ret.push_back(ns.at(p).at(0));
  ret.push_back(ns.at(p).at(1));
  return 1;
}

bool dfs(vector<int> is, vector<int>& fourths) {
  int e = enc(is);
  if (visited.at(e)) { return false; }
  visited.at(e) = true;
  vector<int> cands;
  int rc = getCand(is, cands);
  if (rc == -1) return false;
  if (rc == 0) return true;
  for (int c : cands) {
    vector<int> is1 = is;
    for (int i = 0; i < 4; i++) {
      if (i != c) is1.at(i)++;
    }
    if (dfs(is1, fourths)) {
      fourths.push_back(c);
      return true;
    }
  }
  return false;
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

  cin >> N;
  int ss = 0;
  for (int i = 0; i < 4; i++) {
    cin >> A.at(i);
    ss += A.at(i);
  }
  if (3*N != ss) {
    cout << "No\n";
    return 0;
  }
  for (int i = 0; i < 4; i++) {
    o.at(i).resize(A.at(i));
    for (int j = 0; j < A.at(i); j++) {
      cin >> o.at(i).at(j);
    }
  }
  
  visited.resize((N+1)*(N+1)*(N+1)*(N+1));
  vector<int> fourths;
  if (dfs(vector<int>({0, 0, 0, 0}), fourths)) {
    reverse(fourths.begin(), fourths.end());
    cout << "Yes\n";
    for (int f : fourths) {
      cout << f + 1 << "\n";
    }
  }else {
    cout << "No\n";
  }

  return 0;
}

