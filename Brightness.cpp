#include "Brightness.h"

Brightness::Brightness(Matrix& m, int t) : matrix(m), threshold(t) {}

void Brightness::adjust() {
    int rows = matrix.getRows();
    int cols = matrix.getCols();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int pixel = matrix.get(i, j);
            pixel = std::min(255, std::max(0, pixel + threshold)); // Ajustement
            matrix.set(i, j, pixel);
        }
    }
}
