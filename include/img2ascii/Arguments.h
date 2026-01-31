#include <iostream>
#include <string>

class Arguments {
    private:
        std::string inputFile, outputFile, paletteFile;
        size_t largeurMax = 0, hauteurMax = 0;

    public:
        void parse(int argc, char* argv[]);

        std::string& getInputFile();
        std::string& getOutputFile();
        std::string& getPaletteFile();
        size_t getLargeurMax() const;
        size_t getHauteurMax() const;
};
