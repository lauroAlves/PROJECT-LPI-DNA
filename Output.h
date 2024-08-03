#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <unordered_map>
#include <string>

class Output {
public:
    static void printWelcome();
    static void printReadingFile(const std::string& fileName);
    static void printFilesRead();
    static void printSearching();
    static void printMatch(const std::string& name, const std::unordered_map<std::string, int>& profile);
    static void printNoMatch();
};

#endif
