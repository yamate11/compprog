#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(ipoint)

int main() {

  {
    IPoint p1(3, 5), p2(-2, 7);
    assert(p1 + p2 == IPoint(1, 12));
    assert(p1 - p2 == IPoint(5, -2));
    assert(3 * p1 == p1 * 3 && p1 * 3 == IPoint(9, 15));
    assert(p1.rotate() == p1.rotate(1) && p1.rotate(1) == IPoint(-5, 3));
    assert(p1.rotate(2) == p1.rotate(1).rotate(1) && p1.rotate(2) == IPoint(-3, -5));
    assert(p1.rotate(-1) == p1.rotate(3) && p1.rotate(-6) == p1.rotate(2));
    assert(p1.mirror_x() == IPoint(3, -5));
    assert(p1.mirror_y() == IPoint(-3, 5));
    assert(p1.mirror_x().mirror_y() == p1.rotate(2));
    assert(p1.parallel(IPoint(-6, -10)));
    assert(!p1.parallel(IPoint(6, 9)));
  }
  {
    stringstream ss1("5 -2 0 -9 1 80");
    IPoint p1, p2, p3; ss1 >> p1 >> p2 >> p3;
    assert(p1 == IPoint(5, -2));
    assert(p2 == IPoint(0, -9));
    assert(p3 == IPoint(1, 80));
    stringstream ss2;
    ss2 << p1 << " " << p2 << " " << p3;
    assert(ss2.str() == "(5, -2) (0, -9) (1, 80)");
  }
  {
    map<IPoint, ll> mp;
    mp[IPoint(2, -7)] = 99;
    auto it1 = mp.find(IPoint(2, -7));
    assert(it1 != mp.end() && it1->second == 99);
    auto it2 = mp.find(IPoint(5, 3));
    assert(it2 == mp.end());
    unordered_map<IPoint, ll> ump;
    ump[IPoint(4, -2)] = 50;
    auto it3 = ump.find(IPoint(4, -2));
    assert(it3 != ump.end() && it3->second == 50);
    auto it4 = ump.find(IPoint(5, 3));
    assert(it4 == ump.end());
  }

  {
    IPoint p00(0, 0), p0p(0, 2), p0n(0, -3), pp0(1, 0), pn0(-2, 0), p1(2, 3), p2(-3, 1), p3(-2, -5), p4(1, -4);
    vector<IPoint> vec{p0p, p0n, pp0, pn0, p1,   p2,   p3,   p4};
    vector<double> arg{0.5, 1.5, 0,   1,   0.25, 0.75, 1.25, 1.75};

    assert(not IPoint::lt_arg(p00, p00));
    for (const auto& p : vec) assert(not IPoint::lt_arg(p00, p));
    for (const auto& p : vec) assert(not IPoint::lt_arg(p, p00));
    for (size_t i = 0; i < vec.size(); i++) {
      for (size_t j = 0; j < vec.size(); j++) {
        assert(IPoint::lt_arg(vec[i], vec[j]) == (arg[i] < arg[j]));
      }
    }
  }

  cerr << "ok" << endl;
}
