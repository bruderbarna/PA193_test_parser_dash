#pragma once

#include "common.h"
#include <ostream>

class TxIn
{
private:
    uint256 hashPrevTrans;
    uint32_t indexPrevTrans;
    std::unique_ptr<char[]> script;
    uint32_t seqNumber;
public:
    TxIn(const char* buffer, uint32_t& globalOffset, size_t unread_size);
    friend std::ostream& operator<< (std::ostream& stream, const TxIn& tin);
};

