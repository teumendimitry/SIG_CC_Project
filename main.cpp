#include "Matrix.h"
#include "Brightness.h"
#include "Contrast.h"
#include "ImageSaver.h"
#include "Threshold.h"
#include "SumImages.h"
#include "ImageResizer.h"
#include "SubtractImages.h"
#include "MeanFilter.h"
#include "GaussianFilter.h"
#include "PrewittFilter.h"
#include "RobertsFilter.h"
#include "LaplacianFilter.h"
#include "OtsuThreshold.h"
#include "HoughTransform.h"
#include <vector>
#include "Zoom.h"

int main() {
    std::string outputDirectory = ".";
    std::string imageName = "diff_image";

 try {
        //Matrix mat("images/bonhomeBlouson.pgm");
        //mat.dimensions();

        // Ajustement de la luminosité
       // Brightness brightness(mat, 128);
       // brightness.adjust();

        // Ajustement du contraste
        //Contrast contrast(mat, 1.5);
        //contrast.adjust();

        // Appliquer le seuillage
        //Threshold threshold(mat, 128); // Seuil à 128
        //threshold.apply();

        //std::cout << "Matrice après seuillage : " << std::endl;
       // mat.display();

        // Sauvegarder l'image traitée
        //ImageSaver saver(mat, outputDirectory, imageName);
        //saver.save();


        /*Sommes de deux images
        Matrix img1("images/bonhomeBlouson.pgm"); // Première image
        Matrix img2("images/boulanger.pgm"); // Deuxième image
        img1.dimensions();
        img2.dimensions();



       // Redimensionner l'image la plus petite
        if (img1.getRows() < img2.getRows() || img1.getCols() < img2.getCols()) {
            ImageResizer resizer(img1);
            img1 = resizer.resize(img2.getRows(), img2.getCols());
            img1.dimensions();
        } else if (img2.getRows() < img1.getRows() || img2.getCols() < img1.getCols()) {
            ImageResizer resizer(img2);
            img2 = resizer.resize(img1.getRows(), img1.getCols());
            img2.dimensions();
        }


        Matrix result(img1.getRows(), img1.getCols()); // Image résultante

        // Créer l'additionneur et ajouter les images
        SumImages adder(img1, img2, result);
        adder.add();

        // Sauvegarder l'image résultante
        ImageSaver saver(result, outputDirectory, imageName);
        saver.save();
        */


        /* différence de deux images
        Matrix img1("images/bonhomeBlouson.pgm"); // Première image
        Matrix img2("images/boulanger.pgm"); // Deuxième image

        // Redimensionner les images si nécessaire
        if (img1.getRows() < img2.getRows() || img1.getCols() < img2.getCols()) {
            ImageResizer resizer(img1);
            img1 = resizer.resize(img2.getRows(), img2.getCols());
        } else if (img2.getRows() < img1.getRows() || img2.getCols() < img1.getCols()) {
            ImageResizer resizer(img2);
            img2 = resizer.resize(img1.getRows(), img1.getCols());
        }

        Matrix result(img1.getRows(), img1.getCols()); // Image résultante pour la différence

        // Créer l'instance de soustraction et soustraire les images
        SubtractImages subtractor(img1, img2, result);
        subtractor.subtract();

        // Sauvegarder l'image résultante
        ImageSaver saver(result, outputDirectory, imageName);
        saver.save();
        //img1
        ImageSaver saver1(img1, outputDirectory, "Img1Diff");
        saver1.save();
        //img2
        ImageSaver saver2(img2, outputDirectory, "Img2Diff");
        saver2.save();
*/

///////// Filtres///////////////////

/*filtre moyenneur

        Matrix inputImage("images/boulanger.pgm"); // Image d'entrée
        Matrix outputImage(inputImage.getRows(), inputImage.getCols()); // Image de sortie

        int kernelSize = 3; // Taille du noyau

        // Appliquer le filtre moyenneur
        MeanFilter meanFilter(inputImage, outputImage, kernelSize);
        meanFilter.apply();

        // Sauvegarder l'image résultante
        ImageSaver saver(outputImage, outputDirectory, "filtreMoyenneurBoulanger");
        saver.save();
*/


////// filtre gaussien
/*
Matrix inputImage("images/boulanger.pgm"); // Image d'entrée
        Matrix outputImage(inputImage.getRows(), inputImage.getCols()); // Image de sortie

        int kernelSize = 5; // Taille du noyau
        double sigma = 3.0; // Écart-type

        // Appliquer le filtre gaussien
        GaussianFilter gaussianFilter(inputImage, outputImage, kernelSize, sigma);
        gaussianFilter.apply();

        // Sauvegarder l'image résultante
        ImageSaver saver(outputImage, outputDirectory, "FiltreGaussienBoulanger2");
        saver.save();
*/


/////////////////////////// filtres passe haut

// filtre prewitt
/*
Matrix inputImage("images/boulanger.pgm"); // Image d'entrée
        Matrix outputImage(inputImage.getRows(), inputImage.getCols()); // Image de sortie

        // Appliquer le filtre de Prewitt
        PrewittFilter prewittFilter(inputImage, outputImage);
        prewittFilter.apply();

        // Sauvegarder l'image résultante
        ImageSaver saver(outputImage, outputDirectory, "filtrePrewittBoulanger");
        saver.save();

*/

// filtre rober
/*
Matrix inputImage("images/boulanger.pgm"); // Image d'entrée
        Matrix outputImage(inputImage.getRows(), inputImage.getCols()); // Image de sortie

        // Appliquer le filtre de Roberts
        RobertsFilter robertsFilter(inputImage, outputImage);
        robertsFilter.apply();

        // Sauvegarder l'image résultante
        ImageSaver saver(outputImage, outputDirectory, "FiltreRoberBoulanger");
        saver.save();
*/


// filtre laplacien
/*
Matrix inputImage("images/boulanger.pgm"); // Image d'entrée
        Matrix outputImage(inputImage.getRows(), inputImage.getCols()); // Image de sortie

        // Appliquer le filtre laplacien
        LaplacianFilter laplacianFilter(inputImage, outputImage);
        laplacianFilter.apply();

        // Sauvegarder l'image résultante
        ImageSaver saver(outputImage, outputDirectory,"FiltreLaplacienBoulanger");
        saver.save();
        */
//filtre otsu
/*
Matrix inputImage("images/boulanger.pgm"); // Image d'entrée
        Matrix outputImage(inputImage.getRows(), inputImage.getCols()); // Image de sortie

        // Appliquer le filtre d'Otsu
        OtsuThreshold otsuThreshold(inputImage);
        otsuThreshold.applyThreshold(outputImage);

        // Sauvegarder l'image résultante
        ImageSaver saver(outputImage, outputDirectory, "OtsuBoulanger");
        saver.save();
*/

/////// filtre de Hough

        /* Chargement de l'image d'entrée
        Matrix inputImage("images/boulanger.pgm"); // Assurez-vous que l'image est en niveaux de gris
        std::vector<std::pair<int, int>> lines; // Pour stocker les lignes détectées

        // Appliquer la transformation de Hough
        HoughTransform houghTransform(inputImage);
        houghTransform.detectLines(lines, 50); // Ajuster le seuil selon l'image

        // Vérifier le nombre de lignes détectées
        std::cout << "Nombre de lignes détectées : " << lines.size() << std::endl;

        // Créer une image de sortie pour dessiner les lignes
        Matrix outputImage(inputImage.getRows(), inputImage.getCols());

        // Dessiner les lignes détectées sur l'image de sortie
        houghTransform.drawLines(outputImage, lines);

        // Sauvegarder l'image résultante avec les lignes détectées
        ImageSaver saver(outputImage, outputDirectory, "HoughBoulanger");
        saver.save();

        std::cout << "Lignes détectées sauvegardées dans : " << "HoughBoulanger" << std::endl;
*/


////// zoom in

/* Charger l'image d'entrée
Matrix inputImage("images/boulanger.pgm");

// Créer un objet Zoom avec un facteur de zoom
double zoomFactor = 1.0; // Par exemple, 2x le zoom
Zoom zoom(zoomFactor);

// Appliquer le zoom avant
Matrix zoomedImage = zoom.apply(inputImage);

// Sauvegarder l'image zoomée
ImageSaver saver(zoomedImage, outputDirectory, "zoomBoulangerFois1");
saver.save();
*/


//// zoom out

// Créer un objet Zoom avec un facteur de zoom
double zoomFactor = 0.1; // Par exemple, pour un zoom arrière de 50%
Zoom zoom(zoomFactor);

Matrix inputImage("images/boulanger.pgm");

// Appliquer le zoom arrière
Matrix zoomedOutImage = zoom.zoomOut(inputImage);

// Sauvegarder l'image zoomée
ImageSaver saver(zoomedOutImage, outputDirectory, "zoomOutBoulanger2");
saver.save();



} catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;

    }

    return 0;
}
