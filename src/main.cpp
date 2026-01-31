#include <iostream>
#include <sstream>
#include <algorithm>
#include <filesystem>

#include "Arguments.h"
#include "AsciiArt.h"
#include "Image.h"
#include "ImageConverter.h"
#include "Palette.h"

#define NOMINMAX

#ifdef _WIN32
#include <Windows.h>
#endif

Palette parsePalette(const std::string& argPalette) {
    const palette_t classicChars = { "W", "w", "l", "i", ":", ",", ".", " "};
    const palette_t classicDoubleChars = { "WW", "ww", "ll", "ii", "::", ",,", "..", "  "};
    const palette_t uf8Chars = { "█", "▓", "▒", "░", " " };
    const palette_t uf8DoubleChars = { "██", "▓▓", "▒▒", "░░", "  " };

    const Palette classic{ classicChars };
    const Palette classicDouble{ classicDoubleChars };
    const Palette uf8{ uf8Chars };
    const Palette uf8Double{ uf8DoubleChars };

    if (argPalette.empty()) {
        return Palette{""};
    }
    if (argPalette == "classic") {
        return classic;
    }
    if (argPalette == "classicDouble") {
        return classicDouble;
    }
    if (argPalette == "utf8") {
        return uf8;
    }
    if (argPalette == "utf8Double") {
        return uf8Double;
    }

    return Palette{argPalette};
}

int main(int argc, char* argv[]) {
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif
    Arguments args;
    args.parse(argc, argv);

    std::string inputFile = args.getInputFile();
    std::string pgmFile = inputFile;

    if (std::filesystem::path(inputFile).extension() != ".pgm") {
        ImageConverter converter;

        pgmFile = std::filesystem::path(inputFile).stem().string() + ".pgm";
        converter.toPgm(inputFile, pgmFile);
    }

    Image img(pgmFile);

    double facteurLargeur = 1, facteurHauteur = 1;
    if (args.getLargeurMax() > 0 || args.getHauteurMax() > 0) {
        double fw = args.getLargeurMax() > 0 ? double(args.getLargeurMax()) / img.getLargeur() : 1;
        double fh = args.getHauteurMax() > 0 ? double(args.getHauteurMax()) / img.getHauteur() : 1;
        double facteur = std::min(fw, fh);
        facteurLargeur = facteurHauteur = facteur;
    }

    img.echantillonner(facteurLargeur, facteurHauteur);

    Palette palette = parsePalette(args.getPaletteFile());

    palette_t caracteres = palette.convertir(img.getPixels());
    AsciiArt art(caracteres, img.getLargeur());

    art.afficherConsole();

    if (!args.getOutputFile().empty()) {
        art.ecrireFichier(args.getOutputFile());
    }

    return 0;
}