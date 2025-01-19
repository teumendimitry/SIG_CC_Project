#include "Contrast.h"

Contrast::Contrast(Matrix& m, float f) : matrix(m), factor(f) {}

void Contrast::adjust() {
    int rows = matrix.getRows();
    int cols = matrix.getCols();
    int maxVal = 255; // Valeur maximale pour les pixels

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int pixel = matrix.get(i, j);
            // Ajustement du contraste
            pixel = static_cast<int>((pixel - 128) * factor + 128);
            // Limiter la valeur entre 0 et maxVal
            pixel = std::max(0, std::min(maxVal, pixel));
            matrix.set(i, j, pixel);
        }
    }
}
