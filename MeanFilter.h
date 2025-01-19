// MeanFilter.h
#ifndef MEANFILTER_H
#define MEANFILTER_H

#include "Matrix.h"

class MeanFilter {
public:
    MeanFilter(const Matrix& inputImage, Matrix& outputImage, int kernelSize);
    void apply();

private:
    const Matrix& inputImage;
    Matrix& outputImage;
    int kernelSize;
};

#endif // MEANFILTER_H
