// LaplacianFilter.h
#ifndef LAPLACIANFILTER_H
#define LAPLACIANFILTER_H

#include "Matrix.h"

class LaplacianFilter {
public:
    LaplacianFilter(const Matrix& inputImage, Matrix& outputImage);
    void apply();

private:
    const Matrix& inputImage;
    Matrix& outputImage;

    void applyKernel(int x, int y, int& laplacianValue);
};

#endif // LAPLACIANFILTER_H
