#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>

class Matrix {
private:
    std::vector<std::vector<int>> data; // Conteneur pour les données de la matrice
    int rows; // Nombre de lignes
    int cols; // Nombre de colonnes
    int maxVal; // Valeur maximale des pixels

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

    // Méthode pour afficher les dimensions de la matrice
    void dimensions() const {
        std::cout << "Dimensions : " << rows << " x " << cols << std::endl;
    }
};
