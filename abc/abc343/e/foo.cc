#include <algorithm>

int main() {
  int x0 = 0, y0 = 0, z0 = 0;
  for (int x1 = -7; x1 < 8; x1++)
    for (int y1 = -7; y1 < 8; y1++)
      for (int z1 = -7; z1 < 8; z1++)
        for (int x2 = -7; x2 < 8; x2++)
          for (int y2 = -7; y2 < 8; y2++)
            for (int z2 = -7; z2 < 8; z2++)
              for (int _ = 0; _ < 3; _++) {
                std::swap(x0, x1);
                std::swap(x1, x2);
                std::swap(y0, y1);
                std::swap(y1, y2);
                std::swap(z0, z1);
                std::swap(z1, z2);
              }
}
