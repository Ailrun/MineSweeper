#ifndef UI_H_
#define UI_H_

#define UITypeYPE_CUI
//#define UITypeYPE_GUI

#include "MineTable.h"

class Buffer
{
private :
  GlobalType::NumType xLen, yLen;
public :
  Buffer(void);
  ~Buffer(void);
  inline GlobalType::NumType getXLen() const { return xLen; }
  inline GlobalType::NumType getYLen() const { return yLen; }
  inline void setXLen(const GlobalType::NumType &xLen) { this->xLen = xLen; }
  inline void setYLen(const GlobalType::NumType &yLen) { this->yLen = yLen; }
  virtual void setValue(GlobalType::NumType &x, GlobalType::NumType &y) = 0;
  virtual void draw(void) const = 0;
};

class UI
{
private :
  Buffer *outputBuffer;
  bool quit;
protected :
  inline Buffer &getBuffer(void) { return *outputBuffer; }
  inline void setBuffer(Buffer &b) { outputBuffer = &b; }
public :
  typedef enum {button, start, quit} ButtonType;
  UI(void) {}
  virtual ~UI(void) {}
  inline bool isQuit(void) const { return quit; }
  virtual void initializing(MineTable &mt) = 0;
  virtual void giveInput(MineTable &mt) = 0;
  virtual void fillBuffer(const MineTable &mt) = 0;
  virtual void drawBuffer(void) = 0;
};

#endif