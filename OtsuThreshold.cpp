// OtsuThreshold.cpp
#include "OtsuThreshold.h"
#include <cmath>
#include <limits>

OtsuThreshold::OtsuThreshold(const Matrix& inputImage)
    : inputImage(inputImage) {
    calculateHistogram();
}

void OtsuThreshold::calculateHistogram() {
    totalPixels = inputImage.getRows() * inputImage.getCols();
    for (int i = 0; i < inputImage.getRows(); ++i) {
        for (int j = 0; j < inputImage.getCols(); ++j) {
            int pixelValue = inputImage.get(i, j);
            histogram[pixelValue]++;
        }
    }
}

int OtsuThreshold::calculateThreshold() {
    float maxVariance = 0.0f;
    int bestThreshold = 0;

    for (int t = 0; t < 256; ++t) {
        float w0 = 0.0f;
        float w1 = 0.0f;
        float sum0 = 0.0f;
        float sum1 = 0.0f;

        for (int i = 0; i <= t; ++i) {
            w0 += histogram[i];
            sum0 += i * histogram[i];
        }
        for (int i = t + 1; i < 256; ++i) {
            w1 += histogram[i];
            sum1 += i * histogram[i];
        }

        if (w0 == 0 || w1 == 0) continue;

        float mean0 = sum0 / w0;
        float mean1 = sum1 / w1;

        float variance = w0 * w1 * (mean0 - mean1) * (mean0 - mean1);

        if (variance > maxVariance) {
            maxVariance = variance;
            bestThreshold = t;
        }
    }
    return bestThreshold;
}

void OtsuThreshold::applyThreshold(Matrix& outputImage) {
    int threshold = calculateThreshold();
    for (int i = 0; i < inputImage.getRows(); ++i) {
        for (int j = 0; j < inputImage.getCols(); ++j) {
            int pixelValue = inputImage.get(i, j);
            outputImage.set(i, j, (pixelValue > threshold) ? 255 : 0);
        }
    }
}
