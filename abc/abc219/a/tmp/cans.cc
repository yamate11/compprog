#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    using Pair = pair<int, int>;
    auto comp = [&](Pair x, Pair y) -> bool { 
      if (x.first != y.first) return x.first  < y.first;
      else                    return x.second > y.second;
    };
    priority_queue<Pair, vector<Pair>, decltype(comp)> pque(comp);

    pque.emplace(2, 1); pque.emplace(3, 5), pque.emplace(3, 9);
    Pair p;
    p = pque.top(); pque.pop(); assert(p == Pair(3, 5));
    p = pque.top(); pque.pop(); assert(p == Pair(3, 9));
    p = pque.top(); pque.pop(); assert(p == Pair(2, 1));
  
    {
      stringstream ss;
      ss << 100; assert(ss.str() == "100");
    }{
      stringstream ss; 
      ss << hex << 253 << uppercase << 254 << nouppercase << 255;
      ss << dec << 100;
      assert(ss.str() == "fdFEff100");
    }{
      stringstream ss;
      double x = 1.0 / 3.0;
      ss << x << " " << setprecision(20) << x;
      assert(ss.str() == "0.333333 0.33333333333333331483");
    }{
      stringstream ss, ss1;
      ss << setw(4) << 10 << "," << setw(4) << (int)1e8;
      assert(ss.str()  == "  10,100000000");
      ss1 << setfill('0') << setw(4) << 10 << "," << setw(4) << (int)1e8;
      assert(ss1.str() == "0010,100000000");
    }{
      stringstream ss1, ss2;
      // Almost all manipulator are sticky:
      ss1 << hex << 100 << " " << 200;
      assert(ss1.str() == "64 c8");
      // But setw() is an exception.
      ss2 << setw(4) << 5 << 6;
      assert(ss2.str() == "   56");
    }
  }

  {
    struct Exc : exception {};
    auto all_non_zero = [&](string s) -> bool {
      auto dfs = [&](auto f, size_t i) -> void {
        if (i == s.size()) return;
        if (s[i] == '0') throw Exc();
        f(f, i + 1);
      };
      try {
        dfs(dfs, 0);
        return true;
      }catch (const Exc& e) {
        return false;
      }
    };
    assert(all_non_zero("11111"));
    assert(! all_non_zero("11101101"));
  }

  {
    vector<int> vec({10, 2, 5, 7, 5, 2, 5});
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    assert(vec == vector<int>({2, 5, 7, 10}));
  }

  {
    auto comp = [&](int x, int y) -> bool {
      if (x % 2 != y % 2) return x % 2 < y % 2;
      else return x < y;
    };
    set<int, decltype(comp)> is(comp);
    is.insert(9);
    is.insert(8);
    is.insert(2);
    is.insert(1);
    stringstream ss;
    for (int t : is) ss << t;
    cout << ss.str() << endl;
  }
  {
    struct Comp {
      bool operator() (int x, int y) const {
        if (x % 2 != y % 2) return x % 2 < y % 2;
        else return x < y;
      }
    };
    set<int, Comp> is;
    is.insert(9);
    is.insert(8);
    is.insert(2);
    is.insert(1);
    stringstream ss;
    for (int t : is) ss << t;
    cout << ss.str() << endl;
  }
  
  {
    vector<int> vec({2, 4, 5, 5, 5, 6, 10, 12});
    auto itN = upper_bound(vec.begin(), vec.end(), 5);
    
    stringstream ss;
    for (auto itR = reverse_iterator<decltype(itN)>(itN);
         itR != vec.rend(); itR++) {
      ss << *itR;
    }
    assert(ss.str() == "55542");
  }

  {
    stringstream ss;
    multiset<int> is({2, 4, 5, 5, 5, 6, 10, 12});
    auto itN = is.upper_bound(5);
    for (auto itR = reverse_iterator<decltype(itN)>(itN);
         itR != is.rend(); itR++) {
      ss << *itR;
    }
    cout << ss.str() << endl;
    assert(ss.str() == "55542");
  }


  return 0;
}

