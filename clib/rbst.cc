#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  RBST
  Randomized Binary Search Tree

  This implementation is fairly slow.  Around 40% slower than PBDS.

  Usage:
  RBST<T> ss;
  bool b = ss.insert(t);      // returs true successfully inserted
  bool b = ss.erase(t);       // returs true successfully erased
  T t = ss.at(i);             // The ith element from the smallest
                              //   equivalent to *os.find_by_order(i) in PBDS
  int i = ss.lb_idx(t);       // The number of elments smaller than t
                              //   equivalent to os.order_of_key(t) in PBDS

 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()    ---- rbst.cc

template <typename T>
struct RBST {

  static random_device rd;
  static mt19937 rng;
  static int randrange(int i, int j) {
    uniform_int_distribution<int> dist(i, j - 1);
    return dist(rng);
  }

  struct Node {
    Node* left;
    Node* right;
    int size;
    T val;

    Node() : left(nullptr), right(nullptr), size(1), val() {}
    Node(const T& val_) : left(nullptr), right(nullptr), size(1), val(val_) {}
    Node(Node* left_, Node* right_, int size_, const T& val_) : left(left_), right(right_), size(size_), val(val_) {}
    ~Node() {
      if (left) delete left;
      if (right) delete right;
    }

    void _push() {}

    void _update() { size = _size_s(left) + _size_s(right) + 1; }

    static int _size_s(Node* p) { return p ? p->size : 0; }

    static int _lb_idx_s(Node* p, const T& v) { return p ? p->lb_idx(v) : 0; }
    int lb_idx(const T& v) const { return val < v ? _size_s(left) + 1 + _lb_idx_s(right, v) : _lb_idx_s(left, v); }
    
    static int _ub_idx_s(Node* p, const T& v) { return p ? p->ub_idx(v) : 0; }
    int ub_idx(T v) const { return v < val ? _ub_idx_s(left, v) : _size_s(left) + 1 + _ub_idx_s(right, v); }

    static bool _member_s(Node* p, const T& v) { return p ? p->member(v) : false; }
    bool member(const T& v) const {
      if (v < val) return _member_s(left, v);
      else if (val < v) return _member_s(right, v);
      else return true;
    }

    T at(int k) const {
      int lsz = _size_s(left);
      if (k < lsz) return left->at(k);
      k -= lsz;
      if (k == 0) return val;
      return right->at(k - 1);
    }

    static Node* _insert_s(Node* p, const T& v, bool decided) {
      if (not p) return new Node(v);
      return p->insert(v, decided);
    }
    Node* insert(const T& v, bool decided) {
      if (not decided and RBST::randrange(0, size + 1) == 0) decided = true;
      if (v < val) {
        Node* p = _insert_s(left, v, decided);
        if (not p) return nullptr;
        if (decided) {
          left = p->right;
          p->right = this;
          _update();
          p->_update();
          return p;
        }else {
          left = p;
          _update();
          return this;
        }
      }else if (val < v) {
        Node* p = _insert_s(right, v, decided);
        if (not p) return nullptr;
        if (decided) {
          right = p->left;
          p->left = this;
          _update();
          p->_update();
          return p;
        }else {
          right = p;
          _update();
          return this;
        }
      }else {
        return nullptr;
      }
    }

    static pair<Node*, Node*> _erase_s(Node* p, const T& v) {
      if (not p) return {nullptr, nullptr};
      return p->erase(v);
    }
    pair<Node*, Node*> erase(const T& v) {
      if (v < val) {
        auto [p, deleted] = _erase_s(left, v);
        if (not deleted) return {this, nullptr};
        left = p;
        _update();
        return {this, deleted};
      }else if (val < v) {
        auto [p, deleted] = _erase_s(right, v);
        if (not deleted) return {this, nullptr};
        right = p;
        _update();
        return {this, deleted};
      }else {
        Node* p = _merge_s(left, right);
        left = nullptr;
        right = nullptr;
        return {p, this};
      }
    }

