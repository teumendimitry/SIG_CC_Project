#ifndef ZOOM_H
#define ZOOM_H

#include "Matrix.h"

class Zoom {
public:
    Zoom(double factor);
    Matrix apply(const Matrix& inputImage);
    Matrix zoomOut(const Matrix& inputImage); // Ajout de la méthode zoomOut

private:
    double zoomFactor;
};

#endif // ZOOM_H
