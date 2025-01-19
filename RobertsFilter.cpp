
// RobertsFilter.cpp
#include "RobertsFilter.h"
#include <cmath>

RobertsFilter::RobertsFilter(const Matrix& inputImage, Matrix& outputImage)
    : inputImage(inputImage), outputImage(outputImage) {}

void RobertsFilter::applyKernel(int x, int y, int& gx, int& gy) {
    gx = 0;
    gy = 0;

    int kernelX[2][2] = {
        {1, 0},
        {0, -1}
    };

    int kernelY[2][2] = {
        {0, 1},
        {-1, 0}
    };

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int ni = x + i;
            int nj = y + j;

            if (ni >= 0 && ni < inputImage.getRows() && nj >= 0 && nj < inputImage.getCols()) {
                gx += inputImage.get(ni, nj) * kernelX[i][j];
                gy += inputImage.get(ni, nj) * kernelY[i][j];
            }
        }
    }
}

void RobertsFilter::apply() {
    int rows = inputImage.getRows();
    int cols = inputImage.getCols();

    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            int gx, gy;
            applyKernel(i, j, gx, gy);

            int magnitude = static_cast<int>(std::sqrt(gx * gx + gy * gy));
            magnitude = (magnitude > 255) ? 255 : magnitude;

            outputImage.set(i, j, magnitude);
        }
    }
}