    static Node* _merge_s(Node* p, Node* q) {
      if (not p) return q;
      if (not q) return p;
      ll n = _size_s(p);
      ll m = _size_s(q);
      if (RBST::randrange(0, n + m) < n) {
        Node* r = _merge_s(p->right, q);
        p->right = r;
        p->_update();
        return p;
      }else {
        Node* r = _merge_s(p, q->left);
        q->left = r;
        q->_update();
        return q;
      }
    }

    /*
    static Node* merge(Node* l, Node* r) {
      if (not l) return r;
      if (not r) return l;
      l->_push(); r->_push();
      if (Node::randrange(0, l->size + r->size) < l->size) {
        l->right = merge(l->right, r);
        l->_update();
        return l;
      }else {
        r->left = merge(l, r->left);
        r->_update();
        return r;
      }
    }

    using pnn = pair<Node*, Node*>;
    pnn split_base(optional<const T&> v, int k) {
      if ((not v) and (k < 0 or size <= k)) throw new runtime_error("Node.split: k is out of range");
      _push();
      if (not left) return right->split_base(v, k);
      if (not right) return left->split_base(v, k);
      if ((v and (not val < *v)) or k <= left->size) {
        auto [l1, r1] = left->split_base(v, k);
        left = r1;
        _update();
        return pnn(l1, this);
      } else {
        auto [l1, r1] = right->split_base(v, k - left->size - 1);
        right = l1;
        _update();
        return pnn(this, r1);
      }
    }

    // returns [0, k) and [k, N)
    prr split(int k) { return _split_base(nullopt, k); }
    */

#if DEBUG
    pair<string, int> show(int seq) const {
      stringstream ss;
      int seq0 = seq;
      string ptr_l = "null", ptr_r = "null";
      if (left) {
        ptr_l = to_string(seq + 1);
        string exp_l;
        tie(exp_l, seq) = left->show(seq + 1);
        ss << exp_l;
      }
      if (right) {
        ptr_r = to_string(seq + 1);
        string exp_r;
        tie(exp_r, seq) = right->show(seq + 1);
        ss << exp_r;
      }
      ss << seq0 << ": [left: " << ptr_l << ", right: " << ptr_r << ", size: " << size << ", val: " << val << "]\n";
      return {ss.str(), seq};
    }

    int depth() {return max(left ? left->depth() + 1 : 0, right ? right->depth() + 1 : 0);}
    double a_depth() {
      if (not left and not right) return 1.0;
      if (not left) return (1 + right->a_depth()) * right->size / (right->size + 1);
      if (not right) return (1 + left->a_depth()) * left->size / (left->size + 1);
      return ((1 + left->a_depth()) * left->size + (1 + right->a_depth()) * right->size) / (left->size + right->size + 1);
    }

#else
    string show(int seq) const { return ""; }
    int depth() { return 0; }
    double a_depth() { return 0.0; }
#endif

  };

  Node* node;

  RBST() : node(nullptr) {}
  RBST(const T& v) { node = new Node(v); }
  ~RBST() { if (node) delete node; }
  
  int size() const { return Node::_size_s(node); }
  int lb_idx(const T& v) const { return Node::_lb_idx_s(node, v); }
  int ub_idx(const T& v) const { return Node::_ub_idx_s(node, v); }
  T at(int k) const {
    if (k < 0 or size() <= k) throw new runtime_error("RBST.at: k is out of range");
    return node->at(k);
  }
  bool member(const T& v) const { return Node::_memeber_s(node, v); }
  bool insert(const T& v) {
    Node* p = Node::_insert_s(node, v, false);
    if (not p) return false;
    node = p;
    return true;
  }
  bool erase(const T& v) {
    if (not node) return false;
    auto [p, deleted] = Node::_erase_s(node, v);
    if (not deleted) return false;
    node = p;
    delete deleted;
    return true;
  }

#if DEBUG
  string show() const {
    if (not node) return "(empty)";
    auto [s, i] = node->show(1);
    return s;
  }
#else
  string show() const { return ""; }
#endif

  friend ostream& operator<<(ostream& os, const RBST& r) { return os << r.show(); }
};

template <typename T> random_device RBST<T>::rd;
template <typename T> mt19937 RBST<T>::rng(RBST<T>::rd());

// @@ !! END ---- rbst.cc
