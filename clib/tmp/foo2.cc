template<typename T>
struct X {
  template<int p>
  void func(int) {}
};


template<typename T>
void bar() {
  X<T> x;
  x.template func<0>(1);
  // x0.func<0>(1);
  // x.func2<int>(1);
}


int main() {
  bar<int>();
  // X<int> x;
  // x.func<0>(1);
  // x.func2<int>(1);

  return 0;
}


