#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug rerror f:updMaxMin geometry)

bool pt_comp(const Point& a, const Point& b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

vector<Point> naive_convex_hull(const vector<Point>& o_pts) {
  vector<Point> spts(o_pts);
  sort(spts.begin(), spts.end(), pt_comp);
  vector<Point> pts;
  for (int i = 0; i < (int)spts.size(); i++) {
    if (i == 0 || !spts.at(i-1).sim(spts.at(i))) pts.push_back(spts.at(i));
  }

  unordered_set<int> inner;
  int n = pts.size();

  auto check2 = [&](int m) -> void {
    if (inner.find(m) != inner.end()) return;
    for (int i = 0; i < n; i++) {
      if (m == i) continue;
      if (inner.find(i) != inner.end()) continue;
      for (int j = i+1; j < n; j++) {
	if (m == j) continue;
	if (inner.find(j) != inner.end()) continue;
	Point q1 = pts.at(i) - pts.at(m);
	Point q2 = pts.at(j) - pts.at(m);
	if (!q1.parallel(q2)) continue;
	if (!may_eq(q1.x, 0.0)) {
	  if (q2.x / q1.x < 0) { inner.insert(m); return; }
	}else {
	  if (q2.y / q1.y < 0) { inner.insert(m); return; }
	}
      }
    }
  };

  auto check3 = [&](int m) -> void {
    if (inner.find(m) != inner.end()) return;
    for (int i = 0; i < n; i++) {
      if (m == i) continue;
      if (inner.find(i) != inner.end()) continue;
      for (int j = i+1; j < n; j++) {
	if (m == j) continue;
	if (inner.find(j) != inner.end()) continue;
	for (int k = j+1; k < n; k++) {
	  if (m == k) continue;
	  if (inner.find(k) != inner.end()) continue;
	  if (in_triangle(pts.at(m), pts.at(i), pts.at(j), pts.at(k))
	      != Line::SIDE_N) {
	    inner.insert(m);
	    return;
	  }
	}
      }
    }
  };
  for (int m = 0; m < n; m++) check2(m);
  for (int m = 0; m < n; m++) check3(m);
  vector<Point> ret;
  for (int m = 0; m < n; m++) {
    if (inner.find(m) == inner.end()) ret.push_back(pts.at(m));
  }
  return ret;
}

tuple<Real, int, int> naive_diameter(const vector<Point>& pts) {
  int n = pts.size();
  Real vmax = 0.0;
  int i0 = -1;
  int j0 = -1;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (updMax(vmax, (pts.at(i) - pts.at(j)).len())) {
	i0 = i;
	j0 = j;
      }
    }
  }
  return make_tuple(vmax, i0, j0);
}

