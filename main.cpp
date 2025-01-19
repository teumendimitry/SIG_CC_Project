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

        // Ajustement de la luminosit�
       // Brightness brightness(mat, 128);
       // brightness.adjust();

        // Ajustement du contraste
        //Contrast contrast(mat, 1.5);
        //contrast.adjust();

        // Appliquer le seuillage
        //Threshold threshold(mat, 128); // Seuil � 128
        //threshold.apply();

        //std::cout << "Matrice apr�s seuillage : " << std::endl;
       // mat.display();

        // Sauvegarder l'image trait�e
        //ImageSaver saver(mat, outputDirectory, imageName);
        //saver.save();


        /*Sommes de deux images
        Matrix img1("images/bonhomeBlouson.pgm"); // Premi�re image
        Matrix img2("images/boulanger.pgm"); // Deuxi�me image
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


        Matrix result(img1.getRows(), img1.getCols()); // Image r�sultante

        // Cr�er l'additionneur et ajouter les images
        SumImages adder(img1, img2, result);
        adder.add();

        // Sauvegarder l'image r�sultante
        ImageSaver saver(result, outputDirectory, imageName);
        saver.save();
        */


        /* diff�rence de deux images
        Matrix img1("images/bonhomeBlouson.pgm"); // Premi�re image
        Matrix img2("images/boulanger.pgm"); // Deuxi�me image

        // Redimensionner les images si n�cessaire
        if (img1.getRows() < img2.getRows() || img1.getCols() < img2.getCols()) {
            ImageResizer resizer(img1);
            img1 = resizer.resize(img2.getRows(), img2.getCols());
        } else if (img2.getRows() < img1.getRows() || img2.getCols() < img1.getCols()) {
            ImageResizer resizer(img2);
            img2 = resizer.resize(img1.getRows(), img1.getCols());
        }

        Matrix result(img1.getRows(), img1.getCols()); // Image r�sultante pour la diff�rence

        // Cr�er l'instance de soustraction et soustraire les images
        SubtractImages subtractor(img1, img2, result);
        subtractor.subtract();

        // Sauvegarder l'image r�sultante
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

        Matrix inputImage("images/boulanger.pgm"); // Image d'entr�e
        Matrix outputImage(inputImage.getRows(), inputImage.getCols()); // Image de sortie

        int kernelSize = 3; // Taille du noyau

        // Appliquer le filtre moyenneur
        MeanFilter meanFilter(inputImage, outputImage, kernelSize);
        meanFilter.apply();

        // Sauvegarder l'image r�sultante
        ImageSaver saver(outputImage, outputDirectory, "filtreMoyenneurBoulanger");
        saver.save();
*/


////// filtre gaussien
/*
Matrix inputImage("images/boulanger.pgm"); // Image d'entr�e
        Matrix outputImage(inputImage.getRows(), inputImage.getCols()); // Image de sortie

        int kernelSize = 5; // Taille du noyau
        double sigma = 3.0; // �cart-type

        // Appliquer le filtre gaussien
        GaussianFilter gaussianFilter(inputImage, outputImage, kernelSize, sigma);
        gaussianFilter.apply();

        // Sauvegarder l'image r�sultante
        ImageSaver saver(outputImage, outputDirectory, "FiltreGaussienBoulanger2");
        saver.save();
*/


/////////////////////////// filtres passe haut

// filtre prewitt
/*
Matrix inputImage("images/boulanger.pgm"); // Image d'entr�e
        Matrix outputImage(inputImage.getRows(), inputImage.getCols()); // Image de sortie

        // Appliquer le filtre de Prewitt
        PrewittFilter prewittFilter(inputImage, outputImage);
        prewittFilter.apply();

        // Sauvegarder l'image r�sultante
        ImageSaver saver(outputImage, outputDirectory, "filtrePrewittBoulanger");
        saver.save();

*/

// filtre rober
/*
Matrix inputImage("images/boulanger.pgm"); // Image d'entr�e
        Matrix outputImage(inputImage.getRows(), inputImage.getCols()); // Image de sortie

        // Appliquer le filtre de Roberts
        RobertsFilter robertsFilter(inputImage, outputImage);
        robertsFilter.apply();

        // Sauvegarder l'image r�sultante
        ImageSaver saver(outputImage, outputDirectory, "FiltreRoberBoulanger");
        saver.save();
*/


// filtre laplacien
/*
Matrix inputImage("images/boulanger.pgm"); // Image d'entr�e
        Matrix outputImage(inputImage.getRows(), inputImage.getCols()); // Image de sortie

        // Appliquer le filtre laplacien
        LaplacianFilter laplacianFilter(inputImage, outputImage);
        laplacianFilter.apply();

        // Sauvegarder l'image r�sultante
        ImageSaver saver(outputImage, outputDirectory,"FiltreLaplacienBoulanger");
        saver.save();
        */
//filtre otsu
/*
Matrix inputImage("images/boulanger.pgm"); // Image d'entr�e
        Matrix outputImage(inputImage.getRows(), inputImage.getCols()); // Image de sortie

        // Appliquer le filtre d'Otsu
        OtsuThreshold otsuThreshold(inputImage);
        otsuThreshold.applyThreshold(outputImage);

        // Sauvegarder l'image r�sultante
        ImageSaver saver(outputImage, outputDirectory, "OtsuBoulanger");
        saver.save();
*/

/////// filtre de Hough

        /* Chargement de l'image d'entr�e
        Matrix inputImage("images/boulanger.pgm"); // Assurez-vous que l'image est en niveaux de gris
        std::vector<std::pair<int, int>> lines; // Pour stocker les lignes d�tect�es

        // Appliquer la transformation de Hough
        HoughTransform houghTransform(inputImage);
        houghTransform.detectLines(lines, 50); // Ajuster le seuil selon l'image

        // V�rifier le nombre de lignes d�tect�es
        std::cout << "Nombre de lignes d�tect�es : " << lines.size() << std::endl;

        // Cr�er une image de sortie pour dessiner les lignes
        Matrix outputImage(inputImage.getRows(), inputImage.getCols());

        // Dessiner les lignes d�tect�es sur l'image de sortie
        houghTransform.drawLines(outputImage, lines);

        // Sauvegarder l'image r�sultante avec les lignes d�tect�es
        ImageSaver saver(outputImage, outputDirectory, "HoughBoulanger");
        saver.save();

        std::cout << "Lignes d�tect�es sauvegard�es dans : " << "HoughBoulanger" << std::endl;
*/


////// zoom in

/* Charger l'image d'entr�e
Matrix inputImage("images/boulanger.pgm");

// Cr�er un objet Zoom avec un facteur de zoom
double zoomFactor = 1.0; // Par exemple, 2x le zoom
Zoom zoom(zoomFactor);

// Appliquer le zoom avant
Matrix zoomedImage = zoom.apply(inputImage);

// Sauvegarder l'image zoom�e
ImageSaver saver(zoomedImage, outputDirectory, "zoomBoulangerFois1");
saver.save();
*/


//// zoom out

// Cr�er un objet Zoom avec un facteur de zoom
double zoomFactor = 0.1; // Par exemple, pour un zoom arri�re de 50%
Zoom zoom(zoomFactor);

Matrix inputImage("images/boulanger.pgm");

// Appliquer le zoom arri�re
Matrix zoomedOutImage = zoom.zoomOut(inputImage);

// Sauvegarder l'image zoom�e
ImageSaver saver(zoomedOutImage, outputDirectory, "zoomOutBoulanger2");
saver.save();



} catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;

    }

    return 0;
}
