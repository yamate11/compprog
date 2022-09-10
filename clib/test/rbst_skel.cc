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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"


// @@ !! LIM(rbst)


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  if (1) {
    RBST<ll> t;
  
    t.insert(6);
    // DLOGK(t);
    t.insert(2);
    // DLOGK(t);
    t.insert(8);
    // DLOGK(t);
    t.insert(4);
    // DLOGK(t);
    t.insert(0);
    // DLOGK(t);
    assert(t.at(2) == 4);
    assert(t.at(4) == 8);
    assert(t.lb_idx(6) == 3);
    assert(t.lb_idx(7) == 4);
    assert(t.ub_idx(4) == 3);
    assert(t.ub_idx(5) == 3);
    assert(t.size() == 5);
    t.erase(4);
    assert(t.size() == 4);
    t.erase(6);
    assert(t.size() == 3);
    t.erase(0);
    assert(t.size() == 2);
    t.erase(2);
    assert(t.size() == 1);
    t.erase(8);
    assert(t.size() == 0);
  }
  
  if (0) {
    RBST<ll> t;
    REP(i, 0, 10000) t.insert(i);
    cout << t.node->depth() << endl;
    cout << t.node->a_depth() << endl;
    REP(i, 10000, 1000000) t.insert(i);
    cout << t.node->depth() << endl;
    cout << t.node->a_depth() << endl;
    REP(i, 0, 990000) t.erase(i);
    cout << t.node->depth() << endl;
    cout << t.node->a_depth() << endl;
  }

  /*
  if (0) {
    
    bool pbds = false, rbst = false, ordi = true;
    if (argc >= 2 and string(argv[1]) == "pbds") pbds = true;
    if (argc >= 2 and string(argv[1]) == "rbst") rbst = true;
    if (argc >= 2 and string(argv[1]) == "set") ordi = true;

    ordered_set os;
    RBST<ll> ss;
    set<ll> us;
    ll N; cin >> N;
    if (pbds) {
      REP(i, 0, N) {
        ll tp, x; cin >> tp >> x;
        if (tp == 1) {
          os.insert(x);
        }else if (tp == 2) {
          os.erase(x);
        }else if (tp == 3) {
          cout << os.order_of_key(x) << "\n";
        }else if (tp == 4) {
          cout << *os.find_by_order(x) << "\n";
        }
      }
    }
    if (rbst) {
      REP(i, 0, N) {
        ll tp, x; cin >> tp >> x;
        if (tp == 1) {
          ss.insert(x);
        }else if (tp == 2) {
          ss.erase(x);
        }else if (tp == 3) {
          cout << ss.lb_idx(x) << "\n";
        }else if (tp == 4) {
          cout << ss.at(x) << "\n";
        }
      }
    }
    if (ordi) {
      REP(i, 0, N) {
        ll tp, x; cin >> tp >> x;
        if (tp == 1) {
          us.insert(x);
        }else if (tp == 2) {
          us.erase(x);
        }else {
          cout << "Sorry, not implemented." << endl;
          exit(1);
        }
      }
    }
  }
  */

  return 0;
}
