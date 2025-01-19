#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

public:
    // Constructeur qui initialise la matrice avec des dimensions spécifiées
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, std::vector<int>(cols, 0)); // Initialisation avec des zéros
    }

    // Constructeur pour lire une image PGM
    Matrix(const std::string& filename) {
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

        // Lire les dimensions
        int maxVal;
        file >> cols >> rows >> maxVal;

        data.resize(rows, std::vector<int>(cols));

        // Lire les valeurs de pixel
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                file >> data[i][j];
            }
        }
    }

    // Méthode pour obtenir un élément à la position (i, j)
    int get(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw std::out_of_range("Index out of range");
        }
        return data[i][j];
    }

    // Méthode pour définir un élément à la position (i, j)
    void set(int i, int j, int value) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw std::out_of_range("Index out of range");
        }
        data[i][j] = value;
    }

    // Méthode pour afficher la matrice
    void display() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }
};
