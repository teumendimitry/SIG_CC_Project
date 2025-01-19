#ifndef IMAGESAVER_H
#define IMAGESAVER_H

#include "Matrix.h"

class ImageSaver {
private:
    Matrix& matrix; // R�f�rence � la matrice � sauvegarder
    std::string directory; // R�pertoire de sauvegarde
    std::string filename; // Nom du fichier

public:
    ImageSaver(Matrix& m, const std::string& dir, const std::string& name);
    void save();
};

#endif // IMAGESAVER_H
