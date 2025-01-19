#include "ImageSaver.h"

ImageSaver::ImageSaver(Matrix& m, const std::string& dir, const std::string& name)
    : matrix(m), directory(dir), filename(name) {}

void ImageSaver::save() {
    std::ofstream file(directory + "/" + filename + ".pgm");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for saving");
    }

    file << "P2" << std::endl; // Format PGM
    file << matrix.getCols() << " " << matrix.getRows() << std::endl; // Dimensions
    file << "255" << std::endl; // Valeur maximale

    int rows = matrix.getRows();
    int cols = matrix.getCols();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file << matrix.get(i, j) << " ";
        }
        file << std::endl;
    }

    file.close();
}
