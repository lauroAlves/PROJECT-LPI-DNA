#ifndef DNAPROFILE_H
#define DNAPROFILE_H

#include <string>
#include <vector>
#include <unordered_map>

class DNAProfile {
public:
    DNAProfile(const std::string& sequence);
    void analyzeSequence(const std::vector<std::string>& strs);
    const std::unordered_map<std::string, int>& getProfile() const;
    
private:
    std::string dnaSequence;
    std::unordered_map<std::string, int> profile;

    int findMaxConsecutiveRepeats(const std::string& str) const;
};

#endif
