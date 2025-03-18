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
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll lim = 2e5;
  ll N; cin >> N;
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  for (ll i = 0; i < N; i++) cin >> B[i];
  vector<ll> numA(lim + 1), numB(lim + 1);
  for (ll i = 0; i < N; i++) {
    numA[A[i]]++;
    numB[B[i]]++;
  }
  for (ll i = 1; i <= lim; i++) {
    if (numA[i] + numB[i] > N) {
      cout << "No\n";
      return 0;
    }
  }
  using sta = tuple<ll, ll, ll, ll>;
  using stb = pair<ll, ll>;
  vector<stb> freeA, freeB;
  priority_queue<sta> pque;
  for (ll i = 1; i <= lim; i++) {
    if (numA[i] == 0 && numB[i] == 0) continue;
    else if (numA[i] == 0) freeB.emplace_back(numB[i], i);
    else if (numB[i] == 0) freeA.emplace_back(numA[i], i);
    else pque.emplace(numA[i] + numB[i], numA[i], numB[i], i);
  }
  using stc = pair<ll, ll>;
  vector<stc> rec;
  while (!pque.empty()) {
    auto [nab, na, nb, i] = pque.top(); pque.pop();
    if (!pque.empty()) {
      auto [mab, ma, mb, j] = pque.top(); pque.pop();
      rec.emplace_back(i, j);
      if (na == 1) {
	freeB.emplace_back(nb, i);
      }else {
	pque.emplace(nab - 1, na - 1, nb, i);
      }
      if (mb == 1) {
	freeA.emplace_back(ma, j);
      }else {
	pque.emplace(mab - 1, ma, mb - 1, j);
      }
    }else {
      assert(!freeB.empty());
      ll k = freeB.size() - 1;
      auto [nn, ii] = freeB[k];
      rec.emplace_back(i, ii);
      if (nn == 1) freeB.resize(k);
      else freeB[k] = {nn - 1, ii};
      if (na == 1) {
	freeB.emplace_back(nb, i);
      }else {
	pque.emplace(nab - 1, na - 1, nb, i);
      }
    }
  }
  DLOG("rec=", rec, "freeA=", freeA, "freeB=", freeB);
  ll idxA = 0;
  ll idxB = 0;
  ll na, ia, nb, ib;
  tie(na, ia) = freeA[idxA];
  tie(nb, ib) = freeB[idxB];
  while (true) {
    while (na > 0 && nb > 0) {
      rec.emplace_back(ia, ib);
      na--; nb--;
    }
    if (na == 0) {
      idxA++;
      if (idxA == (ll)freeA.size()) break;
      tie(na, ia) = freeA[idxA];
    }
    if (nb == 0) {
      idxB++;
      tie(nb, ib) = freeB[idxB];
    }
    DLOG("idxA=", idxA, "idxB=", idxB, "na=", na, "nb=", nb);
  }
  sort(rec.begin(), rec.end());
  cout << "Yes\n";
  bool first = true;
  for (auto [i, j] : rec) {
    if (first) first = false;
    else cout << " ";
    cout << j;
  }
  cout << endl;

  return 0;
}

