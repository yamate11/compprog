#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mod cmpNaive)
// --> f:gcd mod cmpNaive
// ---- inserted function gcd from util.cc
// g = eGCD(a, b, s, t)  --->  sa + tb = g
ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u = 0;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

// gcd(0, x) = x, gcd(-x, y) = gcd(x, y)
ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(abs(a), abs(b), dummy1, dummy2);
}
// ---- end gcd
// ---- inserted library file mod.cc

ll MOD = 1e9 + 7;
// ll MOD = 998244353;

struct Fp {
  ll val;

  ll _calc_from_ll(ll t = 0) {
    if      (t >= MOD)  return t % MOD;
    else if (t >= 0)    return t;
    else if (t >= -MOD) return t + MOD;
    else {
      ll v = t % MOD;
      if (v == 0) return 0;
      else        return v + MOD;
    }
  }

  Fp(ll t = 0) : val(_calc_from_ll(t)) {}
  Fp(const Fp& t) : val(t.val) {}
  Fp& operator =(const Fp& t) { val = t.val; return *this; }
  Fp& operator =(ll t) { val = _calc_from_ll(t); return *this; }
  Fp& operator =(int t) { val = _calc_from_ll(t); return *this; }

  Fp& operator +=(const Fp& t) {
    val += t.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  Fp& operator -=(const Fp& t) {
    val -= t.val;
    if (val < 0) val += MOD;
    return *this;
  }

  Fp& operator *=(const Fp& t) {
    val = (val * t.val) % MOD;
    return *this;
  }

  Fp inv() const {
    if (val == 0) {
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    ll u = 0;
    ll v = 0;
    eGCD(val, MOD, u, v);
    return Fp(u);
  }

  Fp& operator /=(const Fp& t) {
    return (*this) *= t.inv();
  }

  Fp operator +(const Fp& t) const { return Fp(val) += t; }
  Fp operator -(const Fp& t) const { return Fp(val) -= t; }
  Fp operator *(const Fp& t) const { return Fp(val) *= t; }
  Fp operator /(const Fp& t) const { return Fp(val) /= t; }
  Fp operator -() const { return Fp(-val); }

  bool operator ==(const Fp& t) const { return val == t.val; }
  bool operator !=(const Fp& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

Fp operator +(int x, const Fp& y) { return Fp(x) + y; }
Fp operator -(int x, const Fp& y) { return Fp(x) - y; }
Fp operator *(int x, const Fp& y) { return Fp(x) * y; }
Fp operator /(int x, const Fp& y) { return Fp(x) / y; }
Fp operator +(ll x, const Fp& y) { return Fp(x) + y; }
Fp operator -(ll x, const Fp& y) { return Fp(x) - y; }
Fp operator *(ll x, const Fp& y) { return Fp(x) * y; }
Fp operator /(ll x, const Fp& y) { return Fp(x) / y; }
Fp operator +(const Fp& x, int y) { return x + Fp(y); }
Fp operator -(const Fp& x, int y) { return x - Fp(y); }
Fp operator *(const Fp& x, int y) { return x * Fp(y); }
Fp operator /(const Fp& x, int y) { return x / Fp(y); }
Fp operator +(const Fp& x, ll y) { return x + Fp(y); }
Fp operator -(const Fp& x, ll y) { return x - Fp(y); }
Fp operator *(const Fp& x, ll y) { return x * Fp(y); }
Fp operator /(const Fp& x, ll y) { return x / Fp(y); }

istream& operator>> (istream& is, Fp& t) {
  ll x; is >> x;
  t = x;
  return is;
}

ostream& operator<< (ostream& os, const Fp& t) {
  os << t.val;
  return os;
}

class Comb {
  int nMax;
  vector<Fp> vFact;
  vector<Fp> vInvFact;
public:
  Comb(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact.at(0) = 1;
    for (int i = 1; i <= nMax; i++) vFact.at(i) = i * vFact.at(i-1);
    vInvFact.at(nMax) = vFact.at(nMax).inv();
    for (int i = nMax; i >= 1; i--) vInvFact.at(i-1) = i * vInvFact.at(i);
  }
  Fp fact(int n) { return vFact.at(n); }
  Fp comb(int n, int r) {
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
  // The number of permutation extracting r from n.
  Fp perm(int n, int r) {
    return vFact.at(n) * vInvFact.at(n-r);
  }
};

// ---- end mod.cc
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

// ---- end cmpNaive.cc
// @@ !! LIM  -- end mark --


int naive(istream& cin, ostream& cout) {
  ll N, K; cin >> N >> K;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);

  ll vmax = LLONG_MIN;
  auto chk = [&](const auto& rF, ll prod, ll num, ll i) -> void {
    if (num == K) {
      vmax = max(vmax, prod);
      return;
    }
    if (i == N) return;
    rF(rF, prod * A.at(i), num + 1, i + 1);
    rF(rF, prod, num, i+1);
  };
  chk(chk, 1, 0, 0);
  Fp ans = Fp(vmax);
  cout << ll(ans) << endl;
  return 0;
}

int body(istream& cin, ostream& cout) {

  ll N, K; cin >> N >> K;
  vector<ll> A(N);
  vector<ll> pos;
  vector<ll> neg;

  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    A.at(i) = a;
    if (a >= 0) pos.push_back(a);
    else        neg.push_back(-a);
  }
  if (N == K) {
    ll sign = 1;
    Fp prod = 1;
    for (ll i = 0; i < N; i++) {
      prod *= abs(A.at(i));
      if (A.at(i) < 0) sign = -sign;
    }
    if (sign < 0) prod = -prod;
    cout << prod << endl;
    return 0;
  }
  ll numPos = pos.size();
  ll numNeg = neg.size();
  sort(pos.begin(), pos.end(), greater<ll>());
  sort(neg.begin(), neg.end(), greater<ll>());
  if (numNeg == N && K % 2 == 1) {
    reverse(neg.begin(), neg.end());
    Fp prod = 1;
    for (ll i = 0; i < K; i++) {
      prod *= neg.at(i);
    }
    prod = -prod;
    cout << prod << endl;
    return 0;
  }

  Fp prod = 1;
  ll j;
  if (K % 2 == 0) {
    j = 0;
    prod = 1;
  }else {
    j = 1;
    prod = pos.at(0);
  }
  ll i = 0;
  while (i + j < K) {
    if (j + 1 >= numPos) {
      prod *= neg.at(i);
      prod *= neg.at(i + 1);
      i += 2;
    }else if (i + 1 >= numNeg) {
      prod *= pos.at(j);
      prod *= pos.at(j + 1);
      j += 2;
    }else if (neg.at(i) * neg.at(i + 1) > pos.at(j) * pos.at(j + 1)) {
      prod *= neg.at(i);
      prod *= neg.at(i + 1);
      i += 2;
    }else {
      prod *= pos.at(j);
      prod *= pos.at(j + 1);
      j += 2;
    }
  }
  cout << prod << endl;

  return 0;
}

