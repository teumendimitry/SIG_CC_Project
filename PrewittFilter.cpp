// PrewittFilter.cpp
#include "PrewittFilter.h"
#include "Matrix.h"
#include <cmath>

PrewittFilter::PrewittFilter(const Matrix& inputImage, Matrix& outputImage)
    : inputImage(inputImage), outputImage(outputImage) {}

void PrewittFilter::applyKernel(int x, int y, int& gx, int& gy) {
    gx = 0;
    gy = 0;

    // Masque de Prewitt
    int kernelX[3][3] = {
        {-1, 0, 1},
        {-1, 0, 1},
        {-1, 0, 1}
    };

    int kernelY[3][3] = {
        {-1, -1, -1},
        {0, 0, 0},
        {1, 1, 1}
    };

    // Itérer sur le noyau
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int ni = x + i;
            int nj = y + j;

            // Vérifier si nous sommes dans les limites de l'image
            if (ni >= 0 && ni < inputImage.getRows() && nj >= 0 && nj < inputImage.getCols()) {
                gx += inputImage.get(ni, nj) * kernelX[i + 1][j + 1];
                gy += inputImage.get(ni, nj) * kernelY[i + 1][j + 1];
            }
        }
    }
}

void PrewittFilter::apply() {
    int rows = inputImage.getRows();
    int cols = inputImage.getCols();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int gx, gy;
            applyKernel(i, j, gx, gy);

            // Calculer la magnitude du gradient
            int magnitude = static_cast<int>(std::sqrt(gx * gx + gy * gy));
            // Assurer que la valeur est entre 0 et 255
            magnitude = (magnitude > 255) ? 255 : magnitude;

            outputImage.set(i, j, magnitude);
        }
    }
}
