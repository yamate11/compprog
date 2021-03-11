#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
  #define DFUNC(fname, ...) fname(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFUNC(fname, ...)
#endif

struct pair_hash {
  inline std::size_t operator()(const std::pair<int,int> & v) const {
    return v.first*31+v.second;
  }
};

typedef unordered_set<pair<int,int>, pair_hash> usetPairII;

int N,M,K;
vector<unordered_map<int,vector<int>>> nbr;
usetPairII pVisited;

void show_collection(const char* fmt, auto xs) {
  DLOG("[");
  bool first = true;
  for (auto x : xs)  {
    if (first)  first = false;
    else        DLOG(", ");
    DLOG(fmt, x);
  }
  DLOG("]\n");
}

unordered_set<int> next_set(unordered_set<int> cs) {
  unordered_set<int> result;
  stack<pair<int,int>> cands;
  for (int a : cs) {
    DLOG("init %d\n", a);
    for (auto v : nbr.at(a)) {
      int c = v.first;
      auto ac = make_pair(a,c);
      if (pVisited.count(ac))  continue;
      cands.push(ac);
      DLOG("cands.push(%d, %d)\n", a, c);
    }
  }
  while (!cands.empty()) {
    auto ac = cands.top();
    cands.pop();
    DLOG("from cands: (%d, %d)\n", ac.first, ac.second);
    if (!pVisited.count(ac)) {
      DLOG("  not visited\n");
      pVisited.insert(ac);
      int a = ac.first;
      int c = ac.second;
      for (int b : nbr.at(a).at(c)) {
	cands.push(make_pair(b,c));
	DLOG("--cands.push(%d, %d)\n", b, c);
      }
      if (!cs.count(a))  {
	result.insert(a);
	DLOG("result.insert(%d)\n", a);
      }
    }else {
      DLOG("  already visited\n");
    }
  }

  return result;
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> M >> K;
  nbr.resize(N+1);
  for (int i = 1; i <= M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    nbr.at(a)[c].push_back(b);
    nbr.at(b)[c].push_back(a);
  }
  int cnt = 0;
  unordered_set<int> cur_set({1});
  while (!cur_set.count(N))  {
    DFUNC(show_collection, "%d", cur_set);
    cnt++;
    cur_set = next_set(cur_set);
    if (cur_set.empty()) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << cnt*K << endl;
  return 0;
}

