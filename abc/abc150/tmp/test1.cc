#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define VEC1T(type) vector<type>
#define VEC2T(type) vector<VEC1T(type)>
#define VEC3T(type) vector<VEC2T(type)>
#define VEC4T(type) vector<VEC3T(type)>
#define VEC1D(type, name, n1, init) name(n1, init)
#define VEC2D(type, name, n1, n2, init) name(n1, VEC1(type, , n2, init))
#define VEC3D(type, name, n1, n2, n3, init) \
  name(n1, VEC2(type, , n2, n3, init))
#define VEC4D(type, name, n1, n2, n3, n4, init)	\
  name(n1, VEC3(type, , n2, n3, n4, init))
#define VEC1(type, name, n1, init) VEC1T(type) VEC1D(type, name, n1, init)
#define VEC2(type, name, n1, n2, init) \
  VEC2T(type) VEC2D(type, name, n1, n2, init)
#define VEC3(type, name, n1, n2, n3, init) \
  VEC3T(type) VEC3D(type, name, n1, n2, n3, init)
#define VEC4(type, name, n1, n2, n3, n4, init)	\
  VEC4T(type) VEC4D(type, name, n1, n2, n3, n4, init)

using Vec1 = vector<ll>;
using Vec2 = vector<Vec1>;
using Vec3 = vector<Vec2>;
using Vec4 = vector<Vec3>;


int main() {
  ll N = 10;
  VEC4(ll, vec, N, N, N, N, -1);
  vec.at(0).at(1).at(2).at(3) = 50;
  cout << vec.at(0).at(1).at(2).at(3) << endl;
  Vec4 w(N, Vec3(N, Vec2(N, Vec1(N, -1))));
  w.at(0).at(1).at(2).at(3) = 70;
  cout << w.at(0).at(1).at(2).at(3) << endl;
  cout << w.at(5).at(1).at(2).at(3) << endl;
  
			 
}
