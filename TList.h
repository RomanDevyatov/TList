#ifndef _TList_H_
#define _TList_H_

#include "TLink.h"

class TList
{
private:
    PLink Head;
    unsigned int Size;

public:
    TList();
    ~TList();
    void InsFirst(int, int);
    void InsLast(int, int);
    void Insert(int Data, int ShortPow);
    void PrintList(void);
    int IsEmpty(void);
    int IsBusy(void);
    int GetSize();
    void Summing1(TList b);
    TList Summing2(TList b);
    void CorrectForm();
};
#endif