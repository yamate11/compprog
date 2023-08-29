#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:<< trie)

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    auto trie = create_trie('a', 'd');
    assert (trie.from == 'a');
    assert (trie.br_size == 4);

    int p1 = trie.insert("abcd");
    trie.insert("ac");
    trie.insert("add");
    trie.insert("add");
    assert(trie.num_string("abcd") == 1);
    assert(trie.num_string("add") == 2);
    trie.erase("add");
    assert(trie.num_string("add") == 1);
    trie.erase("add");
    assert(trie.num_string("add") == 0);
    int p2 = trie.string_index("");
    assert (p2 == 0);

    int p3 = trie.string_index("abcdd");
    assert(p3 < 0);
    int p4 = trie.string_index("abcdd", true);
    assert(trie.child_index(p1, 'd') == p4);
    assert(trie.parent_index(p4) == p1);
    assert(trie.prefixed_string_index(p1, "d") == p4);
    int p10 = trie.insert("cdc");
    trie.insert("cdca");
    trie.insert("cdcaa");
    trie.insert("cdcd");
    assert(trie.num(p10) == 1);
    assert(trie.size(p10) == 4);
    int p11 = trie.string_index("ddddaaadd");
    assert(trie.num(p11) == 0);
    assert(trie.size(p11) == 0);
  }
  {
    auto trie = create_trie('A', 'E');
    trie.insert("ABC");
    int p1 = trie.insert("ABD");
    int p2 = trie.insert("ABEAB");
    trie.insert("ABC");
    assert(trie.node_to_str(p1) == "ABD");
    assert(trie.node_to_str(p2) == "ABEAB");
    assert(trie.num_prefix("A") == 4);
    assert(trie.num_prefix("AB") == 4);
    assert(trie.num_prefix("ABE") == 1);
    auto vec1 = trie.string_set();
    auto vec2 = vector<string>{"ABC", "ABC", "ABD", "ABEAB"};
    assert(vec1 == vec2);
    stringstream ss1, ss2;
    ss1 << trie;
    ss2 << trie.string_set();
    assert(ss1.str() == ss2.str());
  }
  {
    assert(ull2binstr(10, 4) == "1010");
    assert(binstr2ull("10010") == 18);
  }

  cout << "ok\n";
  return 0;
}
