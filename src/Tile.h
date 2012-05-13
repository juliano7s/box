
#ifndef TILE_H
#define TILE_H

#include <string>

namespace Box
{
    class Tile
    {
    public:
        Tile();
        Tile(std::string tileTypeName);

    public:
        std::string typeName() { return mTypeName; }

    private:
        std::string mTypeName;
    };
};

#endif //TILE_H