#include "ImageResizer.h"
#include <iostream>

ImageResizer::ImageResizer(Matrix& img) : original(img) {}

Matrix ImageResizer::resize(int targetRows, int targetCols) {
    int originalRows = original.getRows();
    int originalCols = original.getCols();

    std::cout << "Dimensions de l'image originale : "
              << originalRows << "x" << originalCols << std::endl;
    std::cout << "Dimensions cibles : "
              << targetRows << "x" << targetCols << std::endl;

    // Créer une nouvelle matrice remplie de zéros
    Matrix resized(targetRows, targetCols);

    // Calculer les positions pour centrer l'image originale
    int rowOffset = (targetRows - originalRows) / 2;
    int colOffset = (targetCols - originalCols) / 2;

    std::cout << "Décalage : " << rowOffset << " (lignes), " << colOffset << " (colonnes)" << std::endl;

    // Vérifier si les décalages ne sont pas négatifs
    if (rowOffset < 0 || colOffset < 0) {
        throw std::runtime_error("Les dimensions cibles sont trop petites pour contenir l'image originale.");
    }

    for (int i = 0; i < originalRows; ++i) {
        for (int j = 0; j < originalCols; ++j) {
            // Vérifie que nous ne dépassons pas les dimensions de la matrice résultante
            if (i + rowOffset < targetRows && j + colOffset < targetCols) {
                resized.set(i + rowOffset, j + colOffset, original.get(i, j));
            } else {
                std::cerr << "Tentative d'accès à des indices hors limites : "
                          << "i = " << i + rowOffset << ", j = " << j + colOffset << std::endl;
            }
        }
    }

    return resized; // Retourner l'image redimensionnée
}
