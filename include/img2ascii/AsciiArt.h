#include <vector>
#include <string>

using art_t = std::vector<std::string>;

class AsciiArt {
    private:
        art_t caracteres;
        size_t largeur;

    public:
        AsciiArt(art_t& caracteres, size_t largeur);

        void afficherConsole() const;
        void ecrireFichier(std::string& nomFichierSortie) const;
};
