#ifndef CUI_H_
#define CUI_H_
#include "UI.h"

class CUI_Buffer : public Buffer
{

};

class CUI :public UI
{
private :
  virtual void initializing();
  virtual void getInput(Num_T &x, Num_T &y);
  virtual void putOutput(Num_T &x, Num_T &y);
  virtual void clickButton(Num_T &x, Num_T &y);
  virtual void clickStart(bool &isStart);
public :
  CUI(void);
  virtual ~CUI(void);
  virtual void getBuffer(void);
  virtual void drawBuffer(void);
};

#endif