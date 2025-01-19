#include "Matrix.h"

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data.resize(rows, std::vector<int>(cols, 0)); // Initialisation avec des zéros
}

Matrix::Matrix(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    // Lire le format
    std::getline(file, line);
    if (line != "P2") {
        throw std::invalid_argument("Unsupported file format");
    }

    // Ignorer les lignes vides et les commentaires
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            continue; // Ignorer les lignes vides et les commentaires
        }

        std::istringstream iss(line);
        // Lire les dimensions
        if (iss >> cols >> rows) {
            break; // Sortir de la boucle si les dimensions sont lues
        }
    }

    // Lire la valeur maximale
    if (!(file >> maxVal)) {
        throw std::invalid_argument("Failed to read max value");
    }

    // Vérification des dimensions
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Invalid dimensions in PGM file");
    }

    data.resize(rows, std::vector<int>(cols));

    // Lire les valeurs de pixel
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(file >> data[i][j])) {
                throw std::runtime_error("Failed to read pixel data");
            }
        }
    }
}

int Matrix::get(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw std::out_of_range("Index out of range in get Matrix function");
    }
    return data[i][j];
}

void Matrix::set(int i, int j, int value) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw std::out_of_range("Index out of range in set Matrix function");
    }
    data[i][j] = value;
}

void Matrix::display() const {
    for (const auto& row : data) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::dimensions() const {
    std::cout << "Dimensions : " << rows << " x " << cols << std::endl;
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}
