#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>

class Matrix {
private:
    std::vector<std::vector<int>> data; // Conteneur pour les donn�es de la matrice
    int rows; // Nombre de lignes
    int cols; // Nombre de colonnes
    int maxVal; // Valeur maximale des pixels

public:
    // Constructeur qui initialise la matrice avec des dimensions sp�cifi�es
    Matrix(int r, int c);

    // Constructeur pour lire une image PGM
    Matrix(const std::string& filename);

    // M�thodes
    int get(int i, int j) const;
    void set(int i, int j, int value);
    void display() const;
    void dimensions() const;
    int getRows() const;
    int getCols() const;
    void fill(unsigned char r, unsigned char g, unsigned char b); // D�claration de fill
};

#endif // MATRIX_H
