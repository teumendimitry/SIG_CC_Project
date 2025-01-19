// SubtractImages.cpp
#include "SubtractImages.h"

SubtractImages::SubtractImages(const Matrix& img1, const Matrix& img2, Matrix& result)
    : image1(img1), image2(img2), result(result) {}

void SubtractImages::subtract() {
    int rows = image1.getRows();
    int cols = image1.getCols();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int diff = image1.get(i, j) - image2.get(i, j);
            // Assurer que la valeur est entre 0 et 255
            diff = (diff < 0) ? 0 : diff;
            result.set(i, j, diff);
        }
    }
}
