#ifndef _TLink_H_
#define _TLink_H_

#include <iostream>
using namespace std;

class TLink;
typedef TLink *PLink;

class TLink
{
private:
    int
        Data,
        ShortPow;
    TLink *pNext;

public:
    TLink(int, int, TLink *);

    void SetData(int d);
    int GetData() const;
    int GetShortPow() const;
    void SetShortPow(int d);

    PLink GetpNext() const;
    void SetpNext(PLink pn);
};
#endif