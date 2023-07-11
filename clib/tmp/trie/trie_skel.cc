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
    auto root = Trie<>::create_root('a', 'd');
    root->insert("abcd");
    root->insert("ac");
    root->insert("add");
    root->insert("add");
    auto p1 = root->getNode("abcd");
    assert(p1->exists(""));
    assert(root->getNum("abcd") == 1);
    assert(root->getNum("add") == 2);
    bool b1 = root->erase("add");
    assert(b1 and root->getNum("add") == 1);
    bool b2 = root->erase("add", 1000);
    assert(not b2 and root->getNum("add") == 0);
    auto p2 = root->getNode("");
    assert (root->info->from == 'a');
    assert (root->info->br_size == 4);
    assert (root->info->root == p2);
    auto p3 = root->getNode("abcdd");
    assert(not p3);
    auto p4 = root->getNode("abcdd", true);
    assert(p1->children[3] == p4);
    assert(p1->getNode("d") == p4);
    assert(p1->getNode('d') == p4);
    p4->addVal(2);
    assert(p4->num == 2);
    auto p6 = root->addVal("abcdd", -2);
    assert(p6 == p4 and p6->num == 0);
    auto p7 = root->insert("ccc");
    assert(p7->num == 1);
    root->insert("ccc", 3);
    assert(p7->num == 4);
    root->erase("ccc", 2);
    assert(p7->num == 2);
    bool b9 = root->erase("ccc", 10);
    assert(not b9 and p7->num == 0);
    auto p10 = root->insert("cdc");
    root->insert("cdca");
    root->insert("cdcaa");
    root->insert("cdcd");
    assert(p10->size == 4);
    assert(p7->node2str() == "ccc");
    auto vec1 = p10->sub_stringSet("cdc");
    auto vec2 = vector<string>{"cdc", "cdca", "cdcaa", "cdcd"};
    assert(vec1 == vec2);
    stringstream ss1, ss2;
    ss1 << *root;
    ss2 << root->stringSet();
    assert(ss1.str() == ss2.str());
  }



  cout << "ok\n";
  return 0;
}
