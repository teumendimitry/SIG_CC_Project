// HoughTransform.h
#ifndef HOUGHTRANSFORM_H
#define HOUGHTRANSFORM_H

#include "Matrix.h"
#include <vector>

class HoughTransform {
public:
    HoughTransform(const Matrix& inputImage);
    void detectLines(std::vector<std::pair<int, int>>& lines, int threshold);
    void drawLines(Matrix& image, const std::vector<std::pair<int, int>>& lines);

private:
    const Matrix& inputImage;
    int width;
    int height;
    int maxR;
    std::vector<std::vector<int>> accumulator;

    void initializeAccumulator();
};

#endif // HOUGHTRANSFORM_H
