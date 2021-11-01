#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

template<typename ForwardIt, typename MapFilt>
struct view {
  ForwardIt first;
  ForwardIt last;
  MapFilt mf;

  struct Itr {
    using iterator_category = forward_iterator_tag;
    using value_type = typename ForwardIt::value_type;
    using difference_type = typename ForwardIt::difference_type;
    using reference = typename ForwardIt::reference;
    using pointer = typename ForwardIt::pointer;

    view& the_view;
    ForwardIt cur;
    value_type val;
    

    bool operator ==(const Itr& o) const { return cur == o.cur; }
    bool operator !=(const Itr& o) const { return cur != o.cur; }

    reference operator *()  { return val; }
    pointer operator ->() const { return &val; }

    void forward() {
      while (cur != the_view.last) {
        optional<value_type> ot = the_view.mf(*cur);
        if (ot.has_value()) {
          val = ot.value();
          break;
        }
        ++cur;
      }
    }

    Itr& operator ++() {
      cur++;
      forward();
      return *this;
    }
    Itr operator ++(int) {
      Itr const tmp(*this);
      ++*this;
      return tmp;
    }

    Itr(view& the_view_, ForwardIt cur_) 
      : the_view(the_view_), cur(cur_) { forward(); }

  };

  view(ForwardIt first_, ForwardIt last_, MapFilt mf_)
    : first(first_), last(last_), mf(mf_) {}
  Itr begin() { return Itr(*this, first); }
  Itr end() { return Itr(*this, last); }

};


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> vec1 = {1, 2, 3, 4, 5};
  // ll x = accumulate(vec1.begin(), vec1.end(), 0LL);
  auto filt1 = [&](ll x) -> optional<ll> {
    if (x % 2 == 0) return optional<ll>(x * 10);
    else return nullopt;
  };
  view vvec(vec1.begin(), vec1.end(), filt1);
  for (auto x : vvec) {
    cout << x << endl; // 20, 40
  }

  return 0;
}
