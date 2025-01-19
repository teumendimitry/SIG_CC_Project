#ifndef SUMIMAGES_H
#define SUMIMAGES_H

#include "Matrix.h"

class SumImages {
private:
    Matrix& image1; // Premi�re image
    Matrix& image2; // Deuxi�me image
    Matrix& result; // Image r�sultante

public:
    SumImages(Matrix& img1, Matrix& img2, Matrix& res);
    void add();
};

#endif // SUMIMAGES_H
