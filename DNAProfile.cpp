#include "DNAProfile.h"

DNAProfile::DNAProfile(const std::string& sequence) : dnaSequence(sequence) {}

void DNAProfile::analyzeSequence(const std::vector<std::string>& strs) {
    for (const auto& str : strs) {
        profile[str] = findMaxConsecutiveRepeats(str);
    }
}

const std::unordered_map<std::string, int>& DNAProfile::getProfile() const {
    return profile;
}

int DNAProfile::findMaxConsecutiveRepeats(const std::string& str) const {
    int maxRepeats = 0;
    int len = str.length();
    for (size_t i = 0; i < dnaSequence.length(); ++i) {
        int count = 0;
        while (dnaSequence.substr(i, len) == str) {
            ++count;
            i += len;
        }
        if (count > maxRepeats) {
            maxRepeats = count;
        }
    }
    return maxRepeats;
}
