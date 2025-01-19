// MeanFilter.cpp
#include "MeanFilter.h"

MeanFilter::MeanFilter(const Matrix& inputImage, Matrix& outputImage, int kernelSize)
    : inputImage(inputImage), outputImage(outputImage), kernelSize(kernelSize) {}

void MeanFilter::apply() {
    int rows = inputImage.getRows();
    int cols = inputImage.getCols();
    int halfKernel = kernelSize / 2;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int sum = 0;
            int count = 0;

            // Itérer sur le noyau
            for (int ki = -halfKernel; ki <= halfKernel; ++ki) {
                for (int kj = -halfKernel; kj <= halfKernel; ++kj) {
                    int ni = i + ki;
                    int nj = j + kj;

                    // Vérifier si nous sommes dans les limites de l'image
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        sum += inputImage.get(ni, nj);
                        count++;
                    }
                }
            }

            // Calculer la moyenne
            outputImage.set(i, j, sum / count);
        }
    }
}
