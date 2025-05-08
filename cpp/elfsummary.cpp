#include<iostream>
#include<fstream>
#include<string>

class ElfReader {
    std::string fileName;

public:
    ElfReader(std::string filename) : fileName(filename) {}
    int summarize() {
        std::ifstream ifs;
        ifs.open(fileName, std::ios::binary);
        if (!ifs.is_open()) {
            std::cerr << "Error opening file: " << fileName << std::endl;
            return 1;
        }

        // get length of file:
        int length = 0;
        ifs.seekg (0, std::ios::end);
        length = ifs.tellg();
        ifs.seekg (0, std::ios::beg);
        if (length < 52) { // not even a 32-bit binary
            std::cerr << "Invalid file, expecting at least 52 bytes for ELF "
                << " header." << std::endl;
            return 1;
        }
        char magic_word[5];
        ifs.read(magic_word, 4);

        std::cout << "Filename: " << fileName << std::endl;
        std::cout << "MAGIC WORD: " << std::hex << "0x" << (int)magic_word[1]
            << " 0x" << (int)magic_word[2] << " 0x" << (int)magic_word[3] << std::endl;
        return 0;
    }
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <elf filename>" << std::endl;
        return 1;
    }
    ElfReader reader(argv[1]);
    reader.summarize();
    return 0;
}
