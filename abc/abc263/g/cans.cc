#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <atcoder/mincostflow>
using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(sieve)

// ---- inserted function f:itrange from util.cc

struct ItRange {
  ll st;
  ll en;

  struct Itr {
    using iterator_category = input_iterator_tag;
    using value_type = ll;
    using difference_type = ptrdiff_t;
    using reference = value_type const&;
    using pointer = value_type const*;

    ll val;

    bool operator ==(const Itr& o) const { return val == o.val; }
    bool operator !=(const Itr& o) const { return val != o.val; }

    reference operator *() const { return val; }
    pointer operator ->() const { return &val; }

    Itr& operator ++() {
      val++;
      return *this;
    }
    Itr operator ++(int) {
      Itr const tmp(*this);
      ++*this;
      return tmp;
    }

  };

  using iterator = Itr;

  ItRange(ll v_start, ll v_end): st(v_start), en(v_end) {}
  Itr begin() { return Itr({st}); }
  Itr end() { return Itr({en}); }
};

#define ALLIR(a, b) ItRange(a, b).begin(), ItRange(a, b).end()

// Imitation to Python range operator....


// ---- end f:itrange

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

vector<pair<ll, int>> _prfac_sub(ll n, const auto& it_beg, const auto& it_end) {
  vector<pair<ll, int>> res;
  ll x = n;
  for (auto it = it_beg; it != it_end and *it * *it <= x; it++) {
    ll p = *it;
    int r = 0;
    while (x % p == 0) {
      x /= p;
      r++;
    }
    if (r > 0) res.push_back(make_pair(p, r));
  }
  if (x > 1) res.push_back(make_pair(x, 1));
  return res;
}

vector<pair<ll, int>> prfac(ll n) {
  ItRange itr(2, n + 1);
  return _prfac_sub(n, itr.begin(), itr.end());
}
vector<pair<ll, int>> prfac(ll n, const vector<int>& primes) {
  return _prfac_sub(n, primes.begin(), primes.end());
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
    List of divisors
      - getDivisors(n)
      - getDivisors(n, primes)
            primes should contain prime numbers at least up to sqrt(n)
    Note: the results are NOT sorted
 */

// _gdsub ... aux function used in getDivisors()
vector<ll> _gdsub(int i, auto fs) {
  if (i == (int)fs.size()) { return vector<ll>({1}); }
  auto part = _gdsub(i+1, fs);
  auto [p, r] = fs[i];
  ll pp = p;    // pp = p^m, for m \in [1, r]
  int partOrigLen = part.size();
  for (int m = 1; m <= r; m++) {
    for (int j = 0; j < partOrigLen; j++) part.push_back(pp * part[j]);
    pp *= p;
  }
  return part;
}

vector<ll> getDivisors(ll n) { return _gdsub(0, prfac(n)); }
vector<ll> getDivisors(ll n, const vector<int>& primes) { return _gdsub(0, prfac(n, primes)); }
vector<ll> getDivisorsDivSieve(ll n, const vector<int>& divSieve) { return _gdsub(0, prfacDivSieve(n, divSieve)); }

// ---- end sieve.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto primes = sieve(3200);

  ll N; cin >> N;
  vector<ll> A(N), B(N);
  REP(i, N) cin >> A[i] >> B[i];
  ll big = 1e18;
  mcf_graph<ll, ll> graph(2*N + 2);
  ll one = -1;
  ll one_edge = -1;
  REP(i, N) {
    graph.add_edge(2*i, 2*i + 1, B[i], (A[i] == 1 ? 1 : 0));
    if (A[i] % 2 == 0) {
      graph.add_edge(2*i + 1, 2*N + 1, big, 0);
    }else if (A[i] == 1) {
      one_edge = graph.add_edge(2*N, 2*i, big, 0);
      one = i;
    }else {
      graph.add_edge(2*N, 2*i, big, 0);
    }
  }
  REP(i, N) REP2(j, i + 1, N) {
    auto pr = prfac(A[i] + A[j]);
    if (SIZE(pr) == 1 and pr[0].second == 1) {
      ll odd, even;
      if (A[i] % 2 == 0) {
        odd = j; even = i;
      }else {
        odd = i; even = j;
      }
      graph.add_edge(2*odd + 1, 2*even, big, 0);
    }
  }
  auto [f, _] = graph.flow(2*N, 2*N + 1);
  if (one >= 0) {
    ll one_flow = graph.get_edge(one_edge).flow;
    f += (B[one] - one_flow) / 2;
  }
  cout << f << endl;

  return 0;
}

