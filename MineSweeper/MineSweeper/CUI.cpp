#include "CUI.h"
#include <stdexcept>

#ifndef UITypeYPE_GUI

GlobalType::NumType CUIBuffer::getIndex(const GlobalType::NumType &x, const GlobalType::NumType &y) const
{
  return y*getXLen() + x;
}

CUIBuffer::CUIBuffer(const GlobalType::NumType &x, const GlobalType::NumType &y, std::ostream &os) : outputStream(os)
{
  buffer = new CUIType::DispType[x*y];
}

CUIBuffer::~CUIBuffer(void)
{
  delete[] buffer;
}

void CUIBuffer::setValue(const GlobalType::NumType &x, const GlobalType::NumType &y, const CUIType::DispType &val)
{
  if (x < getXLen() && y < getYLen())
  {
    buffer[getIndex(x,y)] = val;
  }
  else
  {
    throw std::invalid_argument("Invalid argument in x / y of CUIBuffer::setValue");
  }
}

void CUIBuffer::draw(void) const
{

}

#endif

//찾아볼 키워드 : 군인 지뢰찾기???