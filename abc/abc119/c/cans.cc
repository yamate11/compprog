#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// See debug.cc for usage etc
#define DEBUG 0

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#if DEBUG
  #define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DCALL(func, ...)
#endif

// Returns a const char* representation of a container, such as a vector.
// Works for a container whose iterator has begin() and end()
// E.g.
//       vector<ll> v = {1, 2, 3};
//       DLOG("v = %s", toString(v).c_str());    // You need c_str()  
string toString(auto v) {
  stringstream ss;
  ss << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin())  ss << ", ";
    // if the value_type is not printable, modify the following line.
    ss << *it;
    // e.g., if it is a pair, use "ss << pairToString(*it)"
  }
  ss << "]";
  return ss.str();
}

int N, A, B, C;
vector<int> l;
vector<int> v;
int nA, nB, nC;

bool subNext(int i) {
  if (i == N) return false;
  if (subNext(i+1)) return true;
  if (v.at(i) < 3) {
    v.at(i)++;
    return true;
  }else {
    v.at(i) = 0;
    return false;
  }
}

bool next() {
  return subNext(0);
}

int calCost(int goal, int c) {
  int sumlen = 0;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (v.at(i) == c) {
      sumlen += l.at(i);
      cnt++;
    }
  }
  int retval;
  if (cnt == 0) {
    retval = (int)1e9;
  }else {
    retval = (cnt - 1) * 10 + abs(sumlen - goal);
  }
  DLOG("v = %s", toString(v).c_str());
  DLOG("calCost(%d, %d) = %d", goal, c, retval);
  return retval;
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> A >> B >> C;
  l.resize(N);
  for (int i = 0; i < N; i++) cin >> l.at(i);
  v.resize(N);
  int answer = 1e9;
  while(next()) {
    int cost = calCost(A, 1) + calCost(B, 2) + calCost(C, 3);
    answer = min(answer, cost);
  }
  cout << answer << endl;


  return 0;
}

