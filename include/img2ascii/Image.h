#pragma once

#include <string>
#include <vector>

using pixels_t = std::vector<int>;

class Image {
    private:
        std::string nomFichier;
        size_t largeur, hauteur;
        std::vector<int> pixels;

    public:
        Image(const std::string& fichier);

        void charger(std::ifstream& img);
        void echantillonner(double facteurLargeur, double facteurHauteur);

        pixels_t getPixels();
        size_t getLargeur() const;
        size_t getHauteur() const;
};
