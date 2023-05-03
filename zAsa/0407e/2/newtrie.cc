#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


template<typename T>
struct Trie {

  struct TrNode {
    vector<int> _next;
    int _parent;
    T udata;
    TrNode(int sz = 0, int _parent_ = -1) : _next(sz, -1), _parent(_parent_), udata() {}
  };

  char from;
  int br_size;
  vector<TrNode> nodes;

  Trie(char from_, char to_)
    : from(from_), br_size(to_ - from_ + 1), nodes(1, TrNode(br_size)) {}

  int _index(const string& s) {
    int idx = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      auto& nxt = nodes[idx]._next;
      int c = s[i] - from;
      if (nxt[c] < 0) {
	nodes.emplace_back(br_size, idx);
	idx = nodes.size() - 1;
	nxt[c] = idx;
      }else {
	idx = nxt[c];
      }
    }
    return idx;
  }

  // If s is not in the trie, it will be inserted.
  TrNode& node(const string& s) {
    ll i = _index(s);
    return nodes[i];
  }
  
  TrNode& parent(const TrNode& nd) { return nodes[nd._parent]; }
  TrNode& child(const TrNode& nd, char c) { return nodes[nd._next[c - from]]; }

};


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  return 0;
}
