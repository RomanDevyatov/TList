
#include "TLink.h"

TLink::TLink(int _data = 0, int _shortpow = 0, TLink *_pNext = NULL)
{
    Data = _data;
    ShortPow = _shortpow;
    pNext = _pNext;
}

int TLink::GetData() const
{
    return Data;
}

int TLink::GetShortPow() const
{
    return ShortPow;
}

PLink TLink::GetpNext() const
{
    return pNext;
}

void TLink::SetData(int d)
{
    Data = d;
}

void TLink::SetShortPow(int d)
{
    ShortPow = d;
}

void TLink::SetpNext(PLink pn)
{
    pNext = pn;
}
