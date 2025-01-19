#include "Zoom.h"
#include "Matrix.h"



Zoom::Zoom(double factor) : zoomFactor(factor) {}

Matrix Zoom::apply(const Matrix& inputImage) {
    int originalRows = inputImage.getRows();
    int originalCols = inputImage.getCols();
    int newRows = static_cast<int>(originalRows * zoomFactor);
    int newCols = static_cast<int>(originalCols * zoomFactor);

    Matrix zoomedImage(newRows, newCols);

    for (int y = 0; y < newRows; ++y) {
        for (int x = 0; x < newCols; ++x) {
            int origY = static_cast<int>(y / zoomFactor);
            int origX = static_cast<int>(x / zoomFactor);

            if (origY < originalRows && origX < originalCols) {
                int value = inputImage.get(origY, origX);
                zoomedImage.set(y, x, value);
            }
        }
    }

    return zoomedImage;
}

Matrix Zoom::zoomOut(const Matrix& inputImage) {
    int originalRows = inputImage.getRows();
    int originalCols = inputImage.getCols();
    int newRows = static_cast<int>(originalRows / zoomFactor);
    int newCols = static_cast<int>(originalCols / zoomFactor);

    Matrix zoomedImage(newRows, newCols);

    for (int y = 0; y < newRows; ++y) {
        for (int x = 0; x < newCols; ++x) {
            int origY = static_cast<int>(y * zoomFactor);
            int origX = static_cast<int>(x * zoomFactor);

            if (origY < originalRows && origX < originalCols) {
                int value = inputImage.get(origY, origX);
                zoomedImage.set(y, x, value);
            }
        }
    }

    return zoomedImage;
}
