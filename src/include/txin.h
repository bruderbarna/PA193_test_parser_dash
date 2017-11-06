#pragma once

#include "common.h"
#include <ostream>

class TxIn
{
private:
    uint256 hashPrevTrans;
    uint32_t indexPrevTrans;
    offsets scriptOffsets;
    uint32_t seqNumber;
public:
    TxIn(const char* buffer, uint32_t& globalOffset, size_t& unread_size);
    uint32_t GetSeqNumber() const;
    uint256 GetHashPrevTrans() const;


    friend std::ostream& operator<< (std::ostream& stream, const TxIn& tin);
    friend class TestHelper;

private:
    TxIn() {}
};

