// PrewittFilter.h
#ifndef PREWITTFILTER_H
#define PREWITTFILTER_H

#include "Matrix.h"

class PrewittFilter {
public:
    PrewittFilter(const Matrix& inputImage, Matrix& outputImage);
    void apply();

private:
    const Matrix& inputImage;
    Matrix& outputImage;

    void applyKernel(int x, int y, int& gx, int& gy);
};

#endif // PREWITTFILTER_H
