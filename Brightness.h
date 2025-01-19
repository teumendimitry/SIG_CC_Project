#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include "Matrix.h"

class Brightness {
private:
    Matrix& matrix; // Référence à la matrice à ajuster
    int threshold; // Seuil de luminosité

public:
    Brightness(Matrix& m, int t); // Constructeur
    void adjust(); // Méthode pour ajuster la luminosité
};

#endif // BRIGHTNESS_H
