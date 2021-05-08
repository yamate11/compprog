#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:<< f:perfmeas sieve)

// ---- inserted function f:<< from util.cc
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

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig) {
  deque<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop_front();
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

// ---- end f:<<

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// ---- inserted library file sieve.cc

// sieve(upto) returns the list of prime numbers up to upto.
//   Size: upto(1e8).size() ... 5.7e6,  upto(1e9).size() ... 5.1e7
//   Performance: upto(1e8) ... 0.7sec,   upto(1e9) ... 9.2sec
vector<int> sieve(int upto) {
  vector<int> res;
  vector<bool> tbl(upto+1);
  ll lim = (int)(sqrt((double)upto)) + 1;
  for (int x = 2; x <= upto; x++) {
    if (tbl[x]) continue;
    res.push_back(x);
    if (x <= lim) {
      for (int y = x * x; y <= upto; y += x) tbl[y] = true;
    }
  }
  return res;
}

vector<int> divisorSieve(int upto) {
  vector<int> tbl(upto+1);
  iota(tbl.begin(), tbl.end(), 0);
  ll lim = (int)(sqrt((double)upto)) + 1;
  for (int x = 2; x <= lim; x++) {
    if (tbl[x] < x) continue;
    for (int y = x * x; y <= upto; y += x) if (tbl[y] == y) tbl[y] = x;
  }
  return tbl;
}

/*
  Prime Factorization
    Two versions:
      - prfac(n)
      - prfac(n, primes)
            primes should contain prime numbers at least up to sqrt(n)
 */

const vector<int> dummy_primes;

vector<pair<ll, int>> prfac(ll n, const vector<int>& primes = dummy_primes) {
  vector<int> tmp_primes;
  if (primes.size() == 0) {
    tmp_primes = sieve((int)sqrt((double)n) + 1);
  }
  const vector<int>& prms = primes.size() == 0 ? tmp_primes : primes;

  vector<pair<ll, int>> res;
  ll x = n;
  for (ll p : prms) {
    if (x == 1)  break;
    if (p * p > x)  break;
    if (x % p != 0)  continue;
    int c = 1;
    x /= p;
    while (x % p == 0) {
      c += 1;
      x /= p;
    }
    res.push_back(make_pair(p, c));
  }
  if (x != 1)  res.push_back(make_pair(x, 1));
  return res;
}

vector<pair<int, int>> prfacDivSieve(int n, const vector<int>& divSieve) {
  vector<pair<int, int>> ret;
  int p = -1;
  int r = 0;
  while (n > 1) {
    int q = divSieve[n];
    if (p == q) {
      r++;
    }else {
      if (p > 0) ret.emplace_back(p, r);
      p = q;
      r = 1;
    }
    n /= p;
  }
  if (p > 0) ret.emplace_back(p, r);
  return ret;
}

/*
vector<pair<ll, int>> prfac(ll n) {
  return prfac(n, sieve((int)(sqrt((double)n)) + 1));
}
*/

/*
    List of divisors
      - getDivisors(n)
      - getDivisors(n, primes)
            primes should contain prime numbers at least up to sqrt(n)
    Note: the results are NOT sorted
 */

// gdsub ... aux function used in getDivisors()
vector<ll> gdsub(int i, int n, auto fs) {
  if (i == n) { return vector<ll>({1}); }
  auto part = gdsub(i+1, n, fs);
  ll p  = fs.at(i).first;
  int r = fs.at(i).second;
  ll pp = p;    // pp = p^m, for m \in [1, r]
  int partOrigLen = part.size();
  for (int m = 1; m <= r; m++) {
    for (int j = 0; j < partOrigLen; j++) {
      part.push_back(pp * part.at(j));
    }
    pp *= p;
  }
  return part;
}

vector<ll> getDivisors(ll n, const vector<int>& primes = dummy_primes) {
  auto fs = prfac(n, primes);
  return gdsub(0, fs.size(), fs);
}

vector<ll> getDivisorsDivSieve(ll n, const vector<int>& divSieve) {
  auto fs = prfacDivSieve(n, divSieve);
  return gdsub(0, fs.size(), fs);
}


// ---- end sieve.cc

// @@ !! LIM -- end mark --

int main() {

  {
    auto p = sieve(1000);
    assert(p.at(10) == 31);
    assert(p.at(100) == 547);
    auto p1 = sieve(547);
    assert(p1.at(100) == 547);
    auto t = prfac(4*5*49);
    assert(t.at(0).first == 2 && t.at(0).second == 2 &&
	   t.at(1).first == 5 && t.at(1).second == 1 &&
	   t.at(2).first == 7 && t.at(2).second == 2 &&
	   t.size() == 3);
    auto ds = getDivisors(4*5*49);
    sort(ds.begin(), ds.end());
    assert(ds.size() == 18 && ds.at(0) == 1 && ds.at(1) == 2 && ds.at(2) == 4
	   && ds.at(3) == 5 && ds.at(4) == 7 && ds.at(15) == 245 &&
	   ds.at(16) == 490 && ds.at(17) == 980);
    auto t2 = prfac(258141461878361);
    assert(t2.at(0).first ==  97 && t2.at(0).second == 2 &&
	   t2.at(1).first == 401 && t2.at(1).second == 1 &&
	   t2.at(2).first == 409 && t2.at(2).second == 3 &&
	   t2.size() == 3);
    auto ds2 = getDivisors(990728680597);
    sort(ds2.begin(), ds2.end());
    vector<ll> ds2A = {1, 9967, 9973, 9967*9967, 9967*9973, 9967LL*9967*9973};
    assert(ds2.size() == ds2A.size());
    for (size_t i = 0; i < ds2.size(); i++) assert(ds2.at(i) == ds2A.at(i));
  }

  {
    auto divSieve = divisorSieve(100000);
    vector<pair<int, int>> vec1({{3,1}, {7,2}});
    assert(prfacDivSieve(3*7*7, divSieve) == vec1);
    vector<pair<int, int>> vec2({{283,1}, {293,1}});
    // cout << prfacDivSieve(283*293, divSieve);
    assert(prfacDivSieve(283*293, divSieve) == vec2);
    assert(divSieve[283*293] == 283);
    assert(divSieve[5*1511] == 5);
    assert(divSieve[99991] == 99991);
  }

  {
    ll n = 1e5;
    auto primes = sieve(sqrt(n) + 1);
    auto divSieve = divisorSieve(n);
    for (ll i = 2; i <= n; i++) {
      auto pr1 = prfac(i, primes);
      auto pr2 = prfacDivSieve(i, divSieve);
      assert(pr1.size() == pr2.size());
      for (ll j = 0; j < (ll) pr1.size(); j++) {
	auto [p1, r1] = pr1[j];
	auto [p2, r2] = pr2[j];
	assert(p1 == p2 && r1 == r2);
      }
    }
  }
  {
    // performance
    ll n = 1e6;
    double t1 = get_time_sec();
    ll dummy = 0;
    auto primes = sieve(n);
    for (ll i = 2*n/3; i < n; i++) {
      auto pr = prfac(i, primes);
      dummy += pr.size();
    }
    double t2 = get_time_sec();
    auto divSieve = divisorSieve(n);
    for (ll i = 2*n/3; i < n; i++) {
      auto pr = prfacDivSieve(n, divSieve);
      dummy += pr.size();
    }
    double t3 = get_time_sec();
    cout << t2 - t1 << ", " << t3 - t2 << endl;
    cout << primes[0] << divSieve[0] << dummy << endl;
  }
  {
    ll n = 1e7;
    double t1 = get_time_sec();
    auto primes = sieve(ll(sqrt(n)) + 1);
    auto pr1 = prfac(n, primes);
    double t2 = get_time_sec();
    auto divSieve = divisorSieve(n);
    auto pr2 = prfacDivSieve(n, divSieve);
    double t3 = get_time_sec();
    cout << t2 - t1 << ", " << t3 - t2 << endl;
    assert(pr1.size() == pr2.size());
  }

  cerr << "OK\n";
}
