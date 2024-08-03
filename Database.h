#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <unordered_map>

class Database {
public:
    Database(const std::string& filename);
    bool findMatch(const std::unordered_map<std::string, int>& profile, std::string& name) const;
    const std::vector<std::string>& getSTRs() const; // Adicionado
    
private:
    std::vector<std::string> strs;
    std::vector<std::unordered_map<std::string, int>> profiles;
    std::vector<std::string> names;
    
    void loadDatabase(const std::string& filename);
};

#endif
