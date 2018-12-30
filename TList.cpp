#include "TList.h"

TList::TList()
{
    Head = new TLink(0, -1, Head);
    if (Head != NULL)
    {
        Head->SetpNext(Head);
    }
    else
        throw "Memory";

    Size = 0;
    /*
  //Head = NULL;
  /*Tail = NULL;

  //Head->SetpNext(Head->GetData());

  Head  =  0  by  dafault    */
}

TList::~TList()
{
    /*while (Size != 0)
  {
  PLink tmp = Head->GetpNext();
  delete Head;
  Head = tmp;
  Size--;
  }*/
}

void TList::InsFirst(int Data, int ShortPow)
{
    PLink tmpHead = Head;

    tmpHead = tmpHead->GetpNext();

    PLink p = new TLink(Data, ShortPow, tmpHead);
    if (p != NULL)
    {
        Head->SetpNext(p);
        Size++;
    }
    else
        throw "Memory";
}

void TList::InsLast(int Data, int ShortPow)
{
    PLink p = new TLink(Data, ShortPow, Head);
    PLink tmpHead = Head;
    PLink prev;

    if (p != NULL)
    {
        do
        {
            prev = tmpHead;
            tmpHead = tmpHead->GetpNext();
            //cout << tmpHead -> GetData() << endl;
        } while (tmpHead->GetShortPow() != -1);
        prev->SetpNext(p);
        Size++;
    }
    else
        throw "Memory";    
}

void TList::Insert(int Data, int ShortPow)
{
    if (Data != 0)
    {
        if (IsEmpty())
            InsFirst(Data, ShortPow);
        else
        {
            PLink
                tmpHead = Head,
                prev;
            int num = 0;

            do
            {
                prev = tmpHead;
                tmpHead = tmpHead->GetpNext();
                //cout << tmpHead->GetData() << endl;
                num = tmpHead->GetShortPow();

                if (ShortPow > num)
                {
                    PLink p = new TLink(Data, ShortPow, tmpHead);
                    if (p != 0)
                    {
                        prev->SetpNext(p);
                        Size++;
                    }
                }
                else if (ShortPow == num)
                {
                    tmpHead->SetData(2 * (tmpHead->GetData()));
                    cout << "warning, the same symbols, element amount are not changed";
                }
            } while (tmpHead->GetShortPow() != -1 && ShortPow < num);
            if (ShortPow < num)
                InsLast(Data, ShortPow);
        }
    }
}

void TList::PrintList(void)
{
    PLink tmpHead = Head;
    int flag = 0;

    tmpHead = tmpHead->GetpNext();
    do
    {
        int
            data = tmpHead->GetData(),
            x = (tmpHead->GetShortPow()) / 100,
            y = ((tmpHead->GetShortPow()) % 100) / 10,
            z = (tmpHead->GetShortPow()) % 10;

        if (data != 0)
        {
            if (abs(data) != 1)
            {
                if (flag == 1 && data > 0)
                    cout << " + ";
                cout << data;

                if (x != 0)
                {
                    cout << "*x";
                    if (x > 1)
                        cout << "^" << x;
                }

                if (y != 0)
                {
                    cout << "*y";
                    if (y > 1)
                        cout << "^" << y;
                }

                if (z != 0)
                {
                    cout << "*z";
                    if (z > 1)
                        cout << "^" << z;
                }
            }
            else if (abs(data) == 1)
            {
                if (data == 1 && flag == 1)
                    cout << " + ";
                if (data == -1)
                    cout << " - ";

                if (x != 0)
                {
                    cout << "x";
                    if (x > 1)
                        cout << "^" << x;
                    //star set
                    if (y != 0)
                        cout << "*";
                    else if (z != 0)
                        cout << "*";
                }

                if (y != 0)
                {
                    cout << "y";
                    if (y > 1)
                        cout << "^" << y;
                    //star set
                    if (z != 0)
                        cout << "*";
                }

                if (z != 0)
                {
                    cout << "z";
                    if (z > 1)
                        cout << "^" << z;
                }
            }
        }        
        tmpHead = tmpHead->GetpNext();
        flag = 1;
    } while (tmpHead->GetShortPow() != -1);
    //cout << " = 0" << endl << endl;
    cout 
        << endl
        << endl;
}

int TList::IsEmpty(void)
{
    int res;
    if ((Head->GetpNext())->GetShortPow() == -1)
        res = 1;
    else
        res = 0;
    return res;
}

