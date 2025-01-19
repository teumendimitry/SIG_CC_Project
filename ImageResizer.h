#ifndef IMAGERESIZER_H
#define IMAGERESIZER_H

#include "Matrix.h"

class ImageResizer {
private:
    Matrix& original; // Image originale

public:
    ImageResizer(Matrix& img);
    Matrix resize(int targetRows, int targetCols);
};

#endif // IMAGERESIZER_H
