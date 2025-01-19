// GaussianFilter.cpp
#include "GaussianFilter.h"
#include <cmath>

GaussianFilter::GaussianFilter(const Matrix& inputImage, Matrix& outputImage, int kernelSize, double sigma)
    : inputImage(inputImage), outputImage(outputImage), kernelSize(kernelSize), sigma(sigma) {}

void GaussianFilter::createGaussianKernel(std::vector<std::vector<double>>& kernel) {
    int halfKernel = kernelSize / 2;
    double sum = 0.0;

    for (int x = -halfKernel; x <= halfKernel; ++x) {
        for (int y = -halfKernel; y <= halfKernel; ++y) {
            double value = std::exp(-(x * x + y * y) / (2 * sigma * sigma));
            kernel[x + halfKernel][y + halfKernel] = value;
            sum += value;
        }
    }

    // Normaliser le noyau
    for (int i = 0; i < kernelSize; ++i) {
        for (int j = 0; j < kernelSize; ++j) {
            kernel[i][j] /= sum;
        }
    }
}

void GaussianFilter::apply() {
    int rows = inputImage.getRows();
    int cols = inputImage.getCols();
    std::vector<std::vector<double>> kernel(kernelSize, std::vector<double>(kernelSize));
    createGaussianKernel(kernel);

    int halfKernel = kernelSize / 2;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double sum = 0.0;

            // Itérer sur le noyau
            for (int ki = -halfKernel; ki <= halfKernel; ++ki) {
                for (int kj = -halfKernel; kj <= halfKernel; ++kj) {
                    int ni = i + ki;
                    int nj = j + kj;

                    // Vérifier si nous sommes dans les limites de l'image
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        sum += inputImage.get(ni, nj) * kernel[ki + halfKernel][kj + halfKernel];
                    }
                }
            }

            // Assigner la valeur filtrée
            outputImage.set(i, j, static_cast<int>(sum));
        }
    }
}
