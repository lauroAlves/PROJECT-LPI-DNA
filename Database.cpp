#include "Database.h"
#include <fstream>
#include <sstream>

Database::Database(const std::string& filename) {
    loadDatabase(filename);
}

void Database::loadDatabase(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    
    std::string line;
    if (getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        getline(ss, item, ','); // Skip the "name" column
        while (getline(ss, item, ',')) {
            strs.push_back(item);
        }
    }
    
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        getline(ss, name, ',');
        names.push_back(name);
        
        std::unordered_map<std::string, int> profile;
        for (const auto& str : strs) {
            std::string count;
            getline(ss, count, ',');
            profile[str] = std::stoi(count);
        }
        profiles.push_back(profile);
    }
}

const std::vector<std::string>& Database::getSTRs() const {
    return strs;
}

bool Database::findMatch(const std::unordered_map<std::string, int>& profile, std::string& name) const {
    for (size_t i = 0; i < profiles.size(); ++i) {
        if (profiles[i] == profile) {
            name = names[i];
            return true;
        }
    }
    return false;
}