mt19937 rng;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  
  {
    Point orig(0, 0), pux(1, 0), puy(0, 1);
    Point p01(3, 4), p02(-4, -3), p03(1, -2), p04(2, -1), p05(-1, 1);
    Point p06(0.0001, -0.0001), p07(-1e10, 1e10);

    assert(orig == orig);
    assert(pux != puy);
    assert(p01 + p02 == p05);
    assert(p02 - p03 == Point(-5, -1));
    assert(p04 * 3 == Point(6, -3));
    assert(2 * p04 == Point(4, -2));
    assert(Point(12, 16) / 4 == p01);
    assert(-p05 == Point(1, -1));
    assert(orig.sim(Point(1e-14, -1e-14)));
    assert(!orig.sim(pux));
    assert(orig.sim(Point(-0.01, 0.01), 0.1));
    assert(!orig.sim(p06));
    assert(p07.sim(p07+p06));
    assert(abs(p01.len() - 5) < g_err);
    assert(Point::polar(4, M_PI*2/3).sim(Point(-2, 2*sqrt(3))));
    assert(pux.rotate(M_PI/4).sim(Point(sqrt(2)/2, sqrt(2)/2)));
    assert(p03.rotate(-M_PI/2).sim(Point(-2, -1)));

    Line l01(pux + puy, orig), l02(p05, 2*puy);
    Line l03(p04, p01 + 4 * p04), l04(p02, p01 - 7 * p02);
    assert(!l01.parallel(l02));
    assert(l01.parallel(Line(l02.dir.rotateQ(), l02.base)));
    assert(l01.ptOn(Point(-3, -3)));
    assert(! l02.ptOn(p03));
    assert(l01.unsafe_intersect(l02).sim(Point(1,1)));
    assert(l03.unsafe_intersect(l04).sim(p01));
    assert(may_eq(l01.len(p01), sqrt(2)/2));
    assert(may_eq(Line(p01.rotateQ(), p01).len(orig), 5));
  
    Point p08(1, -2), p09(4, 2);
    Circle c01(p09, 2), c02(p08, 1), c03(p08, 4), c04(p08, 10);
    Line l05(p02, p09 + 3 * (p02/p02.len()).rotateQ());
    Line l06(p03, p09 + 1 * (p03/p03.len()).rotateQ());
    bool b; Point tmp_p1, tmp_p2;
    tie(b, tmp_p1, tmp_p2) = c01.intersect(l05);
    assert(!b);
    tie(b, tmp_p1, tmp_p2) = c01.intersect(l06);
    assert(b && l06.ptOn(tmp_p1) && c01.ptOn(tmp_p1)
	   && l06.ptOn(tmp_p2) && c01.ptOn(tmp_p2));
    tie(b, tmp_p1, tmp_p2) = c01.intersect(c02);
    assert(!b);
    tie(b, tmp_p1, tmp_p2) = c01.intersect(c04);
    assert(!b);
    tie(b, tmp_p1, tmp_p2) = c03.intersect(c01);
    assert(b && c01.ptOn(tmp_p1) && c03.ptOn(tmp_p1)
	   && c01.ptOn(tmp_p2) && c03.ptOn(tmp_p2));

    assert(circumcenter(Point(0,0), Point(2,0), Point(1,sqrt(3))
			).sim(Point(1, sqrt(3)/3)));
    assert(circumcenter(Point(4,5), Point(5,4), Point(-3,4)
			).sim(Point(1,1)));
  }

  {
    Point pt1(1,1), pt2(-2,3), dir1(1,2), dir2(3,2), ptC(4,7);
    Line l1(dir1, pt1), l2(dir2, pt2);
    auto [rc1, t11, t21] = l1.intersect_coeff(l2);
    assert(rc1 == Line::IST_ONE && ptC.sim(pt1 + t11 * dir1)
	   && ptC.sim(pt2 + t21 * dir2));
    Line l3(-dir1, pt1 + 4.0 * dir1);
    auto [rc3, t13, t23] = l1.intersect_coeff(l3);
    assert(rc3 == Line::IST_ALL);
    Line l4(-dir1, pt2);
    auto [rc4, t14, t24] = l1.intersect_coeff(l4);
    assert(rc4 == Line::IST_NONE);
  }

  {
    stringstream ss1("1.234 5.678"), ss2("-1000 -3000");
    Point p1, p2;
    ss1 >> p1;
    ss2 >> p2;
    assert(p1.sim(Point(1.234, 5.678)));
    assert(p2.sim(Point(-1000, -3000)));
    stringstream ss3, ss4, ss5, ss6;
    ss3 << p1;
    ss4 << p2;
    ss5 << Line(Point(10, -20), Point(-30, 40));
    ss6 << Circle(Point(-10, 20), 5);
    assert(ss3.str() == "(1.234, 5.678)");
    assert(ss4.str() == "(-1000, -3000)");
    assert(ss5.str() == "[d (10, -20), b (-30, 40)]");
    assert(ss6.str() == "[c (-10, 20), 5]");
  }

  {
    Point p10(7,2), p11(-3, 5);
    assert(may_eq(p10.innerProd(p11), -11));
    assert(may_eq(p11.innerProd(p10), -11));
    assert(may_eq(p10.outerProd(p11), 41));
    assert(may_eq(p11.outerProd(p10), -41));
    assert(may_eq(Point(1,1).angle(Point(-1,0)), G_PI*0.75));
    assert(may_eq(Point(-1,0).angle(Point(1,1)), -G_PI*0.75));
    for (ll i = 0; i < 20; i++) {
      Point p12 = p10.rotate(i*G_PI/10);
      assert(may_eq(p10.innerProd(p12),
		  p10.len() * p12.len() * cos(p10.angle(p12))));
      assert(may_eq(p10.outerProd(p12),
		  p10.len() * p12.len() * sin(p10.angle(p12))));
    }
  }

  {
    Point orig(0, 0), pux(1, 0), puy(0, 1);
    Line l01(pux + puy, orig);
    assert(l01.ptOn(Point(2,2)));
    assert(l01.ptSide(Point(3,2)) == Line::SIDE_N);
    assert(l01.ptSide(Point(3,4)) == Line::SIDE_P);
    Line l07(-(pux + puy), orig);
    assert(l07.ptSide(Point(3,3)) == Line::SIDE_ON);
    assert(l07.ptSide(Point(3,2)) == Line::SIDE_P);
    assert(l07.ptSide(Point(3,4)) == Line::SIDE_N);

    Point p13(2,2), p14(6,4), p15(4,8), p16(3,3), p17(5,6), p18(5,9),
      p19(10,6), p20(8,5), p21(14,8), p22(0,1), p23(4,3);
    assert(in_triangle(p16, p13, p14, p15) == Line::SIDE_P);
    assert(in_triangle(p17, p13, p14, p15) == Line::SIDE_ON);
    assert(in_triangle(p18, p13, p14, p15) == Line::SIDE_N);
    assert(in_triangle(p15, p13, p14, p15) == Line::SIDE_ON);
  }

  {
    // testing convex_hull and convex_diameter
    vector<Point> pts1 = {{0,0}, {2,0}, {2,2}, {0,2}, {1,1}, {0,1}, {2,1}};
    auto ch1 = convex_hull(pts1);
    assert(ch1 == vector<Point>({{0,0}, {2,0}, {2,2}, {0,2}}));
    assert(may_eq(get<0>(convex_diameter(ch1)), 2.0*sqrt(2.0)));

    vector<Point> pts2 = {{0,0}, {3,0}, {5,0}, {1,2}, {4,2}};
    auto ch2 = convex_hull(pts2);
    assert(ch2 == vector<Point>({{0,0}, {5,0}, {4,2}, {1,2}}));
    assert(may_eq(get<0>(convex_diameter(ch2)), 5.0));
  
    vector<Point> pts3 = {{0,5}, {1,4}, {1,8}, {2,1}, {2,2}, {3,5}, {3,8}, {4,5}};
    auto ch3 = convex_hull(pts3);
    assert(ch3 == vector<Point>({{0,5}, {2,1}, {4,5}, {3,8}, {1,8}}));

    vector<Point> pts4 = {{2,2}, {1,1}, {2,2}, {1,1}, {2,2}};
    auto ch4 = convex_hull(pts4);
    assert(ch4 == vector<Point>({{1,1}, {2,2}}));

    vector<Point> pts5 = {{2,2}, {2,2}, {2,2}};
    auto ch5 = convex_hull(pts5);
    assert(ch5 == vector<Point>({{2,2}}));
  
    rng.seed(time(0));
    // rng.seed(0);
  
    int repeat = 10000;
    int size1 = 10;
    int num = 5;
    uniform_int_distribution<int> dist(0, size1);
    for (int t = 0; t < repeat; t++) {
      vector<Point> pts;
      for (int i = 0; i < num; i++) {
	double x = dist(rng);
	double y = dist(rng);
	pts.emplace_back(x, y);
      }
      auto ch = convex_hull(pts);
      auto nch = naive_convex_hull(pts);
      double d, nd; int i, j, ni, nj;
      tie(d, i, j) = convex_diameter(ch);
      tie(nd, ni, nj) = naive_diameter(pts);
      vector<Point> chx(ch);
      vector<Point> nchx(nch);
      sort(chx.begin(), chx.end(), pt_comp);
      sort(nchx.begin(), nchx.end(), pt_comp);
      if (chx != nchx) {
	// DLOG("pts=", pts);
	// DLOG("ch=", ch);
	// DLOG("nch=", nch);
      }
      assert(chx == nchx);
      if (!may_eq(d, nd)) {
	// DLOG("pts=", pts);
	// DLOG("ch=", ch);
	// DLOG("d=", d, ch.at(i), ch.at(j));
	// DLOG("nd=", nd, pts.at(ni), pts.at(nj));
      }
      assert(may_eq(d, nd));
    }

    // end  (convex_hull and convex_diameter)
  }

  cout << "Test done." << endl;
}
