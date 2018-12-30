#include "TList.h"

void SetMonom(TList tmp);
int flag = 0;

int main(void)
{
  TList A, B, C, D, tmp;
  int m;
  
  //**************************************
    cout << "Set a POLYNOM A:" << endl;
    SetMonom(A);

    cout << endl << "Set a POLYNOM B:" << endl;
    SetMonom(B);

  /*A.Insert(2, 222);
  A.Insert(1, 111);

  B.Insert(-2, 222);
  B.Insert(-1, 111);*/

  cout << endl << endl;

  /*cout << "A:" << endl;
  A.PrintList();

  cout << "B:" << endl;
  B.PrintList();*/


  if (A.IsEmpty() == 1 && B.IsEmpty() == 1)
    cout << "A and B are EMPTY" << endl;
  else if (A.IsEmpty() == 0 && B.IsEmpty() == 1)
  {
    cout << "B is EMPTY";
    B.PrintList();
  }
  else if (A.IsEmpty() == 1 && B.IsEmpty() == 0)
  {
    cout << "B is EMPTY" << endl;
    B.PrintList();
  }
  else if (A.IsEmpty() == 0 && B.IsEmpty() == 0)
  {	
	cout << "A:" << endl;
	A.PrintList();
	
    cout << "B:" << endl;
    B.PrintList();

    cout << "Sum 1" << endl;
    tmp = A.Summing2(B);
    tmp.CorrectForm();
    if (tmp.IsEmpty() == 1)
      cout << "result is EMPTY" << endl;
    else
    tmp.PrintList();    
  }
  //**************************************
  cout << "Set a POLYNOM C:" << endl;
  SetMonom(C);

  cout << endl << "Set a POLYNOM D:" << endl;
  SetMonom(D);

  /*C.Insert(2, 222);
  C.Insert(1, 111);

  D.Insert(-2, 222);
  D.Insert(-1, 111);*/
  
  if (C.IsEmpty() == 1 && D.IsEmpty() == 1)
    cout << "C and D are EMPTY" << endl;
  else if (C.IsEmpty() == 0 && D.IsEmpty() == 1)
  {
    cout << "List D is EMPTY";
    C.PrintList();
  }
  else if (C.IsEmpty() == 1 && D.IsEmpty() == 0)
  {
    cout << "List C is EMPTY" << endl;
    D.PrintList();
  }
  else if (C.IsEmpty() == 0 && D.IsEmpty() == 0)
  {
    cout << "C:" << endl;
    C.PrintList();

    cout << "D:" << endl;
    D.PrintList();

    cout << "Sum 1" << endl;
    C.Summing1(D);
    C.CorrectForm();
    if (C.IsEmpty() == 1)
      cout << "result is EMPTY" << endl;
    else
      C.PrintList();
  }
  

  

  system("pause");
  return 0;
}


void SetMonom(TList tmp)
{
  int
    pow = NULL,
    pow1 = NULL,
    pow2 = NULL,
    pow3 = NULL,
    coef = NULL,
    t = NULL;

  while (1)
  {
    do {
      cout << "Do you want to set a monom?(1-yes, 0- no)" << endl;
      cin >> t;
    } while (t>1 || t<0);
    if (t == 1)
    {
      cout << "Set a coefficient" << endl;
      cin >> coef;
	  
      do
      {
        cout << "Write a power of 'X'" << endl;
        cin >> pow1;
      } while (pow1 < 0 || pow1 > 9);

      do
      {
        cout << "Write a power of 'Y'" << endl;
        cin >> pow2;
	  } while (pow2 < 0 || pow2 > 9);

      do
      {
        cout << "Write a power of 'Z'" << endl;
        cin >> pow3;
      } while (pow3 < 0 || pow3 > 9);

      pow = 100 * pow1 + 10 * pow2 + 1 * pow1;
      tmp.Insert(coef, pow);

	  tmp.CorrectForm();
      cout << endl;
    }
    else break;
  }
}




