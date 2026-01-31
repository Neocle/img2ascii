#include "Arguments.h"

void Arguments::parse(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--input") inputFile = argv[i + 1];
        else if (arg == "--output") outputFile = argv[i + 1];
        else if (arg == "--palette") paletteFile = argv[i + 1];
        else if (arg == "--width") largeurMax = std::stoul(argv[i + 1]);
        else if (arg == "--height") hauteurMax = std::stoul(argv[i + 1]);
        else if (arg == "--help") {
            std::cout <<
                "Usage :\n"
                "    img2ascii [options]\n"
                "\n"
                "Options :\n"
                "    --input fichier        Spécifie le fichier image à convertir.\n"
                "                           Si ce paramètre n'est pas spécifié, le fichier est\n"
                "                           demandé via la console.\n"
                "\n"
                "    --output fichier       Spécifie le fichier texte de sortie.\n"
                "                           Si non spécifié, l'Ascii Art est affiché dans la\n"
                "                           console.\n"
                "\n"
                "    --palette fichier/nom  Spécifie un fichier contenant la palette Ascii ou le nom\n"
                "                           d'une des paletes prédéfinies (classic/classicDouble/utf8/utf8Double)"
                "                           Chaque ligne du fichier contient un caractère UTF-8,\n"
                "                           du plus sombre au plus clair.\n"
                "                           Si non spécifié, la palette par défaut est :\n"
                "                           \"W\", \"w\", \"l\", \"i\", \":\", \",\", \".\", \" \"\n"
                "\n"
                "    --help                 Affiche cette aide.\n"
                "    --width nombre         Spécifie la largeur max de l'Ascii Art.\n"
                "                           Si ce paramètre n'est pas spécifié, aucune limite n'est fixée.\n"
                "                           Voir Remarques.\n"
                "    --height nombre        Spécifie la hauteur max de l'Ascii Art.\n"
                "                           Si ce paramètre n'est pas spécifié, aucune limite n'est fixée.\n"
                "                           Voir Remarques.\n"
                "\n"
                "Remarques :\n"
                "Quelles que soient les valeurs des options --width et --height, la taille de l'Ascii Art\n"
                "est bornée par la taille de l'image en entrée. La taille de l'Ascii Art conserve\n"
                "toujours le même ratio que l'image d'entrée, les valeurs des options --width et --height\n"
                "ne sont que des maximums.\n";

            exit(1);
        }
    }

    if (inputFile.empty()) {
        std::cout << "Fichier d'entrée ? ";
        std::cin >> inputFile;
    }
}

std::string& Arguments::getInputFile() {
    return this->inputFile;
}

std::string& Arguments::getOutputFile() {
    return this->outputFile;
}

std::string& Arguments::getPaletteFile() {
    return this->paletteFile;
}

size_t Arguments::getLargeurMax() const {
    return this->largeurMax;
}

size_t Arguments::getHauteurMax() const {
    return this->hauteurMax;
}