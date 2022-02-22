#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))


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

vector<pair<ll, int>> prfac1(ll n) {
  vector<pair<ll, int>> res;
  ll x = n;
  for (ll p = 2; x > 1 and p * p <= x; p++) {
    ll r = 0;
    while (x % p == 0) {
      x /= p;
      r++;
    }
    if (r > 0) res.push_back(make_pair(p, r));
  }
  if (x > 1) res.push_back(make_pair(x, 1));
  return res;
}

vector<pair<ll, int>> prfac(ll n, const vector<int>& primes) {
  vector<pair<ll, int>> res;
  ll x = n;
  for (ll p : primes) {
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

vector<pair<ll, int>> prfac2(ll n) {
  return prfac(n, sieve(llround(ceil(sqrt(double(n))))));
}


vector<pair<ll, int>> prfacDivSieve(int n, const vector<int>& divSieve) {
  vector<pair<ll, int>> ret;
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

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}


int main(int argc, char** argv) {

  random_device rd;
  mt19937_64 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };
  auto showms = [](double t, double s) -> ll { return llround(1'000'000 * (s - t)); };
  if (1) {
    ll m = 100;
    vector<double> ns = {1e5, 2e5, 5e5, 1e6, 2e6, 5e6, 1e7};
    for (double d : ns) {
      ll n = llround(d);
      vector<ll> td(m);
      vector<vector<vector<pair<ll, int>>>> chk(4, vector(m, vector<pair<ll, int>>()));
      REP(i, m) td[i] = randrange(1, n + 1);

      double t0 = get_time_sec();
      REP(i, m) chk[0][i] = prfac1(td[i]);
      double t1 = get_time_sec();
      REP(i, m) chk[1][i] = prfac2(td[i]);
      double t2 = get_time_sec();
      auto primes = sieve(llround(ceil(sqrt(d))));
      double t3 = get_time_sec();
      REP(i, m) chk[2][i] = prfac(td[i], primes);
      double t4 = get_time_sec();
      auto divSieve = divisorSieve(n);
      double t5 = get_time_sec();
      REP(i, m) chk[3][i] = prfacDivSieve(td[i], divSieve);
      double t6 = get_time_sec();

      REP(i, m) assert(chk[0][i] == chk[1][i]);
      REP(i, m) assert(chk[0][i] == chk[2][i]);
      REP(i, m) assert(chk[0][i] == chk[3][i]);

      /*
      cout << n << " " << showms(t0, t1) << " " << showms(t1, t2) << " " << showms(t2, t3)
           << " " << showms(t3, t4) << " " << showms(t4, t5) << " " << showms(t5, t6) << endl;
      */
    }
  }
    

  return 0;
  
}
