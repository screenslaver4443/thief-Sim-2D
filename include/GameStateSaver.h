#ifndef GAMESTATESAVER_H
#define GAMESTATESAVER_H

#include "Savable.h"
#include <string>
#include <fstream>

class GameStateSaver : public Savable
{
private:
    int *target = nullptr;

public:
    GameStateSaver() = default;
    void setTarget(int *t) { target = t; }

    bool saveToFile(const std::string &path) const override
    {
        if (!target)
            return false;
        std::ofstream ofs(path);
        if (!ofs.is_open())
            return false;
        ofs << *target << "\n";
        ofs.close();
        return true;
    }

    bool loadFromFile(const std::string &path) override
    {
        if (!target)
            return false;
        std::ifstream ifs(path);
        if (!ifs.is_open())
            return false;
        int v;
        ifs >> v;
        if (ifs.fail())
        {
            ifs.close();
            return false;
        }
        *target = v;
        ifs.close();
        return true;
    }

    std::string getSaveId() const override { return "gamestate"; }
};

#endif
