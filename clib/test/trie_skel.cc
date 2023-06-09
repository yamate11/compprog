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
    Trie<ll> trie('a', 'd');
    int i0 = trie.insert("abcd");
    trie.user(i0) = 0;
    int i1 = trie.insert("abc");
    trie.user(i1) = 1;
    int i2 = trie.insert("acd");
    trie.user(i2) = 2;
    int i3 = trie.insert("ba");
    trie.user(i3) = 3;
    assert((trie.to_vector_string() == vector<string>{"abc", "abcd", "acd", "ba"}));
    assert(trie.from == 'a');
    assert(trie.br_size == 4);
    trie.erase("abc");
    trie.user(i2) -= 2;
    trie.erase(i3);
    trie.user(i3) -= 3;
    DLOGK(trie.to_vector_string());
    assert((trie.to_vector_string() == vector<string>{"abcd", "acd"}));
    assert(trie.index("abc") == -1);
    assert(trie.index("ba") == -1);
    assert(trie.parent(i0) == i1);
    assert(trie.child(i1, 'd') == i0);
    assert(trie.exists(i0));
    assert(not trie.exists(i3));
    assert(trie.user(i1) == 1);
    assert(trie.user(i2) == 0);
  }
  {
    stringstream ss1;
    stringstream ss2;
    Trie trie('a', 'z');
    vector<string> vec{"xyz", "abcd", "a", "ae"};
    for (string s : vec) trie.insert(s);
    auto vec1 = vec;
    sort(vec1.begin(), vec1.end());
    ss1 << trie;
    ss2 << vec1;
    assert(ss1.str() == ss2.str());
  }

  cout << "ok\n";
  return 0;
}
