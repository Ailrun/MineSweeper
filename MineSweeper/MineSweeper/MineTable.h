#ifndef MINETABLE_H_
#define MINETABLE_H_
#include "Type.h"
#include "Button.h"

class MineTable
{
private :
  Num_T xLen, yLen;
  Num_T mineNum;
  Button *buttons;
public :
  MineTable(Num_T x, Num_T y);
  ~MineTable();
  void randomMine(int seed);
  void giveInputToBtn(Num_T x, Num_T y, Click_T input);
  Num_T leftMine(void);
  Num_T timer(void);
};

#endif