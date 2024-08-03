#include <iostream>
#include <fstream>
#include <string>
#include "DNAProfile.h"
#include "Database.h"
#include "Output.h"

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: dna_profiler -d <database_file> -s <dna_sequence_file>" << std::endl;
        return 1;
    }
    
    std::string dbFile, dnaFile;
    for (int i = 1; i < argc; i += 2) {
        if (std::string(argv[i]) == "-d") {
            dbFile = argv[i+1];
        } else if (std::string(argv[i]) == "-s") {
            dnaFile = argv[i+1];
        }
    }
    
    Output::printWelcome();
    
    try {
        Output::printReadingFile("DNA Database");
        Database db(dbFile);

        Output::printReadingFile("Unknown DNA sequence");
        std::ifstream dnaFileStream(dnaFile);
        if (!dnaFileStream.is_open()) {
            throw std::runtime_error("Could not open DNA file");
        }
        std::string dnaSequence((std::istreambuf_iterator<char>(dnaFileStream)), std::istreambuf_iterator<char>());
        dnaFileStream.close();
        
        Output::printFilesRead();
        Output::printSearching();
        
        DNAProfile profile(dnaSequence);
        profile.analyzeSequence(db.getSTRs());
        
        std::string name;
        if (db.findMatch(profile.getProfile(), name)) {
            Output::printMatch(name, profile.getProfile());
        } else {
            Output::printNoMatch();
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
