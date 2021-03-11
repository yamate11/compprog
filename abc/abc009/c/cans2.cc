#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug)
// --> f:<< debug
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
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  string orig; cin >> orig;
  if (K <= 1) {
    cout << orig << endl;
    return 0;
  }

  vector<deque<ll>> rem(128);
  for (ll i = 0; i < N; i++) rem.at(orig.at(i)).push_back(i);
  char crem = 'a';

  vector<bool> vacant(N);

  priority_queue<char, vector<char>, greater<char>> pending;

  vector<char> result(N);
  ll cost = 0;

  for (ll m = 0; m < N; m++) {
    DLOG("m", m);
    char c = 'z' + 1;
    ll type = -1;
    ll add = vacant.at(m) ? 0 : 1;
    if (!vacant.at(m)) {
      c = orig.at(m);
      type = 0;
    }
    if (cost <= K - add && !pending.empty() && pending.top() < c) {
      c = pending.top();
      type = 1;
    }
    for (; crem <= 'z' && rem.at(crem).size() == 0; crem++);
    if (cost <= K-1 - add && crem < c) {
      c = crem;
      type = 2;
    }
    DLOG("cost", cost, "crem", crem, "c", c, "type", type, "rem.at(crem).size()", rem.at(crem).size());
    if (type == 0) {
      // do nothing
    }else if (type == 1) {
      pending.pop();
    }else if (type == 2) {
      ll i = rem.at(crem).back(); rem.at(crem).pop_back();
      vacant.at(i) = true;
      cost++;
    }else assert(0);
    if (!vacant.at(m)) {
      char cr = orig.at(m);
      rem.at(cr).pop_front();
      if (type != 0) {
	pending.push(cr);
	cost++;
      }
      DLOG("pop_front", cr);
    }
    result.at(m) = c;
  }

  string ans(result.begin(), result.end());
  cout << ans << endl;

  return 0;
}


