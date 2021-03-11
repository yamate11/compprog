#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug cmpNaive)
// --> f:<< debug cmpNaive
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

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig) {
  queue<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
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

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st) {
  stack<T> tmp(st);
  os << '[';
  bool first = true;
  while (!tmp.empty()) {
    T& t = tmp.top();
    if (first) first = false;
    else os << ", ";
    os << t;
    tmp.pop();
  }
  os << ']';
  return os;
}

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t) {
  if (t.has_value()) os << "v(" << t.value() << ")";
  else               os << "nullopt";
  return os;
}
#endif

ostream& operator<< (ostream& os, int8_t x) {
  os << (int32_t)x;
  return os;
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

#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(__VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif

// ---- end debug.cc
// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");
const string end_file_mark("^__=end_file=__^");

int naive(istream& cin, ostream& cout);
int body(istream& cin, ostream& cout);

void cmpNaive() {
  while (true) {
    string s;
    getline(cin, s);
    bool run_body;
    if (s.at(0) == 'Q') {
      return;
    }else if (s.at(0) == 'B') {
      run_body = true;
    }else if (s.at(0) == 'N') {
      run_body = false;
    }else {
      cerr << "Unknown body/naive specifier.\n";
      exit(1);
    }
    string input_s;
    while (true) {
      getline(cin, s);
      if (s == end_mark) break;
      input_s += s;
      input_s += "\n";
    }
    stringstream ss_in(move(input_s));
    stringstream ss_out;
    if (run_body) {
      body(ss_in, ss_out);
    }else {
      naive(ss_in, ss_out);
    }
    cout << ss_out.str() << end_mark << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if CMPNAIVE
  if (argc == 2) {
    if (strcmp(argv[1], "cmpNaive") == 0) {
      cmpNaive();
    }else if (strcmp(argv[1], "naive") == 0) {
      naive(cin, cout);
    }else {
      cerr << "Unknown argument.\n";
      exit(1);
    }
  }else {
#endif
    body(cin, cout);
#if CMPNAIVE
  }
#endif
  return 0;
}

/*
int naive(istream& cin, ostream& cout) {
  return 0;
}
int body(istream& cin, ostream& cout) {
  return 0;
}
*/

// ---- end cmpNaive.cc
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {
  ll N, K; cin >> N >> K;
  vector<ll> C(N), R(N);
  for (ll i = 0; i < N; i++) cin >> C[i] >> R[i];
  vector<vector<ll>> nbr(N);
  ll big = 1e12;
  vector<vector<ll>> dist(N, vector(N, big));
  for (ll i = 0; i < K; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
    dist[a][b] = dist[b][a] = 1;
  }

  for (ll i = 0; i < N; i++) dist[i][i] = 0;
  for (ll k = 0; k < N; k++) {
    for (ll i = 0; i < N; i++) {
      for (ll j = 0; j < N; j++) {
	if (dist[i][k] + dist[k][j] < dist[i][j]) {
	  dist[j][i] = dist[i][j] = dist[i][k] + dist[k][j];
	}
      }
    }
  }
  DLOG("dist=", dist);

  vector cost(N, vector(N, big));
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      if (j == i) cost[i][j] = 0;
      if (dist[i][j] <= R[i]) cost[i][j] = C[i];
    }
  }
  for (ll k = 0; k < N; k++) {
    for (ll i = 0; i < N; i++) {
      for (ll j = 0; j < N; j++) {
	if (cost[i][k] + cost[k][j] < cost[i][j]) {
	  cost[i][j] = cost[i][k] + cost[k][j];
	}
      }
    }
  }
  cout << cost[0][N-1] << endl;

  return 0;
}

int body(istream& cin, ostream& cout) {

  ll N, K; cin >> N >> K;
  vector<ll> C(N), R(N);
  for (ll i = 0; i < N; i++) cin >> C[i] >> R[i];
  vector<vector<ll>> nbr(N);
  for (ll i = 0; i < K; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  ll big = 1e9;
  vector<vector<ll>> direct(N);
  using sta = pair<ll, ll>;
  for (ll i = 0; i < N; i++) {
    queue<sta> que;
    vector<ll> dist(N, big);
    que.emplace(0, i);
    dist[i] = 0;
    while (!que.empty()) {
      auto [d, x] = que.front(); que.pop();
      if (d > 0) direct[i].push_back(x);
      ll newD = d + 1;
      if (newD > R[i]) continue;
      for (ll y : nbr[x]) {
	if (dist[y] > newD) {
	  dist[y] = newD;
	  que.emplace(newD, y);
	}
      }
    }
  }
  DLOG("direct=", direct);
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  vector<ll> cost(N, big);
  pque.emplace(0, 0);
  cost[0] = 0;
  while (!pque.empty()) {
    auto [c, x] = pque.top(); pque.pop();
    if (cost[x] < c) continue;
    if (x == N - 1) {
      cout << c << endl;
      return 0;
    }
    for (ll y : direct[x]) {
      ll newC = c + C[x];
      if (cost[y] > newC) {
	cost[y] = newC;
	pque.emplace(newC, y);
      }
    }
  }
  assert(0);

  return 0;
}

