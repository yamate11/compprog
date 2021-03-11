#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

using Vec1 = vector<ll>;
using Vec2 = vector<Vec1>;

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


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  Vec2 a(N, Vec1(M)), b(N, Vec1(M));
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    for (int j = 0; j < M; j++) {
      b.at(i).at(j) = s.at(j) - '0';
    }
  }
  auto modify = [&](ll y, ll x, ll p) -> void {
    DLOG("modify", y, x, p);
    b.at(y-1).at(x) -= p;
    b.at(y+1).at(x) -= p;
    b.at(y).at(x-1) -= p;
    b.at(y).at(x+1) -= p;
    a.at(y).at(x) += p;
  };

  for (ll k = 0; k <= (min(N, M)-1) / 2; k++) {
    for (ll j = k+1; j < M - (k+1); j++) {
      modify(k+1,           j, b.at(k        ).at(j));
      modify((N-1) - (k+1), j, b.at(N - (k+1)).at(j));
    }
    for (ll i = k+1; i < N - (k+1); i++) {
      modify(i, k+1,           b.at(i).at(k        ));
      modify(i, (M-1) - (k+1), b.at(i).at(M - (k+1)));
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << a.at(i).at(j);
    }
    cout << "\n";
  }

  return 0;
}

