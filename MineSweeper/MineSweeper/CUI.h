#ifndef CUI_H_
#define CUI_H_
#ifndef UITypeYPE_GUI

#include "UI.h"
#include <iostream>

class CUIType
{
public :
  typedef char DispType;
};

class CUIBuffer : public Buffer
{
private :
  std::ostream &outputStream;
  CUIType::DispType *buffer;
  inline GlobalType::NumType getIndex(const GlobalType::NumType &x, const GlobalType::NumType &y) const;
public :
  CUIBuffer(const GlobalType::NumType &x, const GlobalType::NumType &y, std::ostream &os);
  ~CUIBuffer(void);
  virtual void draw(void) const;
  virtual void setValue(const GlobalType::NumType &x, const GlobalType::NumType &y, const CUIType::DispType &val);
};

class CUI :public UI
{
public :
  CUI(void);
  virtual ~CUI(void);
  virtual void initializing(MineTable &mt);
  virtual void giveInput(MineTable &mt); // all are output
  virtual void fillBuffer(const MineTable &mt);
  virtual void drawBuffer(void);
};

#endif
#endif