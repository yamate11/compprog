#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(random)

// ---- inserted library file random.cc


struct Random {
  static random_device the_random_device;
  mt19937_64 rng;

  Random() : rng(the_random_device()) {}
  Random(unsigned seed) : rng(seed) {}
  
  ll range(ll i, ll j) {
    if (i >= j) {
      throw runtime_error("Random.range: invalid range");
    }
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  }

};

random_device Random::the_random_device;

// ---- end random.cc

// @@ !! LIM -- end mark --

template<typename T>
struct MyRope {
  struct node_t {
    T val;
    node_t* ch[2];
    int pri;
    int cnt;

    node_t(const T& v, ll p) : val(v), pri(p), cnt(1) { ch[0] = ch[1] = NULL; }
  };

  Random rand;
  node_t* root;
  MyRope() : rand(), root(NULL) {}

  int count(node_t* t) { return t ? t->cnt : 0; }
  
  node_t* update(node_t* t) {
    t->cnt = count(t->ch[0]) + count(t->ch[1]) + 1;
    return t;
  }

  node_t* rotate(node_t* t, int b) {
    node_t* s = t->ch[1 - b];
    t->ch[1 - b] = s->ch[b];
    s->ch[b] = t;
    update(t);
    update(s);
    return s;
  }

  node_t* node_insert(node_t* t, int k, const T& val, ll pri) {
    if (not t) return new node_t(val, pri);
    int c = count(t->ch[0]);
    int b = k > c;
    t->ch[b] = node_insert(t->ch[b], k - (b ? (c + 1) : 0), val, pri);
    update(t);
    if (t->pri < t->ch[b]->pri) t = rotate(t, 1 - b);
    return t;
  }

  node_t* node_erase(node_t* t) {
    if (not t->ch[0] and not t->ch[1]) return NULL;
    int b = not t->ch[0] ? 0 : not t->ch[1] ? 1 : t->ch[0]->pri < t->ch[1]->pri ? 0 : 1;
    node_t* s = rotate(t, b);
    node_erase(t);
    return update(s);
  }

  node_t* node_at(node_t* t, int k) {
    ll x = count(t->ch[0]);
    if (k < x) return node_at(t->ch[0], k);
    else if (x == k) return t;
    else return node_at(t->ch[1], k - x - 1);
  }

  void insert(int k, const T& val) { root = node_insert(root, k, val, rand.range(0, LLONG_MAX)); }
  
  T at(int k) { return node_at(root, k)->val; }
    
};


int main() {
  ll N; cin >> N;
  MyRope<ll> mr;
  REP(i, 0, N) {
    ll p; cin >> p; p--;
    mr.insert(p, i);
  }
  REP(i, 0, N) cout << mr.at(i) + 1 << " ";
  cout << endl;
  return 0;
}

