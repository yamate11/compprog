#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


void foo() {
}

template<typename T, typename... Args>
void foo(T t, Args... args) {
  cout << t << endl;
  foo(args...);
}


int main() {

  foo(5, "hello", 3.21234132);
			 
}
