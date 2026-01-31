#include <iostream>
#include <fstream>

#include "AsciiArt.h"

AsciiArt::AsciiArt(art_t& caracteres, size_t largeur) {
    this->largeur = largeur;
    this->caracteres = caracteres;
}

void AsciiArt::afficherConsole() const {
    for (size_t i = 0; i < caracteres.size(); i++) {

        std::cout << caracteres[i] << " ";
        if ((i + 1) % largeur == 0) {
            std::cout << "\n";
        }
    }
}

void AsciiArt::ecrireFichier(std::string& nomFichierSortie) const {
    std::ofstream fichierSortie(nomFichierSortie);

    if (!fichierSortie.is_open()) {
        std::cerr << "Impossible d'écrire vers le fichier " << nomFichierSortie << "\n";
        return;
    }

    for (size_t i = 0; i < caracteres.size(); i++) {

        fichierSortie << caracteres[i] << " ";
        if ((i + 1) % largeur == 0) {
            fichierSortie << "\n";
        }
    }
}
