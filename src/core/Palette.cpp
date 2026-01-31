#include "Palette.h"

#include <fstream>
#include <iostream>

Palette::Palette(const std::string& fichier) {
    std::ifstream palette(fichier);

    if (!palette.is_open() && !fichier.empty()) {
        std::cerr << "Impossible d'ouvrir le fichier" << fichier << "!" << std::endl;
        return;
    }

    this->charger(palette);
}

Palette::Palette(const palette_t& palette) {
    this->caracteresPalette = palette;
}

void Palette::charger(std::ifstream& palette) {
    palette.seekg(0, std::ios::end);

    if (!palette.is_open()) {
        this->caracteresPalette = { "W", "w", "l", "i", ":", ",", ".", " " };
        return;
    }

    if (palette.tellg() == 0) {
        std::cerr << "Le fichier de la palette est vide!" << std::endl;
        this->caracteresPalette = { "W", "w", "l", "i", ":", ",", ".", " " };
        return;
    }

    palette.seekg(0, std::ios::beg);

    std::string ligne;
    while (std::getline(palette, ligne)) {
        // Supprimer les caractères \r et autres espaces en fin de ligne
        while (!ligne.empty() && (ligne.back() == '\r' || ligne.back() == '\n')) {
            ligne.pop_back();
        }

        if (!ligne.empty())
            caracteresPalette.push_back(ligne);
    }
}

std::string Palette::getCaractere(int nuance) {
    int i = nuance * caracteresPalette.size() / 256;
    return caracteresPalette[i];
}

std::vector<std::string> Palette::convertir(const std::vector<int>& nuances) {
    std::vector<std::string> caracteres;

    for (int nuance : nuances) {
        std::string chars = getCaractere(nuance);
        caracteres.push_back(chars);
    }

    return caracteres;
}

