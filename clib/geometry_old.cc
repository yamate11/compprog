#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Utility functions for geometry
      using complex<double>

  Note: line (v,u) means that the direction vector is v and 
        point u is on the line.

  on_a_line(err, z1, z2, z3) 
      Checks if three points are on a line
  line_inter(v1, u1, v2, u2) 
      Returns the intersection points of two lines (v1,u1) and (v2,u2)
  circumcenter(z1, z2, z3)
      Circumcenter (外心) of three points.
      Should not be called if they are on a line.
  perpend_foot(v, u, p)
      The foot of perpendicular (垂線の足) from point p to line (v,u).
  dist_line_pt(v, u, p)
      The distance between line (v,u) and point p.

 */


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- geometry.cc

template<typename T>
constexpr complex<T> imunit = complex<T>(0, 1);

template<typename T>
bool on_a_line(T err, const complex<T>& z1, const complex<T>& z2,
	       const complex<T>& z3) {
  complex<T> v1 = z1 - z3;
  complex<T> v2 = z2 - z3;
  return abs(v1.real() * v2.imag() - v1.imag() * v2.real()) < err;
}

template<typename T>
complex<T> conjdiff(const complex<T>& z1, const complex<T>& z2) {
  return z1 * conj(z2) - conj(z1) * z2;
}

// Intersection of two lines, using a real parameter t
//    z = v1 t + u1
//    z = v2 t + u2
template<typename T>
complex<T> line_inter(const complex<T>& v1, const complex<T>& u1,
		      const complex<T>& v2, const complex<T>& u2) {
  return conjdiff(u1 - u2, v1) / conjdiff(v2, v1) * v2 + u2;
}

// circumcenter --- 外心
template<typename T>
complex<T> circumcenter(const complex<T>& z1, const complex<T>& z2,
			const complex<T>& z3) {
  return line_inter((z1 - z3) * imunit<T>, (z1 + z3) / T(2),
		    (z2 - z3) * imunit<T>, (z2 + z3) / T(2));
}

// Foot of perpendicular --- 垂線の足
//   Line : z = v t + u   (t: real parameter)
//   Point: p
template<typename T>
complex<T> perpend_foot(const complex<T>& v, const complex<T>& u,
			const complex<T>& p) {
  return line_inter(v * complex<T>(0, 1), p, v, u);
}

// Distance between a line and a point
//   Line : z = v t + u  (t: real parameter)
//   Point: p
template<typename T>
T dist_line_pt(const complex<T>& v, const complex<T>& u,
			const complex<T>& p) {
  return abs(p - perpend_foot(v, u, p));
}

using Complex = complex<double>;

// @@ !! END ---- geometry.cc

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  
  Complex z1(0.0, 0.0), z2(5.0, 0.0), z3(3.0, 4.0), z4(0.0, 2.0),
    z5(2.0, 2.0), z6(6.0, 8.0), z7(-1.0, 12.0), z8(-2.0, 2.0), z9(6.0, 10.0),
    z10(3.0, 2.0), z11(1.0, 2.0), z12(4.0, 6.0), z13(-4.0, 2.0),
    z14(-3.0, -1.0), z15(2.0, 0.0), z16(1.0, sqrt(3.0)),
    z17(1.0, sqrt(3.0) / 3.0), z18(-1.0, 1.0);

  assert(on_a_line(1e-6, z1, z3, z6));
  assert(on_a_line(1e-6, z2, z3, z7));
  assert(on_a_line(1e-6, z3, z7, z2));
  assert(on_a_line(1e-6, z7, z2, z3));
  assert(on_a_line(1e-6, z3, z5, z3));
  assert(! on_a_line(1e-6, z2, z3, z4));
  assert(! on_a_line(1e-6, z4, z1, z7));
  assert(! on_a_line(1e-6, z3, z5, z7));
  assert(line_inter(z3, z4, z5, z8) == z9);
  assert(line_inter(z4, z3, z2, z5) == z10);
  assert(circumcenter(z12, z13, z14) == z11);
  assert(abs(circumcenter(z1, z15, z16) - z17) < 1e-6);
  assert(abs(perpend_foot(z5, z4, z1) - z18) < 1e-6);
  assert(abs(dist_line_pt(z3, z2, z11) - 4.4) < 1e-6);

  cout << "Test done." << endl;

}
