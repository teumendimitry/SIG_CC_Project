// HoughTransform.cpp
#include "HoughTransform.h"
#include <cmath>
#include <limits>

HoughTransform::HoughTransform(const Matrix& inputImage)
    : inputImage(inputImage), width(inputImage.getCols()), height(inputImage.getRows()) {
    maxR = static_cast<int>(std::sqrt(width * width + height * height));
    initializeAccumulator();
}

void HoughTransform::initializeAccumulator() {
    accumulator.resize(180, std::vector<int>(maxR, 0));
}

void HoughTransform::detectLines(std::vector<std::pair<int, int>>& lines, int threshold) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (inputImage.get(y, x) > 0) { // Si le pixel est un bord
                for (int theta = 0; theta < 180; ++theta) {
                    int r = static_cast<int>(x * cos(theta * M_PI / 180.0) + y * sin(theta * M_PI / 180.0));
                    r += maxR / 2; // Décalage pour être positif
                    if (r >= 0 && r < maxR) {
                        accumulator[theta][r]++;
                    }
                }
            }
        }
    }

    // Détecter les lignes
    for (int theta = 0; theta < 180; ++theta) {
        for (int r = 0; r < maxR; ++r) {
            if (accumulator[theta][r] >= threshold) {
                lines.push_back(std::make_pair(theta, r - maxR / 2)); // Stocker les lignes
            }
        }
    }
}

void HoughTransform::drawLines(Matrix& image, const std::vector<std::pair<int, int>>& lines) {
    int rows = image.getRows();
    int cols = image.getCols();

    // Remplir l'image de sortie avec des pixels noirs
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            image.set(y, x, 0); // Initialiser chaque pixel à 0 (noir)
        }
    }

    for (const auto& line : lines) {
        int theta = line.first; // Angle
        int r = line.second;     // Distance

        // Convertir theta en radians
        double thetaRad = theta * M_PI / 180.0;

        // Calculer les points de l'image pour tracer la ligne
        for (int x = 0; x < cols; ++x) {
            int y = static_cast<int>((r - x * cos(thetaRad)) / sin(thetaRad));
            if (y >= 0 && y < rows) {
                image.set(y, x, 0); // Définir le pixel à blanc pour dessiner la ligne
            }
        }
    }
}
