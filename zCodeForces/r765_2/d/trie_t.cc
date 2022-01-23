#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(trie)

// ---- inserted library file trie.cc

template <typename T, typename S = int>  
// T is char, int, ll, etc.
// S is the type of the count for each node.  S can be ll.
struct Trie {
  T from;
  int br_size;
  vector<pair<int, S>> nodes;

  Trie(T from_, T to_)
    : from(from_), br_size(to_ - from_ + 1) nodes({{-1, 0}}) {}

  template <bool create = true>
  int find_create(auto ts) {
    int idx = 0;
    for (int i = 0; i < (int)ts.size(); i++) {
      auto& [nidx, cnt] = nodes[idx];
      if (nidx < 0) {
        if (not create) return -1;
        nidx = nodes.size();
        for (int j = 0; j < br_size; j++) nodes.emplace_back(-1, 0);
      }
      idx = nidx + (ts[i] - from);
    }
    return idx;
  }

  int find(auto ts) { return find_create<false>(ts); }

  void add(auto ts, int num = 1) {
    int idx = find_create(ts);
    nodes[idx].second += num;
  }

};

ostream& operator<< (ostream& os, const Trie& trie) {
  for (ll i = 0; i < (ll)trie.nodes.size(); i++) {
    const auto& nd = trie.nodes[i];
    os << i << "(c:" << nd.cont << ",t:" << nd.term << ") " << nd.next << "\n";
  }
  return os;
}


// ---- end trie.cc

// @@ !! LIM -- end mark --


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    Trie trie('a', 'd');
    trie.insert(string("abcd"));
    trie.insert(string("abc"));
    trie.insert(string("acd"));
    trie.insert(string("ba"));
    DLOG(trie);

    assert(trie.nodes[0].cont == 4);

    ll idx = trie.index("ab");
    assert(trie.nodes[idx].cont == 2);
    assert(trie.nodes[idx].term == 0);
  }

  cout << "ok\n";
  return 0;
}
