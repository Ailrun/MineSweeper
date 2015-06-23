#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>
#include <exception>

//Shape class template : abstract class
//----Declaration

class Basic_Shape
{
private :
  int dimension;
protected :
  void setDimension(const int dim = 2){ dimension = dim; }
public :
  Basic_Shape(const int dim = 2){ dimension = dim; }
  int getDimension(void){ return dimension; }
  virtual void changeAxes(const int axe0 = 0, const int axe1 = 1) = 0;
  virtual void changeDimension(const int changeDim = 2) = 0;
};


//Basic_Point class template
//----Declaration

template<typename Pos>
class Basic_Point : public Basic_Shape
{
private :
  Pos *position;
public :
  Basic_Point(const Pos *pos = nullptr, const int dim = 2);
  Basic_Point(const Basic_Point<Pos> &p);
  Basic_Point(const Basic_Point<Pos> &&p);
  ~Basic_Point();
  Basic_Point<Pos> &operator=(const Basic_Point<Pos> &p);
  Basic_Point<Pos> &operator=(const Basic_Point<Pos> &&p);
  Basic_Point<Pos> &operator+=(const Basic_Point<Pos> &p);
  Basic_Point<Pos> &operator+=(const Basic_Point<Pos> &&p);
  Basic_Point<Pos> &operator-=(const Basic_Point<Pos> &p);
  Basic_Point<Pos> &operator-=(const Basic_Point<Pos> &&p);
  Basic_Point<Pos> operator-(void) const;
  Basic_Point<Pos> operator+(const Basic_Point<Pos> &p) const;
  Basic_Point<Pos> operator+(const Basic_Point<Pos> &&p) const;
  Basic_Point<Pos> operator-(const Basic_Point<Pos> &p) const;
  Basic_Point<Pos> operator-(const Basic_Point<Pos> &&p) const;
  Basic_Point<Pos> operator*(const Basic_Point<Pos> &p) const;
  Basic_Point<Pos> operator*(const Basic_Point<Pos> &&p) const;
  Pos &operator[](const int ind);
  bool operator==(const Basic_Point<Pos> &p);
  bool operator!=(const Basic_Point<Pos> &p);
  virtual void changeAxes(const int axe0 = 0, const int axe1 = 1);
  virtual void changeDimension(const int changeDim = 2);
};

//Basic_Point class template
//--Definition

template<typename Pos>
Basic_Point<Pos>::Basic_Point(const Pos *pos, const int dim) : Basic_Shape(dim)
{
  position = new Pos[dim];
  if (pos != nullptr)
  {
    for (int ind = 0; ind < dim; ind++)
    {
      position[ind] = pos[ind];
    }
  }
  else
  {
    for (int ind = 0; ind < dim; ind++)
    {
      position[ind] = 0;
    }
  }
}

template<typename Pos>
Basic_Point<Pos>::Basic_Point(const Basic_Point<Pos> &p) : Basic_Shape(p)
{
  position = new Pos[p.getDimension()];
  for (int ind = 0; ind < p.getDimension(); ind++)
  {
    position[ind] = p.position[ind];
  }
}

template<typename Pos>
Basic_Point<Pos>::Basic_Point(const Basic_Point<Pos> &&p) : Basic_Shape(p)
{
  position = p.position;
  p.position = nullptr;
}

template<typename Pos>
Basic_Point<Pos>::~Basic_Point()
{
  if (position != nullptr)
  {
    delete[] position;
  }
}

template<typename Pos>
Basic_Point<Pos> &Basic_Point<Pos>::operator=(const Basic_Point<Pos> &p)
{
  delete[] position;
  position = new Pos[p.getDimension()];
  setDimension(p.getDimension());
  return this;
}

template<typename Pos>
Basic_Point<Pos> &Basic_Point<Pos>::operator=(const Basic_Point<Pos> &&p)
{
  delete[] position;
  setDimension(p.getDimension());
  position = p.position;
  p.position = nullptr;
  return this;
}

template<typename Pos>
virtual void Basic_Point<Pos>::changeAxes(const int axe0, const int axe1)
{
  int currentDim = getDimension();
  if (axe1 == axe0 &&
    axe0 > -1 && axe0 < currentDim &&
    axe1 < currentDim && axe1 > -1)
  {
    Pos temp = position[axe0];
    position[axe0] = position[axe1];
    position[axe1] = temp;
  }
  else
  {
    throw std::exception("Invalid argument in axe0 / axe1");
  }
}

template<typename Pos>
virtual void Basic_Point<Pos>::changeDimension(const int changeDim)
{
  if (getDimension() != changeDim)
  {
    Pos *temp = position;
    position = new Pos[changeDim];
    for (int ind = 0; ind < getDimension(); ind++)
    {
      position[ind] = temp[ind];
    }
    // when getDimension() > changeDim, this area does not work
    for (int ind = getDimension(); ind < changeDim; ind++)
    {
      position[ind] = 0;
    }
    setDimension(changeDim);
    delete[] temp;
  }
}


//Basic_Line class template
//----Declaration

template<typename Pos>
class Basic_Line : public Basic_Shape
{
private :
  Basic_Point<Pos> point[2];
public :
  Basic_Line(const Basic_Point<Pos> *p = nullptr, const int dim = 2);
  Basic_Line(const Basic_Point<Pos> &p0, const Basic_Point<Pos> &p1, const int dim = 2);
  bool isContain(const Basic_Point<Pos> &p);
  virtual void changeAxes(const int axe0 = 0, const int axe1 = 1);
  virtual void changeDimension(const int dim);
};

template<typename Pos>
Basic_Line<Pos>::Basic_Line(const Basic_Point<Pos> *p, const int dim)
{
  if (p != nullptr && p[0].getDimension() == p[1].getDimension() && p0 != p1)
  {
    point[0] = p[0];
    point[1] = p[1];
  }
}

//Basic_Plane class template
//----Declaration

template<typename Pos>
class Basic_Plane : public Basic_Shape
{
private :
  Basic_Point<Pos> point[3];
public :
  Basic_Plane(const Basic_Point<Pos> *p = nullptr, const int dim = 2);
  Basic_Plane(const Basic_Point<Pos> &p0, const Basic_Point<Pos> &p1, const Basic_Point<Pos> &p2, const int dim = 2);
  bool isContain(const Basic_Point<Pos> &p);
  virtual void changeAxes(const int axe0 = 0, const int axe1 = 1);
  virtual void changeDimension(const int dim);
};

//Basic_Plane class template
//--Definition

template<typename Pos>
Basic_Plane<Pos>::Basic_Plane(Basic_Point<Pos> *p, int dim) : Basic_Shape(dim)
{
  point[0] = p[0];
  point[1] = p[1];
  point[2] = p[2];
}

template<typename Pos>
Basic_Plane<Pos>::Basic_Plane(Basic_Point<Pos> p0, Basic_Point<Pos> p1, Basic_Point<Pos> p2, int dim) : Basic_Shape(dim)
{
  point[0] = p0;
  point[1] = p1;
  point[2] = p2;
}

template<typename Pos>
bool Basic_Plane<Pos>::isContain(Basic_Point<Pos> p)
{
  return true;
}

template<typename Pos>
class Basic_Rect : public Basic_Shape
{
private :
  Basic_Point<Pos> p[2];
  Basic_Plane<Pos> inPlane;
public :

};

#endif //SHAPE_H_