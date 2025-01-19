#ifndef THRESHOLD_H
#define THRESHOLD_H

#include "Matrix.h"

class Threshold {
private:
    Matrix& matrix; // R�f�rence � la matrice � traiter
    int threshold; // Seuil

public:
    Threshold(Matrix& m, int t); // D�claration du constructeur
    void apply(); // D�claration de la m�thode apply
};

#endif // THRESHOLD_H
