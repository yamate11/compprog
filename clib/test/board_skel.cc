#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(board)

template<typename T>
bool same(const Board<T>& brdA, const Board<T>& brdB) {
  int nRA = brdA.numRows(), nRB = brdB.numRows(),
    nCA = brdA.numCols(), nCB = brdB.numCols();
  if (nRA != nRB || nCA != nCB
      || brdA.at(nRA, nCA) != brdB.at(nRB, nCB)) return false;
  for (ll r = 0; r < brdA.numRows(); r++) {
    for (ll c = 0; c < brdA.numCols(); c++) {
      if (brdA.at(r, c) != brdB.at(r, c)) return false;
    }
  }
  return true;
}

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
    Board<char> brd1(4, 5, '#');
    ss1 >> brd1;
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

  {
    Board<char> brd1(3, 4, '.');
    brd1.at(0, 0) = '#';
    assert(brd1.at(0, 0) == '#');

    Board<bool> brd2(3, 4, false);
    brd2.at(0, 0) = true;
    assert(brd2.at(0, 0));

    auto func3 = [&](Board<char>& brd3) -> void {
      brd3.at(0, 1) = '#'; 
      assert(brd3.at(0, 0) == '#');
    };

    auto func4 = [&](Board<bool>& brd4) -> void {
      brd4.at(0, 1) = '#'; 
      assert(brd4.at(0, 0));
    };

    auto func5 = [&](const Board<char>& brd5) -> void {
      // brd5.at(0, 1) = '#'; // compilation error
      assert(brd5.at(0, 0) == '#');
    };

    auto func6 = [&](const Board<bool>& brd6) -> void {
      // brd6.at(0, 1) = '#'; // compilation error
      assert(brd6.at(0, 0));
    };

    func3(brd1);
    func4(brd2);
    func5(brd1);
    func6(brd2);

    Board<char> brd7(brd1);
    Board<bool> brd8(brd2);
    Board<char> brd9 = brd1;
    Board<bool> brd10 = brd2;
    assert(same(brd7,brd1));
    assert(same(brd8,brd2));
    assert(same(brd9,brd1));
    assert(same(brd10,brd2));
  }
  {
    Board<char> brd0(3, 4, '@');
    stringstream("##.#\n...#\n.#..") >> brd0;
    Board<char> brd1(4, 3, '@');
    stringstream("#..\n#.#\n...\n##.\n") >> brd1;
    assert(same(brd0.transpose(), brd1));
    assert(same(brd0.transpose().transpose(), brd0));
    Board<char> brd2(3, 4, '@');
    stringstream(".#..\n...#\n##.#\n") >> brd2;
    assert(same(brd0.reverse_row(), brd2));
    Board<char> brd3(3, 4, '@');
    stringstream("#.##\n#...\n..#.\n") >> brd3;
    assert(same(brd0.reverse_col(), brd3));

    assert(same(brd0.rotate(0), brd0));
    Board<char> brdR1(4, 3, '@');
    stringstream("##.\n...\n#.#\n#..\n") >> brdR1;
    assert(same(brd0.rotate(1), brdR1));
    Board<char> brdR2(3, 4, '@');
    stringstream("..#.\n#...\n#.##\n") >> brdR2;
    // DLOGK(brd0);
    // DLOGK(brdR2);
    // DLOGK(brd0.rotate(1));
    assert(same(brd0.rotate(2), brdR2));
    Board<char> brdR3(4, 3, '@');
    stringstream("..#\n#.#\n...\n.##\n") >> brdR3;
    assert(same(brd0.rotate(3), brdR3));
    assert(same(brd0.rotate(-1), brdR3));
    assert(same(brd0.rotate(-5), brdR3));
    assert(same(brd0.rotate(7), brdR3));

    assert(same(brd0.transpose().rotate(0), brd1));
    assert(same(brd0.transpose().rotate(1), brdR3.transpose()));
    assert(same(brd0.transpose().rotate(2), brdR1.reverse_col()));
    assert(same(brd0.transpose().rotate(3), brd0.reverse_col()));
  }
  {
    Board<char> brd0(3, 4, '@');
    stringstream("##.#\n...#\n.#..") >> brd0;
    for (BrdIdx& bi : BoardRange(brd0)) {
      if (brd0.at(bi) == '#') brd0.at(bi) = '?';
    }
    stringstream sout;
    sout << brd0;
    assert(sout.str() == "??.?\n...?\n.?..");

    Board<bool> brd1(3, 4, false);
    brd1.at(1, 2) = true;
    for (BrdIdx& bi : BoardRange(brd1)) {
      if (bi.r == 1 && bi.c == 2) assert(brd1.at(bi) == true);
      else assert(brd1.at(bi) == false);
    }
  }


  cout << "Test done." << endl;

}
