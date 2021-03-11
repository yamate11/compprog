#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()
// --> 
// @@ !! LIM  -- end mark --

struct STNode {
  ll val;
  STNode* lolo;
  STNode* lohi;
  STNode* hilo;
  STNode* hihi;

  STNode() : val(0), lolo(0), lohi(0), hilo(0), hihi(0) {}

  ll n_query(ll left1, ll right1, ll left2, ll right2,
             ll l1, ll r1, ll l2, ll r2) {
    if (right1 <= l1 || r1 <= left1 || right2 <= l2 || r2 <= left2) {
      return 0;
    }
    if (left1 <= l1 && r1 <= right1 && left2 <= l2 && r2 <= right2) {
      return val;
    }
    ll m1 = (l1 + r1) / 2;
    ll m2 = (l2 + r2) / 2;
    auto sub = [&](STNode* nd, ll x1, ll y1, ll x2, ll y2) -> ll {
      if (!nd) return 0;
      return nd->n_query(left1, right1, left2, right2, x1, y1, x2, y2);
    };
    ll vlolo = sub(lolo, l1, m1, l2, m2);
    ll vlohi = sub(lohi, l1, m1, m2, r2);
    ll vhilo = sub(hilo, m1, r1, l2, m2);
    ll vhihi = sub(hihi, m1, r1, m2, r2);
    return vlolo + vlohi + vhilo + vhihi;
  };

  void n_update(ll x1, ll x2, ll v,
                ll l1, ll r1, ll l2, ll r2) {
    if (l1 + 1 == r1 && l2 + 1 == r2) {
      assert(l1 == x1 && l2 == x2);
      val = v;
    }else {
      ll m1 = (l1 + r1) / 2;
      ll m2 = (l2 + r2) / 2;
      using pt_t = STNode*;
      auto sub = [&](pt_t& nd, ll t1, ll s1, ll t2, ll s2) -> void {
        if (!nd) nd = new STNode();
        nd->n_update(x1, x2, v, t1, s1, t2, s2);
      };
      if (x1 <  m1 && x2 <  m2) sub(lolo, l1, m1, l2, m2);
      if (x1 <  m1 && x2 >= m2) sub(lohi, l1, m1, m2, r2);
      if (x1 >= m1 && x2 <  m2) sub(hilo, m1, r1, l2, m2);
      if (x1 >= m1 && x2 >= m2) sub(hihi, m1, r1, m2, r2);
      auto eval = [&](pt_t nd) -> ll { return nd ? nd->val : 0; };
      val = eval(lolo) + eval(lohi) + eval(hilo) + eval(hihi);
    }
  }
};

struct SegTree {
  ll lbnd1;
  ll rbnd1;
  ll lbnd2;
  ll rbnd2;
  STNode* top;

  ll query(ll left1, ll right1, ll left2, ll right2) {
    return top->n_query(left1, right1, left2, right2,
                        lbnd1, rbnd1, lbnd2, rbnd2);
  }

  void update(ll x1, ll x2, ll v) {
    top->n_update(x1, x2, v,
                  lbnd1, rbnd1, lbnd2, rbnd2);
  }

  SegTree(ll lb1, ll rb1, ll lb2, ll rb2)
    : lbnd1(lb1), rbnd1(rb1), lbnd2(lb2), rbnd2(rb2) {
    top = new STNode();
  }
};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  SegTree st(1, n + 1, 1, n + 1);
  vector<ll> A(n + 1);
  vector<set<ll>> pos(n + 1, {0, n + 1});
  for (ll i = 1; i <= n; i++) {
    ll a; cin >> a;
    A[i] = a;
    pos[a].insert(i);
  }
  vector<ll> prev(n + 1, -1), next(n + 1, -1), rec(n + 1, -1);
  for (ll i = 1; i <= n; i++) {
    ll c = A[i];
    if (rec[c] >= 0) {
      st.update(i, rec[c], i - rec[c]);
      next[rec[c]] = i;
      prev[i] = rec[c];
    }
    rec[c] = i;
  }
  for (ll _q = 0; _q < m; _q++) {
    ll ty; cin >> ty;
    if (ty == 1) {
      ll p, x; cin >> p >> x;
      ll old_x = A[p];
      if (x == old_x) continue;
      ll opr = prev[p];
      ll onx = next[p];
      if (opr >= 0) {
        st.update(p, opr, 0);
        if (onx >= 0) {
          st.update(onx, p, 0);
          st.update(onx, opr, onx - opr);
          prev[onx] = opr;
          next[opr] = onx;
        }else {
          next[opr] = -1;
        }
      }else {
        if (onx >= 0) {
          st.update(onx, p, 0);
          prev[onx] = -1;
        }
      }
      next[p] = prev[p] = -1;
      pos[old_x].erase(p);
      auto it1 = pos[x].lower_bound(p);
      ll nx = *it1--;
      ll pr = *it1;
      if (nx <= n && pr >= 1) {
        st.update(nx, pr, 0);
      }
      if (nx <= n) {
        st.update(nx, p, nx - p);
        next[p] = nx;
        prev[nx] = p;
      }
      if (pr >= 1) {
        st.update(p, pr, p - pr);
        prev[p] = pr;
        next[pr] = p;
      }
      A[p] = x;
      pos[x].insert(p);
    }else if (ty == 2) {
      ll l, r; cin >> l >> r;
      ll v = st.query(l, r + 1, l, n + 1);
      cout << v << "\n";
    }
  }

  return 0;
}

