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

struct MyException : exception {};

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
      vector<vector<int>> B(N, vector<int>(N, -1));

      auto setB = [&](ll i, ll j, ll v) -> void {
	if (B.at(i).at(j) >= 0 && B.at(i).at(j) != v) throw MyException();
	B.at(i).at(j) = v;
      };

      auto opres = [&](const auto& w, ll i) -> ll {
	return ((w.at(i) >> z) & 1);
      };

      DLOG("pt1, B=", B);

      for (ll i = 0; i < N; i++) {
	if (S.at(i) == 0 && opres(U, i) == 1) {
	  for (ll j = 0; j < N; j++) setB(i, j, 1);
	}
	if (S.at(i) == 1 && opres(U, i) == 0) {
	  for (ll j = 0; j < N; j++) setB(i, j, 0);
	}
      }
      for (ll j = 0; j < N; j++) {
	if (T.at(j) == 0 && opres(V, j) == 1) {
	  for (ll i = 0; i < N; i++) setB(i, j, 1);
	}
	if (T.at(j) == 1 && opres(V, j) == 0) {
	  for (ll i = 0; i < N; i++) setB(i, j, 0);
	}
      }
      for (ll i = 0; i < N; i++) {
	for (ll j = 0; j < N; j++) {
	  if (S.at(i) == 0 && opres(U, i) == 0
	      && T.at(j) == 0 && opres(V, j) == 0) setB(i, j, 0);
	  else if (S.at(i) == 1 && opres(U, i) == 1
		   && T.at(j) == 1 && opres(V, j) == 1) setB(i, j, 1);
	}
      }

      DLOG("pt2, B=", B);

      auto someJ = [&](ll i, ll v) -> bool {
	bool found = false;
	for (ll j = 0; j < N; j++) {
	  if (B.at(i).at(j) == v) {
	    found = true;
	    break;
	  }
	}
	if (!found) return false;
	for (ll j = 0; j < N; j++) {
	  if (B.at(i).at(j) == -1) setB(i, j, 1-v);
	}
	return true;
      };
      auto someI = [&](ll j, ll v) -> bool {
	bool found = false;
	for (ll i = 0; i < N; i++) {
	  if (B.at(i).at(j) == v) {
	    found = true;
	    break;
	  }
	}
	if (!found) return false;
	for (ll i = 0; i < N; i++) {
	  if (B.at(i).at(j) == -1) setB(i, j, 1-v);
	}
	return true;
      };
      vector<ll> tbsi, tbsj;
      for (ll i = 0; i < N; i++) {
	if ((S.at(i) == 0 && opres(U, i) == 0 && !someJ(i, 0))
	    || (S.at(i) == 1 && opres(U, i) == 1 && !someJ(i, 1))) {
	}
      }
      for (ll j = 0; j < N; j++) {
	if ((T.at(j) == 0 && opres(V, j) == 0 && !someI(j, 0))
	    || (T.at(j) == 1 && opres(V, j) == 1 && !someI(j, 1))) {
	  tbsj.push_back(j);
	}
      }
      for (ll i = 0; i < N; i++) {
	if ((S.at(i) == 0 && opres(U, i) == 0 && !someJ(i, 0))
	    || (S.at(i) == 1 && opres(U, i) == 1 && !someJ(i, 1))) {
	  tbsi.push_back(i);
	}
      }

      DLOG("pt3, B=", B);

      if (tbsi.size() > 0 || tbsj.size() > 0) {
	if ((tbsi.size() > 0 && tbsj.size() <= 1)
	    || (tbsi.size() <= 1 && tbsj.size() > 0)) throw MyException();
	for (ll p = 0; p < (ll)tbsi.size(); p++) {
	  for (ll q = 0; q < (ll)tbsj.size(); q++) {
	    ll i = tbsi.at(p);
	    ll j = tbsj.at(q);
	    B.at(i).at(j) = ((p == 0) == (q == 0)) ? 0 : 1;
	  }
	}
      }



      for (ll i = 0; i < N; i++) {
	for (ll j = 0; j < N; j++) {
	  ull b = B.at(i).at(j) == 1 ? 1 : 0;
	  A.at(i).at(j) |= (b << z);
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
  }catch(const MyException& e) {
    cout << "-1\n";
  }

  return 0;
}

