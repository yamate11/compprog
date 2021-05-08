#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(minCostFlow)


  
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    MinCostFlow mcf(5);
    mcf.add_edge(0, 1, 10, 2);
    mcf.add_edge(0, 2, 2, 4);
    mcf.add_edge(1, 2, 6, 6);
    mcf.add_edge(1, 3, 6, 2);
    mcf.add_edge(2, 4, 5, 2);
    mcf.add_edge(3, 2, 3, 3);
    mcf.add_edge(3, 4, 8, 6);
    ll c = mcf.run(0, 4, 9);
    assert(c == 80);
  }

  cout << "Test Done." << endl;
  return 0;
  
}
