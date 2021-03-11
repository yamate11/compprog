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

constexpr int maxN = 1e5;
int N;
vector<int> pos, neg, ax(maxN), ay(maxN);

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N;
  int numZ = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (x == 0) numZ++;
    else if (x > 0) pos.push_back(x);
    else neg.push_back(x);
  }
  for (int j = 0; j < numZ; j++) {
    if (pos.size() == 0) pos.push_back(0);
    else neg.push_back(0);
  }

  sort(pos.rbegin(), pos.rend());
  sort(neg.begin(), neg.end());

  ll pHead, nHead;
  if (pos.size() == 0) {
    pHead = neg.at(neg.size() - 1);
    nHead = neg.at(neg.size() - 2);
    neg.pop_back();
    neg.pop_back();
  }else if (neg.size() == 0) {
    nHead = pos.at(pos.size() - 1);
    pHead = pos.at(pos.size() - 1);
    pos.pop_back();
    pos.pop_back();
  }else {
    pHead = pos.at(pos.size() - 1);
    pos.pop_back();
    nHead = neg.at(neg.size() - 1);
    neg.pop_back();
  }
  
  int idx = 0;
  ll vp = pHead;
  for (int t : neg) {
    ax.at(idx) = vp;
    ay.at(idx) = t;
    vp -= t;
    idx++;
  }
  ll vn = nHead;
  for (int t : pos) {
    ax.at(idx) = vn;
    ay.at(idx) = t;
    vn -= t;
    idx++;
  }
  ax.at(idx) = vp;
  ay.at(idx) = vn;
  cout << vp - vn << "\n";
  for (int i = 0; i <= idx; i++) {
    cout << ax.at(i) << " " << ay.at(i) << "\n";
  }
  return 0;
}

