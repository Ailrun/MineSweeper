#ifndef MINETABLE_H_
#define MINETABLE_H_
#include "Type.h"

class MineTable
{
private :
  Num_T xLen, yLen;
  Num_T mineNum;
public :
  MineTable();
  ~MineTable();
  void randomMine(int seed);
  void giveInputToBtn(Num_T x, Num_T y, Click_T input);
  Num_T leftMine(void);
  Num_T timer(void);
};

#endif