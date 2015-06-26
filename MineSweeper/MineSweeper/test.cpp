#include "Shape.h"
#include <iostream>

class OpTestP
{
public :
  OpTestP(){}
  ~OpTestP(){}
  virtual int compare(const OpTestP &op) const { std::cout << "Parent" << std::endl; return 0; }
};

inline bool operator>(OpTestP &left, OpTestP &right)
{
  return (left.compare(right)>0);
}

class OpTestC : public OpTestP
{
public :
  OpTestC(){}
  ~OpTestC(){}
  virtual int compare(const OpTestP &op) const { std::cout << typeid(*this).name() << "  " << typeid(op).name() << std::endl; return 0; }
};

inline bool operator>(OpTestC &, OpTestC &) = delete;

int main(int argc, char **argv)
{
  OpTestC a;
  OpTestC b;
  OpTestP &aa = a;
  OpTestP &bb = b;
  aa > bb;
	return 0;
}
