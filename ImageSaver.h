#ifndef IMAGESAVER_H
#define IMAGESAVER_H

#include "Matrix.h"

class ImageSaver {
private:
    Matrix& matrix; // Référence à la matrice à sauvegarder
    std::string directory; // Répertoire de sauvegarde
    std::string filename; // Nom du fichier

public:
    ImageSaver(Matrix& m, const std::string& dir, const std::string& name);
    void save();
};

#endif // IMAGESAVER_H
