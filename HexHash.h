#ifndef HEXXAGON_HEXHASH_H
#define HEXXAGON_HEXHASH_H
#include "Hex.h"

namespace std
{
    /**
     * Hash function for using in unordered_map in class Board
     */
    template <> struct hash<Hex>
    {
        size_t operator()(const Hex& h) const
        {
            hash<int> int_hash;
            size_t hq = int_hash(h.q);
            size_t hr = int_hash(h.r);
            return hq ^ (hr + 0x9e3779b9 + (hq << 6) + (hq >> 2));
        }
    };
}

#endif
