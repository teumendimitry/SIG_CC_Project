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

    // Cr�er une nouvelle matrice remplie de z�ros
    Matrix resized(targetRows, targetCols);

    // Calculer les positions pour centrer l'image originale
    int rowOffset = (targetRows - originalRows) / 2;
    int colOffset = (targetCols - originalCols) / 2;

    std::cout << "D�calage : " << rowOffset << " (lignes), " << colOffset << " (colonnes)" << std::endl;

    // V�rifier si les d�calages ne sont pas n�gatifs
    if (rowOffset < 0 || colOffset < 0) {
        throw std::runtime_error("Les dimensions cibles sont trop petites pour contenir l'image originale.");
    }

    for (int i = 0; i < originalRows; ++i) {
        for (int j = 0; j < originalCols; ++j) {
            // V�rifie que nous ne d�passons pas les dimensions de la matrice r�sultante
            if (i + rowOffset < targetRows && j + colOffset < targetCols) {
                resized.set(i + rowOffset, j + colOffset, original.get(i, j));
            } else {
                std::cerr << "Tentative d'acc�s � des indices hors limites : "
                          << "i = " << i + rowOffset << ", j = " << j + colOffset << std::endl;
            }
        }
    }

    return resized; // Retourner l'image redimensionn�e
}
