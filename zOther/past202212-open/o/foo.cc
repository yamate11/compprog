#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <type_traits>

// Set, map, multiset用のバージョン
template <typename C, typename T>
auto foo_impl(const C& c, T x, int) -> decltype(c.lower_bound(x)) {
  std::cerr << "set version" << std::endl;
    return c.lower_bound(x);
}

// その他のコンテナ用のバージョン
template <typename C, typename T>
auto foo_impl(const C& c, T x, long) -> decltype(std::lower_bound(c.begin(), c.end(), x)) {
  std::cerr << "vector version" << std::endl;
    return std::lower_bound(c.begin(), c.end(), x);
}

// foo関数
template <typename C, typename T>
auto foo(const C& c, T x) {
    return foo_impl(c, x, 0);
}

int main() {
    std::set<int> s = {1, 2, 3, 4, 5};
    std::vector<int> v = {1, 2, 3, 4, 5};

    auto it_set = foo(s, 3);
    auto it_vec = foo(v, 3);

    if (it_set != s.end()) {
        std::cout << "Set lower_bound: " << *it_set << std::endl;
    } else {
        std::cout << "Set lower_bound: not found" << std::endl;
    }

    if (it_vec != v.end()) {
        std::cout << "Vector lower_bound: " << *it_vec << std::endl;
    } else {
        std::cout << "Vector lower_bound: not found" << std::endl;
    }

    return 0;
}
