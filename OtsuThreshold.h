// OtsuThreshold.h
#ifndef OTSUTHRESHOLD_H
#define OTSUTHRESHOLD_H

#include "Matrix.h"

class OtsuThreshold {
public:
    OtsuThreshold(const Matrix& inputImage);
    int calculateThreshold();
    void applyThreshold(Matrix& outputImage);

private:
    const Matrix& inputImage;
    int histogram[256] = {0};
    int totalPixels = 0;

    void calculateHistogram();
};

#endif // OTSUTHRESHOLD_H
