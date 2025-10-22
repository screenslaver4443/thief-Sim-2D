
#ifndef SAVABLE_H
#define SAVABLE_H
// handles save fille

#include <string>

class Savable
{
public:
    virtual ~Savable() = default;

    virtual bool saveToFile(const std::string &path) const = 0;

    virtual bool loadFromFile(const std::string &path) = 0;
    virtual std::string getSaveId() const = 0;
};

#endif
