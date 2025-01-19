// SubtractImages.h
#ifndef SUBTRACTIMAGES_H
#define SUBTRACTIMAGES_H

#include "Matrix.h"

class SubtractImages {
public:
    SubtractImages(const Matrix& img1, const Matrix& img2, Matrix& result);
    void subtract();

private:
    const Matrix& image1;
    const Matrix& image2;
    Matrix& result;
};

#endif // SUBTRACTIMAGES_H
