#pragma once

#include <string.h>
#include "uint256.h"
#include <memory>
#include <invalidblocksizeexcepion.h>
#include <magicnumberexception.h>
#include <readfileexception.h>
#include <invalidtransactionsizeexcepion.h>


const char MAGIC_NUMBER[] = "\xbf\x0c\x6b\xbd";
const unsigned int MAX_BLOCKFILE_SIZE = 0x8000000; // 128 MiB
const unsigned int MAX_NUMBER_OF_BLOCKS = 10;
const uint32_t MAGIC_NUMBER_SIZE = 4;
const uint32_t BLOCK_SIZE_SIZE = 4;
const uint32_t VERSION_SIZE = 4;
const uint32_t HASH_SIZE = 32;
const uint32_t MERKLE_ROOT_SIZE = 32;
const uint32_t TIME_SIZE = 4;
const uint32_t BITS_SIZE = 4;
const uint32_t NONCE_SIZE = 4;
const uint32_t BLOCK_HEADER_SIZE = VERSION_SIZE + HASH_SIZE + MERKLE_ROOT_SIZE + TIME_SIZE + BITS_SIZE + NONCE_SIZE;
const uint32_t VALUE_SIZE = 8;


using varInt = std::pair<uint64_t,uint8_t>;
using offsets = std::pair<uint64_t,uint64_t>;

inline uint32_t ParseUint32(const char* array)
{
    uint32_t ret;
    memcpy(&ret, array, 4);
    return ret;
}

inline uint64_t ParseUint64(const char* array)
{
    uint64_t ret;
    memcpy(&ret, array, 8);
    return ret;
}

// Parse reverse array to unsigned int
/*inline uint32_t ParseUint32R(const char* array)
{
    return 0; //_0xFD_builtin_bswap32(ParseUint32(array)) - gcc function to change endian (if needed in future)
}*/


inline varInt ParseVarLength(const unsigned char* array)
{
    switch(array[0])
    {
        case 0xFD:
        {
            return varInt((*reinterpret_cast<const uint16_t*>(&array[1])), 2);
        }
        case 0xFE:
        {
            return varInt(*reinterpret_cast<const uint32_t*>(&array[1]),4);
        }
        case 0xFF:
        {
            return varInt(*reinterpret_cast<const uint64_t*>(&array[1]), 8);
        }
    default:
        return varInt(reinterpret_cast<uint8_t>(array[0]),1);
    }
}

inline varInt ParseVarLength(const char* array)
{
    return ParseVarLength(reinterpret_cast<const unsigned char*>(array));
}
