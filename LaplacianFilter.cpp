// LaplacianFilter.cpp
#include "LaplacianFilter.h"
#include <cmath>

LaplacianFilter::LaplacianFilter(const Matrix& inputImage, Matrix& outputImage)
    : inputImage(inputImage), outputImage(outputImage) {}

void LaplacianFilter::applyKernel(int x, int y, int& laplacianValue) {
    laplacianValue = 0;

    int kernel[3][3] = {
        {0, -1, 0},
        {-1, 4, -1},
        {0, -1, 0}
    };

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int ni = x + i;
            int nj = y + j;

            if (ni >= 0 && ni < inputImage.getRows() && nj >= 0 && nj < inputImage.getCols()) {
                laplacianValue += inputImage.get(ni, nj) * kernel[i + 1][j + 1];
            }
        }
    }
}

void LaplacianFilter::apply() {
    int rows = inputImage.getRows();
    int cols = inputImage.getCols();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int laplacianValue;
            applyKernel(i, j, laplacianValue);

            // Assurer que la valeur est entre 0 et 255
            laplacianValue = std::max(0, std::min(255, laplacianValue));
            outputImage.set(i, j, laplacianValue);
        }
    }
}
