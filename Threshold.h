#ifndef THRESHOLD_H
#define THRESHOLD_H

#include "Matrix.h"

class Threshold {
private:
    Matrix& matrix; // Référence à la matrice à traiter
    int threshold; // Seuil

public:
    Threshold(Matrix& m, int t); // Déclaration du constructeur
    void apply(); // Déclaration de la méthode apply
};

#endif // THRESHOLD_H
