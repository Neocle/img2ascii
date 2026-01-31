#include <fstream>
#include <sstream>

#include "Image.h"

#include <iostream>

Image::Image(const std::string& fichier) {
    this->nomFichier = fichier;

    std::ifstream img(nomFichier, std::ios_base::binary);

    if (!img.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier " << nomFichier << "!" << std::endl;
        return;
    }

    this->charger(img);
}

void Image::charger(std::ifstream& img) {
    std::vector<std::string> entete;
    std::string ligne;

    while (entete.size() < 3 && std::getline(img, ligne)) {
        if (ligne.empty() || ligne[0] == '#')
            continue;
        entete.push_back(ligne);
    }

    std::stringstream ss(entete[1]);
    ss >> largeur >> hauteur;

    size_t taille = largeur * hauteur;

    std::vector<char> donneesPixels(taille);
    img.read(donneesPixels.data(), taille);

    this->pixels.clear();
    for (unsigned char octet : donneesPixels) {
        this->pixels.push_back(octet);
    }
}

void Image::echantillonner(double facteurLargeur, double facteurHauteur) {
    if (facteurLargeur >= 1 && facteurHauteur >= 1) {
        return;
    }

    std::vector<std::vector<int>> nuances2d;

    for (size_t i = 0; i < hauteur; i++) {
        std::vector<int> ligne;
        for (size_t j = 0; j < largeur; j++) {
            ligne.push_back(pixels[i * largeur + j]);
        }
        nuances2d.push_back(ligne);
    }

    size_t largeurReduite = std::max<size_t>(1, static_cast<size_t>(largeur * facteurLargeur));
    size_t hauteurReduite = std::max<size_t>(1, static_cast<size_t>(hauteur * facteurHauteur));

    pixels_t imageReduite(largeurReduite * hauteurReduite);

    double groupePixelH = 1.0 / facteurHauteur;
    double groupePixelL = 1.0 / facteurLargeur;

    for (size_t i = 0; i < hauteurReduite; i++) {
        for (size_t j = 0; j < largeurReduite; j++) {
            int ligneDebut = static_cast<int>(i * groupePixelH);
            int colonneDebut = static_cast<int>(j * groupePixelL);
            int ligneFin = static_cast<int>((i + 1) * groupePixelH);
            int colonneFin = static_cast<int>((j + 1) * groupePixelL);
            int sommePixel = 0;
            int nbPixel = 0;

            for (int k = ligneDebut; k < ligneFin; k++) {
                for (int l = colonneDebut; l < colonneFin; l++) {
                    sommePixel += nuances2d[k][l];
                    nbPixel++;
                }
            }

            imageReduite[i * largeurReduite + j] = sommePixel / nbPixel;
        }
    }

    this->pixels = imageReduite;
    this->largeur = largeurReduite;
    this->hauteur = hauteurReduite;
}

pixels_t Image::getPixels() {
    return this->pixels;
}

size_t Image::getLargeur() const {
    return this->largeur;
}

size_t Image::getHauteur() const {
    return this->hauteur;
}