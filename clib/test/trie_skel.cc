#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug trie)


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
