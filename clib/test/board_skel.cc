#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(board)

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  
  {
    stringstream ss1("..#..\n..#..\n....#\n.#...\n");
    /*
      ..#..
      ..#..
      ....#
      .#...
    */
    Board<char> brd1(ss1, 4, 5, '#');
    assert(brd1.get(0,0) == '.');
    assert(brd1.get(0,2) == '#');
    assert(brd1.get(-1,0) == '#');
    assert(brd1.get(4,4) == '#');
    assert(brd1.get(3,4) == '.');
    brd1.set(BrdIdx(2, 0), 'X');
    BrdIdx i(1,0);
    string tmp1;
    for (auto d : BrdIdx::nbr4) tmp1 += brd1.get(i + d);
    assert(tmp1 == "X..#");
  }

  {
    ll H2 = 5, W2 = 3;
    Board<ll> brd2(H2, W2, -1);
    for (ll r = 0; r < H2; r++) {
      for (ll c = 0; c < W2; c++) brd2.set(r, c, r + c);
    }
    BrdIdx i2(0, 0);
    ll sum2 = 0;
    for (BrdIdx ii = i2; brd2.get(ii) >= 0; ii += BrdIdx(1, 0)) {
      for (BrdIdx jj = ii; brd2.get(jj) >= 0; jj += BrdIdx(0, 1)) {
	sum2 += brd2.get(jj);
      }
    }
    assert(sum2 == 45);
  }

  {
    ll H = 3, W = 3;
    Board<ll> brd(H, W, -1);
    brd.at(1, 1) = 10;
    brd.set(-10, -10, 1000);
    assert(brd.at(-10, -10) == -1);
    assert(brd.at(-1, -1) == -1);
    brd.at(-10, -10) = 1000;
    assert(brd.get(-1, -1) == -1);
    try {
      brd.at(-1, -1);
      assert(0);
    }catch(const runtime_error& e) {
    }
    assert(brd.at(1, 1) == 10);
  }

  for (ll i = 0; i < 4; i++) {
    assert(BrdIdx::nbr4.at((i+1)%4) == BrdIdx::nbr4.at(i).rotateQ());
  }

  cout << "Test done." << endl;

}