void TList::Summing1(TList b) //destroying a current List
{
    PLink 
        bHead = b.Head,
        curr1 = Head,
        prev1 = curr1,
        curr2 = b.Head,
        prev2 = curr2;

    int num1 = 0,
        num2 = 0,
        flag = 1;

    do
    {
        if (flag == 1)
        {
            curr1 = curr1->GetpNext(); //moving pointer to the first element after had in each list
            curr2 = curr2->GetpNext();
        }

        num1 = curr1->GetShortPow();
        num2 = curr2->GetShortPow();

        if (num1 > num2)
        {
            prev1 = curr1;
            curr1 = curr1->GetpNext();

            flag = 0;
        }
        else if (num1 < num2)
        {
            prev2->SetpNext(curr2->GetpNext()); // bHead to the next after curr2
            curr2->SetpNext(curr1);             // curr2 to the curr1
            prev1->SetpNext(curr2);             // prev1 to the curr2
                                                //clean making
            curr1 = prev1;
            curr2 = prev2;

            Size++;
            flag = 1;
        }
        else if (num1 == num2)
        {
            prev2->SetpNext(curr2->GetpNext());
            curr1->SetData(curr1->GetData() + curr2->GetData());
            curr2->SetpNext(NULL);
            curr2 = NULL;
            delete curr2;

            curr1 = prev1;
            curr2 = prev2;
            flag = 1;
        }
    } while ((bHead->GetpNext())->GetShortPow() != -1);
}

TList TList::Summing2(TList b) //with an additional List
{
    TList res;
    PLink bHead = b.Head;

    int
        num1 = 0,
        num2 = 0;

    PLink curr1 = new TLink(0, 0, Head->GetpNext());
    PLink curr2 = new TLink(0, 0, b.Head->GetpNext());

    //cout << "Size tmp in  = " << res.GetSize() << endl;

    curr1 = curr1->GetpNext();
    curr2 = curr2->GetpNext();

    while (1)
    {
        //curr1 = curr1->GetpNext();    //moving pointer to the first element in each list
        //curr2 = curr2->GetpNext();
        //cout << "curr1: " << curr1->GetShortPow() << endl;
        //cout << "curr2: " << curr2->GetShortPow() << endl << endl;
        num1 = curr1->GetShortPow();
        num2 = curr2->GetShortPow();

        if ((num1 == -1) && (num2 == -1))
            break;

        if (num1 > num2)
        {
            //cout << "GetpNext1: " << (curr1->GetpNext())->GetShortPow() << endl;
            Head->SetpNext(curr1->GetpNext());

            res.InsLast(curr1->GetData(), curr1->GetShortPow());

            curr1 = curr1->GetpNext();

            Size--;
        }
        else if (num1 < num2)
        {
            //cout << "GetpNext2: " << curr2->GetpNext()->GetShortPow() << endl;
            b.Head->SetpNext(curr2->GetpNext());

            res.InsLast(curr2->GetData(), curr2->GetShortPow());

            curr2 = curr2->GetpNext();

            b.Size--;
        }
        else if (num1 == num2)
        {
            res.InsLast(curr1->GetData() + curr2->GetData(), curr1->GetShortPow());

            /*prev1->SetpNext(curr1->GetpNext());
            prev2->SetpNext(curr2->GetpNext());*/

            curr1 = curr1->GetpNext();
            curr2 = curr2->GetpNext();
            Size--;
            b.Size--;
            /*cout << "curr1: " << curr1->GetShortPow() << endl;
      cout << "curr2: " << curr2->GetShortPow() << endl;*/
        }
        res.Size++;
        //cout << "fuck "<<(bHead->GetpNext())->GetData() << endl;
    }
    //cout << "Size tmp in  2= " << res.GetSize() << endl;
    return res;
}

void TList::CorrectForm()
{
    /*PLink curr = new TLink(0, 0, Head->GetpNext());
  PLink prev = new TLink(0, 0, Head->GetpNext());*/
    PLink 
        curr = Head,
        prev = curr;
    curr = curr->GetpNext();

    while (curr->GetShortPow() != -1)
    {
        /*cout << "data curr: " << curr->GetData() << endl;
    cout << "pow curr: " << curr->GetShortPow() << endl << endl;

    cout << "data prev: " << prev->GetData() << endl;
    cout << "pow prev: " << prev->GetShortPow() << endl;*/
        if (curr->GetData() == 0)
        {
            prev->SetpNext(curr->GetpNext()); // перевигаем который указывает на текущий вперед
            //curr->SetpNext(nullptr);// указываем текущий на налл
            //delete[] curr;// удаляем выделенную память для текущего
            curr = prev;
            curr = curr->GetpNext();
            /*cout << "pow prev: " << prev->GetShortPow() << endl;
      cout<< "pow curr: "<<curr->GetShortPow()<<endl << endl;*/
        }
        else
        {
            curr = curr->GetpNext();
            prev = curr->GetpNext();
        }
    }
}

int TList::GetSize()
{
    return Size; //Возвращаем число элементов списка
}
