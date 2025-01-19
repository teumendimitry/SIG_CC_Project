#ifndef MATRIX_H
#define MATRIX_H

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
    Matrix(int r, int c);

    // Constructeur pour lire une image PGM
    Matrix(const std::string& filename);

    // Méthodes
    int get(int i, int j) const;
    void set(int i, int j, int value);
    void display() const;
    void dimensions() const;
    int getRows() const;
    int getCols() const;
    void fill(unsigned char r, unsigned char g, unsigned char b); // Déclaration de fill
};

#endif // MATRIX_H
