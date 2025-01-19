#include <iostream>
#include "Matrix.cpp" // Inclure le fichier Matrix.cpp

using namespace std;

int main()
{
        try {
        // Exemple d'utilisation avec un fichier PGM
        Matrix mat("images/bonhomeBlouson.pgm"); // Remplace "image.pgm" par le nom de ton fichier PGM

        std::cout << "Matrice : " << std::endl;
        mat.display();

        // Exemple d'accès à un élément
        std::cout << "Élément à (1,1) : " << mat.get(1, 1) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }


    return 0;

}
