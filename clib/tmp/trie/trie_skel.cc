#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug)

#include "./trie.cc"

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    Trie tr('a', 'd');
    tr.insert("abcd");
    tr.insert("ac");
    tr.insert("add");
    tr.insert("add");
    auto p1 = tr.getNode("abcd");
    assert(tr.num("abcd") == 1);
    assert(tr.num("add") == 2);
    tr.erase("add");
    assert(tr.num("add") == 1);
    tr.erase("add", 1000);
    assert(tr.num("add") == 0);
    auto p2 = tr.getNode("");
    assert (tr.from == 'a');
    assert (tr.br_size == 4);
    assert (tr.root == p2);
    auto p3 = tr.getNode("abcdd");
    assert(not p3);
    auto p4 = tr.getNode("abcdd", true);
    assert(p1->children[3] == p4);
    auto p5 = tr.changeVal(p4, 2);
    assert(p4 == p5 and p5->num == 2);
    auto p6 = tr.changeVal("abcdd", -2);
    assert(p6 == p4 and p6->num == 0);
    auto p7 = tr.insert("ccc");
    assert(p7->num == 1);
    tr.insert("ccc", 3);
    assert(p7->num == 4);
    auto p8 = tr.erase("ccc", 2);
    assert(p7 == p8 and p7->num == 2);
    auto p9 = tr.erase("ccc", 10);
    assert(not p9 and p7->num == 0);
    auto p10 = tr.insert("cdc");
    tr.insert("cdca");
    tr.insert("cdcaa");
    tr.insert("cdcd");
    assert(tr.numSubTree("cdc") == 4);
    assert(tr.node2str(p7) == "ccc");
    auto vec1 = tr.stringSet(p10, "cdc");
    auto vec2 = vector<string>{"cdc", "cdca", "cdcaa", "cdcd"};
    assert(vec1 == vec2);
    stringstream ss1, ss2;
    ss1 << tr;
    ss2 << tr.stringSet(tr.root, "");
    assert(ss1.str() == ss2.str());
  }



  cout << "ok\n";
  return 0;
}
