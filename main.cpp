class Slice {
 public:
  int start = 0;
  int stop = 0;

  Slice(int start, int stop) : start{start}, stop{stop} {}
};

class Matrix {
 public:
  Matrix operator()(Slice row_slice, Slice col_slice) {
    return Matrix{};
  }

  Matrix operator[](Slice row_slice, Slice col_slice) {
    return Matrix{};
  }
};

int main() {
  Matrix mat;

  // Works on GCC, Clang, and MSVC
  mat({1, 2}, {2, 3});

#if 1
  // Works on GCC, Clang; fails on MSVC
  mat[{1, 2}, {2, 3}];
#else
  // Works on GCC, Clang, MSVC
  mat[Slice{1, 2}, Slice{2, 3}];
#endif
}
