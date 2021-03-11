#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// --- DEBUG begin --- cut here ---
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

// operator<< definitions for some classes

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
// --- DEBUG end --- cut here ---

auto& updMin(auto& a, const auto b) { return a = min(a, b); }
using Pair = pair<ll, ll>;

ll solve() {
  ll N, W, C; cin >> N >> W >> C;
  vector<Pair> L, R;
  for (ll i = 0; i < N; i++) {
    ll l, r, cost; cin >> l >> r >> cost;
    L.emplace_back(l, cost);
    R.emplace_back(r, cost);
  }
  DLOG("L", L);
  DLOG("R", R);
  sort(L.begin(), L.end());
  sort(R.begin(), R.end());
  ll tot = 0;
  ll i = 0;
  for (; i < N && L.at(i).first < C; i++) tot += L.at(i).second;
  DLOG("init, i", tot, i);
  ll ans = tot;
  ll j = 0;
  ll x = 0;
  while (true) {
    ll dl = i == N ? W + 1 : L.at(i).first - (x + C);
    ll dr = j == N ? W + 1 : R.at(j).first - x;
    if (x + min(dr, dl) + C > W) {
      break;
    }else if (dr <= dl) {
      tot -= R.at(j).second;
      DLOG("tot, j", tot, j);
      x = R.at(j).first;
      j++;
    }else {
      tot += L.at(i).second;
      DLOG("tot, i", tot, i);
      x = L.at(i).first - C;
      i++;
    }
    updMin(ans, tot);      
  }
  return ans;
}			     

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;
  return 0;
}

