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

ll getA(auto tp) {
  ll a;
  tie(a, ignore, ignore) = tp;
  return a;
}

ll getB(auto tp) {
  ll b;
  tie(ignore, b, ignore) = tp;
  return b;
}

ll getN(auto tp) {
  ll n;
  tie(ignore, ignore, n) = tp;
  return n;
}

using Tup = tuple<ll, ll, ll>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<Tup> ab;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    ab.emplace_back(a, b, i+1);
  }
  sort(ab.begin(), ab.end());
  vector<ll> et;
  ll t = LLONG_MAX;
  et.push_back(t);
  ll i = (ll)ab.size() - 1;
  DLOG("pt0");
  while (true) {
    DLOG("** ", i, t, getA(ab.at(i)), getB(ab.at(i)));
    for ( ; i >= 0 && getB(ab.at(i)) > t; i--);
    if (i < 0) break;
    t = getA(ab.at(i));
    et.push_back(t);
  }
  DLOG("pt1");
  sort(ab.begin(), ab.end(),
       [](auto p, auto q) -> bool { return getB(p) < getB(q); });
  auto comp = [&](int p, int q) -> bool {
    return getN(ab.at(p)) > getN(ab.at(q));
  };
  priority_queue<ll, vector<ll>, decltype(comp)> pque(comp);
  vector<ll> ans;
  i = 0;
  ll st = LLONG_MIN;
  for (ll j = (ll)et.size() - 2; j >= 0; j--) {
    DLOG("ptX", i, j, et.at(j), st);
    for ( ; i < N && getB(ab.at(i)) <= et.at(j); i++) pque.push(i);
    while (true) {
      ll k = pque.top(); pque.pop();
      DLOG("popped ", k);
      if (getA(ab.at(k)) >= st) {
	st = getB(ab.at(k));
	ans.push_back(getN(ab.at(k)));
	break;
      }
    }
  }
  DLOG("pt2");
  cout << ans.size() << endl;
  for (ll j = 0; j < (ll)ans.size(); j++) {
    if (j > 0) cout << " ";
    cout << ans.at(j);
  }
  DLOG("pt3");
  cout << endl;

  return 0;
}

