#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(geometry)
// --> geometry
// ---- inserted library file geometry.cc

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

// ---- end geometry.cc
// @@ !! LIM  -- end mark --

using Complex = complex<double>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  double err = 1e-6;

  ll N; cin >> N;
  vector<Complex> z;
  for (ll i = 0; i < N; i++) {
    double x, y; cin >> x >> y;
    z.emplace_back(x, y);
  }

  auto check = [&](Complex c, double d) -> bool {
    for (ll i = 0; i < N; i++) {
      if (abs(z.at(i) - c) > d + err) return false;
    }
    return true;
  };

  double ans = 1e10;
  for (ll i = 0; i < N; i++) {
    for (ll j = i + 1; j < N; j++) {
      double d = abs(z.at(i) - z.at(j)) / 2;
      if (check((z.at(i) + z.at(j)) / 2.0, d)) ans = min(ans, d);
      for (ll k = j + 1; k < N; k++) {
	if (on_a_line(1e-10, z.at(i), z.at(j), z.at(k))) continue;
	Complex cc = circumcenter(z.at(i), z.at(j), z.at(k));
	double d2 = abs(cc - z.at(i));
	if (check(cc, d2)) ans = min(ans, d2);
      }
    }
  }
  cout << ans << endl;

  return 0;
}

