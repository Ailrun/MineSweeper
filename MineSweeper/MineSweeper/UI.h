#ifndef UI_H_
#define UI_H_

#include "MineTable.h"

class Buffer
{
};

class UI
{
private :
  Buffer *buffer;
  MineTable mineTable;
  bool quit;
  virtual void initializing() = 0;
  virtual void getInput(Num_T &x, Num_T &y) = 0;
  virtual void putOutput(Num_T &x, Num_T &y) = 0;
  virtual void clickButton(Num_T &x, Num_T &y) = 0;
  virtual void clickStart(bool &isStart) = 0;
public :
  UI(void);
  virtual ~UI(void);
  virtual bool isQuit(void) const { return quit; }
  virtual void getBuffer(void) = 0;
  virtual void drawBuffer(void) = 0;
};

#endif