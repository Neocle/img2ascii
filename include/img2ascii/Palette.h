#include <vector>

using palette_t = std::vector<std::string>;

class Palette {
    private:
        palette_t caracteresPalette;

    public:
        Palette(const std::string& fichier);
        Palette(const palette_t& palette);

        void charger(std::ifstream& palette);
        std::string getCaractere(int nuance);
        std::vector<std::string> convertir(const std::vector<int>& nuances);
};
