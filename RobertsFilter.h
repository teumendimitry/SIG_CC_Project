// RobertsFilter.h
#ifndef ROBERTSFILTER_H
#define ROBERTSFILTER_H

#include "Matrix.h" // Assurez-vous que cela est inclus

class RobertsFilter {
public:
    RobertsFilter(const Matrix& inputImage, Matrix& outputImage); // Constructeur
    void apply(); // Méthode d'application

private:
    const Matrix& inputImage;
    Matrix& outputImage;

    void applyKernel(int x, int y, int& gx, int& gy); // Méthode pour appliquer le noyau
};

#endif // ROBERTSFILTER_H
