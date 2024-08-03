#include "Output.h"

void Output::printWelcome() {
    std::cout << "Welcome to the Basic DNA Profiler v1.0\n";
    std::cout << "Copyright (C) 2021, Selan R. dos Santos\n\n";
    std::cout << "This program loads a DNA database and an unknown\n";
    std::cout << "DNA sequence and tries to find a match between\n";
    std::cout << "the input DNA sequences and the DNA database.\n\n";
}

void Output::printReadingFile(const std::string& fileName) {
    std::cout << "[Preparing to read the " << fileName << " file]\n";
}

void Output::printFilesRead() {
    std::cout << "[Input files successfully read... Please wait...]\n";
}

void Output::printSearching() {
    std::cout << "[Searching for a match... Please wait...]\n\n";
}

void Output::printMatch(const std::string& name, const std::unordered_map<std::string, int>& profile) {
    std::cout << "Match ID [99.9%]: " << name << "\n\n";
    std::cout << "DNA Profile:\n";
    for (const auto& pair : profile) {
        std::cout << pair.first << " [x" << pair.second << "] ";
    }
    std::cout << "\n";
}

void Output::printNoMatch() {
    std::cout << ">> Sorry, no match in our database.\n";
}
