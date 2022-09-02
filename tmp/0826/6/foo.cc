#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;


template <typename T>
struct RBST {
  RBST* left;
  RBST* right;
  int size;
  T val;

  static random_device rd;
  static mt19937 rng;
  static int randrange(int i, int j) {
    uniform_int_distribution<int> dist(i, j - 1);
    return dist(rng);
  }

  RBST() : left(nullptr), right(nullptr), size(0), val(T()) {}
  RBST(const T& v) : left(nullptr), right(nullptr), size(1), val(v) {}
  
  void push() {}

  int getsize(RBST* p) const { return p ? p->size : 0; }

  void update() { size = getsize(left) + getsize(right) + 1; }
  
  int getlb(RBST* p, const T& v) const { return p ? p->lowerBound(v) : 0; }
  int lowerBound(const T& v) const { return val < v ? getsize(left) + 1 + getlb(right, v) : getlb(left, v); }

  int getub(RBST* p, const T& v) const { return p ? p->upperBound(v) : 0; }
  int upperBound(T v) const { return v < val ? getub(left, v) : getsize(left) + 1 + getub(right, v); }

  T at(int k) const {
    if (k < 0 or size <= k) throw runtime_exctpion("RBST.at: k is out of range");
    int lsz = getsize(left);
    if (k < lsz) return left->at(k);
    k -= lsz;
    if (k == 0) return val;
    return right->at(k - 1);
  }

  static RBST* merge(RBST* l, RBST* r) {
    if (not l) return r;
    if (not r) return l;
    l->push(); r->push();
    if (randrange(0, l->size + r->size) < l->size) {
      l->right = merge(l->right, r);
      l->update();
      return l;
    }else {
      r->left = merge(l, r->left);
      r->update();
      return r;
    }
  }

  using prr = pair<RBST*, RBST*>;
  prr split_base(optional<const T&> v, int k) {
    if ((not v) and (k < 0 or size <= k)) throw runtime_exctpion("RBST.split: k is out of range");
    push();
    if (not left) return right->split(v, k);
    if (not right) return left->split(v, k);
    if ((v and (not val < *v)) or k <= left->size) {
      auto [l1, r1] = left->split(v, k);
      left = r1;
      update();
      return prr(l1, this);
    } else {
      auto [l1, r1] = right->split(v, k - left->size - 1);
      right = l1;
      update();
      return prr(this, r1);
    }
  }

  // returns [0, k) and [k, N)
  prr split(int k) { return split_base(nullopt, k); }

  void insert(const T& v) {
    auto [l1, r1] = split_base(v, 0);
    return merge(merge(l1, new RBST(v)), r1);
  }

  void erase_idx(int k) {
    if (k < 0 or size <= k) throw runtime_exctpion("RBST.erase: k is out of range");
    auto [l1, m1] = split(k);
    auto [_, r1] = m1->split(1);
    return merge(l1, r1);
  }

  void erase_

};

template <typename T> random_device RBST<T>::rd;
template <typename T> mt19937 RBST<T>::rng(RBST<T>::rd());



int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  RBST<ll> t;

  return 0;
}
