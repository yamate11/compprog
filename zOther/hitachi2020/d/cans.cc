#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug binsearch)
// --> f:<< debug binsearch
// ---- inserted function << from util.cc
template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const set<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const multiset<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const map<T1, T2>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}
// ---- end <<
// ---- inserted library file debug.cc
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void dbgLog(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(__VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

// ---- end debug.cc
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / (T)2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, T; cin >> N >> T; T++;
  using Tup = tuple<double, ll, ll>;
  vector<Tup> dat;
  vector<ll> cst;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b; a++; b++;
    if (a >= 2) {
      double eff = (double)(a - 1) / (double)b;
      dat.emplace_back(eff, a, b);
    }else {
      cst.push_back(b);
    }
  }
  sort(dat.begin(), dat.end(), greater<Tup>());
  vector<ll> prev(1);
  prev.at(0) = 1;
  for (ll i = 0; i < (ll)dat.size(); i++) {
    vector<ll> cur;
    cur.push_back(1);
    double eff; ll a, b; tie(eff, a, b) = dat.at(i);
    for (ll j = 0; j < (ll)prev.size(); j++) {
      ll newT = a * prev.at(j) + b;
      ll v = j + 1 < (ll)prev.size() ? min(prev.at(j+1), newT) : newT;
      if (v <= T) cur.push_back(v);
    }
    DLOG("i", i, "cur", cur);
    prev = move(cur);
  }
  sort(cst.begin(), cst.end());
  vector<ll> acc;
  acc.push_back(0);
  for (ll i = 0; i < (ll)cst.size(); i++) {
    acc.push_back(acc.at(i) + cst.at(i));
  }
  ll ans = 0;
  for (ll i = 0; i < (ll)prev.size(); i++) {
    auto check = [&](ll z) -> bool { return prev.at(i) + acc.at(z) <= T; };
    ll cntCst = binsearch<ll>(check, 0, acc.size());
    ans = max(ans, i + cntCst);
  }
  cout << ans << endl;



  return 0;
}

