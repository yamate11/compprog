#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(mypair)

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    mypair<ll, ll> mp1;
    assert(mp1._1 == 0 and mp1._2 == 0);
    pll mp2(5, 10);
    assert(mp2._1 == 5 and mp2._2 == 10);
    pll mp3{5, 10};
    assert(mp2 == mp3);
    pll mp4(mp2);
    assert(mp3 == mp4);
    pair<ll, ll> mp5(5, 10);
    pll mp6(mp5);
    assert(mp3 == mp6);
    assert(mp3 == pll(mp5));
    assert(mp2 == mp6 and not (mp2 != mp6) and not (mp2 < mp6) and not (mp2 > mp6) and mp2 <= mp6 and mp2 >= mp6);
    pll mp7(7, 3);
    assert(not (mp2 == mp7) and mp2 != mp7 and mp2 < mp7 and not (mp2 > mp7) and mp2 <= mp7 and not (mp2 >= mp7));
    assert(not (mp7 == mp2) and mp7 != mp2 and not (mp7 < mp2) and mp7 > mp2 and not (mp7 <= mp2) and mp7 >= mp2);
    pll mp8(5, 20);
    assert(not (mp2 == mp8) and mp2 != mp8 and mp2 < mp8 and not (mp2 > mp8) and mp2 <= mp8 and not (mp2 >= mp8));
    assert(not (mp8 == mp2) and mp8 != mp2 and not (mp8 < mp2) and mp8 > mp2 and not (mp8 <= mp2) and mp8 >= mp2);
    pll mp9;
    mp9 = mp8;
    assert(mp9 == mp8);
  }
  {
    ll x = 1, y = 2;
    // testing the (const A&, const B&) version of the constructors
    mypair<ll, ll> mp1(x, y); 
    assert(mp1._1 == 1 and mp1._2 == 2);
  }
  {
    stringstream s1("25 30 -3 -6"), s2(""), s3("");
    pll mp1, mp2;
    s1 >> mp1 >> mp2;
    assert(mp1 == pll(25, 30) and mp2 == pll(-3, -6));
    s2 << mp1 << mp2;
    assert(s2.str() == "(25, 30)(-3, -6)");
    s3 << mp1 + mp2;
    assert(s3.str() == "(22, 24)");
  }
  {
    pll mp1(5, 7);
    pll mp2(3, 4);
    pll mp3(1, 5);
    mp1 += mp2; assert(mp1 == pll(8, 11));
    mp1 -= mp2; assert(mp1 == pll(5, 7));
    mp1 += mp2 += mp3; assert(mp1 == pll(9, 16) and mp2 == pll(4, 9));
    pll mp4(2, -4);
    pll mp5(4, 1);
    pll mp6(5, 3);
    mp4 -= mp5 -= mp6; assert(mp4 == pll(3, -2) and mp5 == pll(-1, -2));
    pll mp7(4, 5);
    mp7 *= 10;
    assert(mp7 == pll(40, 50));
    mp7 /= 5;
    assert(mp7 == pll(8, 10));
  }
  { 
    pll mp1(5, 7), mp2(3, 4), mp3(1, 5);
    assert(mp1 + mp2 + mp3 == pll(9, 16));
    assert(-mp1 + mp1 == pll());
    assert(mp1 - mp2 - mp3 == pll(1, -2));
    assert(2 * mp1 == pll(10, 14) and mp1 * 2 == pll(10, 14));
    pll mp4(20, 15);
    assert(mp4 / 5 == pll(4, 3));
  }
  {
    pll mp1(1, -3);
    assert(mp1 == mp1.rotate(0));
    assert(mp1.rotate() == mp1.rotate(1));
    assert(mp1.rotate(1) == pll(3, 1));
    assert(mp1.rotate(2) == pll(-1, 3));
    assert(mp1.rotate(3) == pll(-3, -1));
    assert(mp1.rotate(-1) == mp1.rotate(3));
    assert(mp1.rotate(-7) == mp1.rotate(1));
  }
  {
    static ll count_noarg = 0, count_copy = 0, count_move = 0;
    struct S {
      S() { count_noarg++; }
      S(const S& o) { count_copy++; }
      S(S&& o) {  count_move++; }
    };
    using type1 = mypair<S, ll>;
    auto foo = [&]() -> type1 {
      S ret;
      return type1(move(ret), 0);
    };
    count_noarg = count_copy = count_move = 0;
    auto [s, x] = foo();
    x += 1;  // Just to supress a compiler warning that complains not using s and x.
    assert(count_noarg == 1 and count_copy == 0 and count_move == 1);
  }
  {
    pll mp1(5, 2), mp2(6, -8), mp3(-9, 12);
    assert(mp1.inner_prod(mp2) == 14);
    assert((not mp1.parallel(mp2)) and mp2.parallel(mp3) and (not mp1.parallel(mp3)));
  }


  return 0;
}

