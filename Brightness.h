#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include "Matrix.h"

class Brightness {
private:
    Matrix& matrix; // R�f�rence � la matrice � ajuster
    int threshold; // Seuil de luminosit�

public:
    Brightness(Matrix& m, int t); // Constructeur
    void adjust(); // M�thode pour ajuster la luminosit�
};

#endif // BRIGHTNESS_H
