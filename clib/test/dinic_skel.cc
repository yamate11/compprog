#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(dinic)

int main() {

  {
    Dinic d1 = Dinic(2, 0, 1);
    d1.add_edge(0, 1, 10);
    assert(d1.run() == 10);
  }

  {
    Dinic d2 = Dinic(4, 0, 3);
    ll ei1 = d2.add_edge(0, 1, (ll)5e12);
    d2.add_edge(1, 3, (ll)2e12);
    d2.add_edge(0, 2, (ll)4e12);
    ll ei2 = d2.add_edge(2, 3, (ll)7e12);
    ll ei3 = d2.add_edge(0, 3, (ll)10e12);
    d2.add_edge(1, 2, 0);
    assert(d2.run() == (ll)16e12);
    assert(d2.eflow(ei1) == (ll)2e12);
    assert(d2.eflow(ei2) == (ll)4e12);
    assert(d2.eflow(ei3) == (ll)10e12);
  }

  {
    Dinic d3 = Dinic(5, 0, 4);
    d3.add_edge(0, 1, 10);
    d3.add_edge(0, 2, 2);
    d3.add_edge(1, 2, 6);
    d3.add_edge(1, 3, 6);
    d3.add_edge(3, 2, 3);
    d3.add_edge(2, 4, 5);
    d3.add_edge(3, 4, 8);
    assert(d3.run() == 11);
  }

  cerr << "OK\n";
  return 0;
}
