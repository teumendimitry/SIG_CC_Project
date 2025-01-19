#include "Threshold.h"

Threshold::Threshold(Matrix& m, int t) : matrix(m), threshold(t) {}

void Threshold::apply() {
    int rows = matrix.getRows();
    int cols = matrix.getCols();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int pixel = matrix.get(i, j);
            // Appliquer le seuillage
            pixel = (pixel >= threshold) ? 255 : 0; // Binarisation
            matrix.set(i, j, pixel);
        }
    }
}
