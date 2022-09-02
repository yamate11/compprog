struct A {
  A* a;
  int b;
  static A theA;
  A() : a(&A::theA), b(0) {}
  A(int bb) : a(nullptr), b(bb) {}
};
A A::theA(10);


int main() {
  A a1;
}
