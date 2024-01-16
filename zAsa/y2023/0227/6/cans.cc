#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(mapget)

// ---- inserted library file mapget.cc

template<typename MP>
struct mgs : MP {
  using Key = typename MP::key_type;
  using T = typename MP::mapped_type;

  T def;

  mgs(const T& def_ = T()) : MP(), def(def_) {}
  mgs(const mgs& o) : MP(o), def(o.def) {}
  mgs(mgs&& o) : MP(move(o)), def(move(o.def)) {}
  mgs& operator =(const mgs& o) {
    MP::operator=(o);
    def = o.def;
    return *this;
  }
  mgs& operator =(mgs&& o) {
    MP::operator=(move(o));
    def = move(o.def);
    return *this;
  }

  const T& get(const Key& k) const {
    auto it = this->find(k);
    if (it == this->end()) return def;
    else return it->second;
  }

  template<typename T1>
  void set(const Key& k, T1&& t) {
    if (t == def) this->erase(k);
    else (*this)[k] = forward<T1>(t);
  }
};

// ---- end mapget.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;

  using myPair = pair<deque<char>, deque<char>>;
  deque<char> empqueue;
  mgs<map<myPair, ll>> mp_init(-1LL);
  vector tbl(N + 1, mp_init);
  auto func = [&](auto rF, ll n, myPair pp) -> ll {
    ll ret = tbl[n].get(pp);
    if (ret < 0) {
      auto [q1, q2] = pp;
      if (SIZE(q1) > n) {
        ret = 0;
      }else if (n == 0) {
        ret = 1;
      }else {
        ret = 0;
        ll c1 = S[N - n];
        ll c2 = S[2*N - 1 - (N - n)];
        if (q1.empty()) {
          assert(q2.empty());
          if (c1 == c2) ret += 2 * rF(rF, n - 1, pp);
          q2.push_back(c1); q1.push_back(c2);
          ret += 2 * rF(rF, n - 1, myPair(q1, q2));
        }else {
          assert(not q2.empty());
          if (q1.front() == c1 and q2.front() == c2) {
            q1.pop_front();
            q2.pop_front();
            ret += rF(rF, n - 1, myPair(q1, q2));
            q1.push_front(c1);
            q2.push_front(c2);
          }
          if (q1.front() == c1) {
            q1.pop_front();
            q1.push_back(c2);
            ret += rF(rF, n - 1, myPair(q1, q2));
            q1.pop_back();
            q1.push_front(c1);
          }
          if (q2.front() == c2) {
            q2.pop_front();
            q2.push_back(c1);
            ret += rF(rF, n - 1, myPair(q1, q2));
            q2.pop_back();
            q2.push_front(c2);
          }
          if (true) {
            q1.push_back(c2);
            q2.push_back(c1);
            ret += rF(rF, n - 1, myPair(q1, q2));
          }
        }
      }
      tbl[n].set(pp, ret);
    }
    return ret;
  };

  ll ans = func(func, N, myPair(empqueue, empqueue));
  cout << ans << endl;

  return 0;
}

