// GaussianFilter.h
#ifndef GAUSSIANFILTER_H
#define GAUSSIANFILTER_H

#include "Matrix.h"
#include <vector>

class GaussianFilter {
public:
    GaussianFilter(const Matrix& inputImage, Matrix& outputImage, int kernelSize, double sigma);
    void apply();

private:
    const Matrix& inputImage;
    Matrix& outputImage;
    int kernelSize;
    double sigma;

    void createGaussianKernel(std::vector<std::vector<double>>& kernel);
};

#endif // GAUSSIANFILTER_H
