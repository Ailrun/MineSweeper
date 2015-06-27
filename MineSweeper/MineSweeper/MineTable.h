#ifndef MINETABLE_H_
#define MINETABLE_H_
#include "Type.h"
#include "Button.h"

class MineTable
{
private :
  GlobalType::NumType xLen, yLen;
  GlobalType::NumType mineNum;
  Button *buttons;
public :
  MineTable(GlobalType::NumType x = 20, GlobalType::NumType y = 20);
  virtual ~MineTable(void);
  void randomMine(int seed);
  void giveInputToBtn(GlobalType::NumType x, GlobalType::NumType y, GlobalType::ClickType input);
  GlobalType::NumType leftMine(void);
  GlobalType::NumType timer(void);
};

#endif