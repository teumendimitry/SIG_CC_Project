#ifndef CONTRAST_H
#define CONTRAST_H

#include "Matrix.h"

class Contrast {
private:
    Matrix& matrix; // R�f�rence � la matrice � ajuster
    float factor; // Facteur de contraste

public:
    Contrast(Matrix& m, float f);
    void adjust();
};

#endif // CONTRAST_H
