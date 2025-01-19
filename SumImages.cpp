#include "SumImages.h"

SumImages::SumImages(Matrix& img1, Matrix& img2, Matrix& res)
    : image1(img1), image2(img2), result(res) {}


void SumImages::add() {
    int rows = image1.getRows();
    int cols = image1.getCols();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Addition de pixels : img1[" << i << "][" << j << "] + img2[" << i << "][" << j << "]" << std::endl;
            int sum = image1.get(i, j) + image2.get(i, j);
            sum = std::min(255, sum);
            result.set(i, j, sum);
        }
    }
}
