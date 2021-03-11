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

  ll N, M, K; cin >> N >> M >> K;

  random_device dev;
  mt19937 rng(dev());
  uniform_int_distribution<int> dist1(0, N-1);
  uniform_int_distribution<int> dist2(0, N-2);

  ll dur = 250;
  ll repSes = 10000;

  vector<vector<bool>> prohibit(N, vector<bool>(N));
  for (ll i = 0; i < M; i++) {
    ll a, b; cin >> a >> b;
    prohibit.at(a).at(b) = true;
    prohibit.at(b).at(a) = true;
  }
  vector<ll> vec0(N);
  iota(vec0.begin(), vec0.end(), 0);
  ll cnt = 0;
  ll succCnt = 0;
  
  auto stime = chrono::steady_clock::now();
  while (true) {
    for (ll p = 0; p < repSes; p++) {
      vector<ll> vec(vec0);
      for (ll i = 0; i < K; i++) {
	ll x = dist1(rng);
	ll y = (x + 1 + dist2(rng)) % N;
	swap(vec.at(x), vec.at(y));
      }
      DLOG("vec", vec);
      bool success = true;
      if (prohibit.at(vec.at(0)).at(vec.at(N-1))) {
	DLOG("fail ... ", 0, N-1);
	success = false;
      }else {
	for (ll i = 0; i < N - 1; i++) {
	  if (prohibit.at(vec.at(i)).at(vec.at(i+1))) {
	    DLOG("fail ... ", i, i+1);
	    success = false;
	    break;
	  }
	}
      }
      cnt++;
      if (success) {
	DLOG("success");
	succCnt ++;
      }else {
	DLOG("fail");
      }
    }
    auto etime = chrono::steady_clock::now();
    ll elapsed = chrono::duration_cast<chrono::milliseconds>(etime - stime).count();
    if (elapsed > dur) {
      cout << (double)succCnt / cnt << endl;
      // cerr << "cnt = " << cnt << endl;
      return 0;
    }
  }

  return 0;
}

