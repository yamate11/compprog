#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
typedef unsigned long long ull;
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

struct Exc : exception {};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> S(N), T(N);
  for (ll i = 0; i < N; i++) cin >> S.at(i);
  for (ll i = 0; i < N; i++) cin >> T.at(i);
  vector<ull> U(N), V(N);
  for (ll i = 0; i < N; i++) cin >> U.at(i);
  for (ll i = 0; i < N; i++) cin >> V.at(i);

  try {
    vector<vector<ull>> A(N, vector<ull>(N));
    for (ll z = 0; z < 64; z++) {

      auto opres = [&](const auto& w, ll i) -> ll {
	return ((w.at(i) >> z) & 1);
      };

      const int Horiz = 0, Vert = 1;
      vector all(2, vector<ll>(2)), ex(2, vector<ll>(2));
      auto ao = [&](ll t) -> const vector<ll>& { return t == Horiz ? S : T; };
      auto vspec = [&](ll t) -> const vector<ull>&{return t == Horiz ? U : V;};
      for (ll i = 0; i < N; i++) {
	for (ll t = 0; t < 2; t++) {
	  if (opres(vspec(t), i)) {
	    if (ao(t).at(i)) ex.at(t).at(1)++;
	    else             all.at(t).at(1)++;
	  }else {
	    if (ao(t).at(i)) all.at(t).at(0)++;
	    else             ex.at(t).at(0)++;
	  }
	}
      }

      vector mustFill(2, vector(2, false));
      for (ll t = 0; t < 2; t++) {
	for (ll v = 0; v < 2; v++) {
	  if (all.at(t).at(v) && all.at(1-t).at(1-v)) {
	    DLOG("throw1: t=", t, "v=", v);
	    throw Exc();
	  }
	  if (ex.at(t).at(v)) {
	    if (!(all.at(1-t).at(v) || ex.at(1-t).at(v))) {
	      mustFill.at(t).at(v) = true;
	    }
	  }
	}
      }
      for (ll t = 0; t < 2; t++) {
	for (ll v = 0; v < 2; v++) {
	  if (mustFill.at(t).at(v)) {
	    if (mustFill.at(1-t).at(1-v)) {
	      if (ex.at(1-t).at(1-v) <= 1) {
		DLOG("throw2: t=", t, "v=", v);
		throw Exc();
	      }
	    }else {
	      if (ex.at(1-t).at(1-v) == 0) {
		DLOG("throw3: t=", t, "v=", v);
		throw Exc();
	      }
	    }
	  }
	}
      }
      
      ll topH = -1, topV = -1;

      auto decide = [&](ll i, ll j) -> ull {
	ll vaH = opres(vspec(Horiz), i);
	ll vaV = opres(vspec(Vert), j);
	bool allH = ao(Horiz).at(i) != vaH;
	bool allV = ao(Vert).at(i) != vaV;
	if (allH) return vaH;
	if (allV) return vaV;
	if (vaH == vaV) return vaH;
	if (!mustFill.at(Horiz).at(vaH)) return vaV;
	if (!mustFill.at(Vert).at(vaV)) return vaH;
	if (topH == -1) topH = i;
	if (topV == -1) topV = j;
	return ((i == topH) == (j == topV)) ? 0 : 1;
      };

      for (ll i = 0; i < N; i++) {
	for (ll j = 0; j < N; j++) {
	  A.at(i).at(j) |= ((ull)(decide(i, j)) << z);
	}
      }

    }
    for (ll i = 0; i < N; i++) {
      for (ll j = 0; j < N; j++) {
	if (j > 0) cout << " ";
	cout << A.at(i).at(j);
      }
      cout << "\n";
    }
  }catch(const Exc& e) {
    cout << "-1\n";
  }

  return 0;
}

