#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

typedef pair<int, int> Pair;

int main(int argc, char *argv[]) {

  set<Pair> sp;
  sp.insert(make_pair(5, 2));
  sp.insert(make_pair(3, 7));
  for (auto p : sp) {
    cout << p.first << " " << p.second << endl;
  }

}

    
