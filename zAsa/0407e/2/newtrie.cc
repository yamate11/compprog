#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

struct Trie {

  struct TrNode {
    vector<int> _next;
    int _parent;
    bool exist;
    TrNode(int sz = 0, int _parent_ = -1) : _next(sz, -1), _parent(_parent_), exist(false) {}
  };

  char from;
  int br_size;
  vector<TrNode> nodes;

  Trie(char from_, char to_)
    : from(from_), br_size(to_ - from_ + 1), nodes(1, TrNode(br_size)) {}

  int index(const string& s, bool create = false) {
    int idx = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      auto& nxt = nodes[idx]._next;
      int c = s[i] - from;
      if (nxt[c] < 0) {
        if (not create) return -1;
        nodes.emplace_back(br_size, idx);
        idx = nodes.size() - 1;
        nxt[c] = idx;
      }else {
	idx = nxt[c];
      }
    }
    return idx;
  }

  int insert(const string& s) {
    int idx = _index(s, true);
    nodes[idx].exist = true;
    return idx;
  }

  bool erase(int idx) {
    bool ret = nodes[idx].exist;
    nodes[idx].exist = false;
    return ret;
  }

  bool erase(const string& s) {
    int idx = _index(s, false);
    if (idx < 0) return false;
    return erase(idx);
  }

  int parent(int idx) { return nodes[idx]._parent; }

  int child(int idx, char c) { return nodes[idx]._next[c - from]; }

};


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  return 0;
}
