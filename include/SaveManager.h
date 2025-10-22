#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <vector>
#include <string>
#include "Savable.h"

class SaveManager
{
private:
    std::vector<Savable *> registry;

public:
    void registerSavable(Savable *s) { registry.push_back(s); }

    // Save all registered objects into directory (files named <id>.sav)
    bool saveAll(const std::string &dir) const
    {
        for (auto *s : registry)
        {
            std::string path = dir + "/" + s->getSaveId() + ".sav";
            if (!s->saveToFile(path))
                return false;
        }
        return true;
    }

    bool loadAll(const std::string &dir) const
    {
        for (auto *s : registry)
        {
            std::string path = dir + "/" + s->getSaveId() + ".sav";
            if (!s->loadFromFile(path))
                return false;
        }
        return true;
    }
};

#endif
