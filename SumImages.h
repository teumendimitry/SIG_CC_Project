#ifndef SUMIMAGES_H
#define SUMIMAGES_H

#include "Matrix.h"

class SumImages {
private:
    Matrix& image1; // Première image
    Matrix& image2; // Deuxième image
    Matrix& result; // Image résultante

public:
    SumImages(Matrix& img1, Matrix& img2, Matrix& res);
    void add();
};

#endif // SUMIMAGES_H
