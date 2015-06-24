#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>
#include <stdexcept>

//Shape class template : abstract class
//----Declaration

class Basic_Shape
{
private :
  int dimension;
public :
  Basic_Shape(const int dim = 2){ dimension = (dim > 0) ? dim : 1; }
  virtual ~Basic_Shape();
  int getDimension(void) const { return dimension; }
  virtual int compare(const Basic_Shape &s) const;
  virtual int compare(const int &dim) const;
  virtual void setDimension(const int newDim = 2){ dimension = (newDim > 0) ? newDim : 1; }
  virtual void changeAxes(const int axe0 = 0, const int axe1 = 1) = 0;

  friend inline bool operator==(const Basic_Shape &left, const Basic_Shape &right);
  friend inline bool operator==(const int &left, const Basic_Shape &right);
  friend inline bool operator==(const Basic_Shape &left, const int &right);
  friend inline bool operator!=(const Basic_Shape &left, const Basic_Shape &right);
  friend inline bool operator!=(const int &left, const Basic_Shape &right);
  friend inline bool operator!=(const Basic_Shape &left, const int &right);
  friend inline bool operator>(const Basic_Shape &left, const Basic_Shape &right);
  friend inline bool operator>(const Basic_Shape &left, const Basic_Shape &right);
  friend inline bool operator>(const Basic_Shape &left, const Basic_Shape &right);
  friend inline bool operator>=(const Basic_Shape &left, const Basic_Shape &right);
  friend inline bool operator>=(const int &left, const Basic_Shape &right);
  friend inline bool operator>=(const Basic_Shape &left, const int &right);
  friend inline bool operator<(const Basic_Shape &left, const Basic_Shape &right);
  friend inline bool operator<(const int &left, const Basic_Shape &right);
  friend inline bool operator<(const Basic_Shape &left, const int &right);
  friend inline bool operator<=(const Basic_Shape &left, const Basic_Shape &right);
  friend inline bool operator<=(const int &left, const Basic_Shape &right);
  friend inline bool operator<=(const Basic_Shape &left, const int &right);
};

//Basic_Shape class template
//--Definition

//Basic_Shape_Member_Function
int Basic_Shape::compare(const Basic_Shape &s) const
{
  return dimension - s.dimension;
}
int Basic_Shape::compare(const int &dim) const
{
  return dimension - dim;
}

//Basic_Shape_Operator
inline bool operator==(const Basic_Shape &left, const Basic_Shape &right)
{
  return (left.compare(right) == 0);
}
inline bool operator==(const int &left, const Basic_Shape &right)
{
  return (right.compare(left) == 0);
}
inline bool operator==(const Basic_Shape &left, const int &right)
{
  return (left.compare(right) == 0);
}

inline bool operator!=(const Basic_Shape &left, const Basic_Shape &right)
{
  return !(left==right);
}
inline bool operator!=(const int &left, const Basic_Shape &right)
{
  return !(left == right);
}
inline bool operator!=(const Basic_Shape &left, const int &right)
{
  return !(left == right);
}
inline bool operator>(const Basic_Shape &left, const Basic_Shape &right)
{
  return (left.compare(right) > 0);
}
inline bool operator>(const int &left, const Basic_Shape &right)
{
  return (right.compare(right) < 0);
}
inline bool operator>(const Basic_Shape &left, const int &right)
{
  return (left.compare(right) > 0);
}
inline bool operator>=(const Basic_Shape &left, const Basic_Shape &right)
{
  return !(left.compare(right) < 0);
}
inline bool operator>=(const int &left, const Basic_Shape &right)
{
  return !(right.compare(left) > 0);
}
inline bool operator>=(const Basic_Shape &left, const int &right)
{
  return !(left.compare(right) < 0);
}
inline bool operator<(const Basic_Shape &left, const Basic_Shape &right)
{
  return (right>left);
}
inline bool operator<(const int &left, const Basic_Shape &right)
{
  return (right>left);
}
inline bool operator<(const Basic_Shape &left, const int &right)
{
  return (right>left);
}
inline bool operator<=(const Basic_Shape &left, const Basic_Shape &right)
{
  return (right>=left);
}
inline bool operator<=(const int &left, const Basic_Shape &right)
{
  return (right >= left);
}
inline bool operator<=(const Basic_Shape &left, const int &right)
{
  return (right >= left);
}


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
  virtual ~Basic_Point();
  virtual Pos &at(const int ind);
  virtual const Pos &at(const int ind) const;
  virtual int compare(const Basic_Point<Pos> &p);
  virtual int compare(const int &dim);
  virtual void setDimension(const int newDim = 2);
  virtual void changeAxes(const int axe0 = 0, const int axe1 = 1);
  virtual Pos begin() const;
  virtual Pos end() const;
  virtual Basic_Point<Pos> &operator=(const Basic_Point<Pos> &p);
  virtual Basic_Point<Pos> &operator=(const Basic_Point<Pos> &&p);
  virtual Basic_Point<Pos> &operator+=(const Basic_Point<Pos> &p);
  virtual Basic_Point<Pos> &operator+=(const Basic_Point<Pos> &&p);
  virtual Basic_Point<Pos> &operator-=(const Basic_Point<Pos> &p);
  virtual Basic_Point<Pos> &operator-=(const Basic_Point<Pos> &&p);
  virtual Basic_Point<Pos> &operator*=(const Pos &m);
  virtual Basic_Point<Pos> &operator/=(const Pos &d);

  friend Pos &operator[](const Basic_Point<Pos> &obj, const int ind);
  friend const Pos &operator[](const Basic_Point<Pos> &obj, const int ind);
  friend bool operator==(const Basic_Point<Pos> &left, const Basic_Point<Pos> &right);
  friend bool operator!=(const Basic_Point<Pos> &left, const Basic_Point<Pos> &right);
  friend Basic_Point<Pos> operator-(const Basic_Point<Pos> &p);
  friend Basic_Point<Pos> operator-(const Basic_Point<Pos> &p);
  friend Basic_Point<Pos> operator+(const Basic_Point<Pos> &left, const Basic_Point<Pos> &right);
  friend Basic_Point<Pos> operator+(Basic_Point<Pos> &&left, const Basic_Point<Pos> &right);
  friend Basic_Point<Pos> operator+(const Basic_Point<Pos> &left, Basic_Point<Pos> &&right);
  friend Basic_Point<Pos> operator+(Basic_Point<Pos> &&left, Basic_Point<Pos> &&right);
  friend Basic_Point<Pos> operator-(const Basic_Point<Pos> &left, const Basic_Point<Pos> &right);
  friend Basic_Point<Pos> operator-(Basic_Point<Pos> &&left, const Basic_Point<Pos> &right);
  friend Basic_Point<Pos> operator-(const Basic_Point<Pos> &left, Basic_Point<Pos> &&right);
  friend Basic_Point<Pos> operator-(Basic_Point<Pos> &&left, Basic_Point<Pos> &&right);
  friend Basic_Point<Pos> operator*(const Basic_Point<Pos> &left, const Pos &right);
  friend Basic_Point<Pos> operator*(Basic_Point<Pos> &&left, const Pos &right);
  friend Basic_Point<Pos> operator*(const Pos &left, const Basic_Point<Pos> &right);
  friend Basic_Point<Pos> operator*(const Pos &left, Basic_Point<Pos> &&right);
  friend Basic_Point<Pos> operator/(const Basic_Point<Pos> &left, const Pos &right);
  friend Basic_Point<Pos> operator/(Basic_Point<Pos> &&left, const Pos &right);
};

//Basic_Point class template
//--Definition

//Basic_Point_Constructor
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

//Basic_Point_Destructor
template<typename Pos>
Basic_Point<Pos>::~Basic_Point()
{
  if (position != nullptr)
  {
    delete[] position;
  }
}

//Basic_Point_Assign_Operator
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
Basic_Point<Pos> &Basic_Point<Pos>::operator+=(const Basic_Point<Pos> &p)
{
  if (Basic_Shape::operator==(p))
  {
    const int dim = getDimension();
    for (int ind = 0; ind < dim; ind++)
    {
      position[ind] += p.position[ind];
    }
  }
  else if (Basic_Shape::operator>(p))
  {
    const int pdim = p.getDimension();
    for (int ind = 0; ind < pdim; ind++)
    {
      position[ind] += p.position[ind]:;
    }
  }
  else
  {
    const int pdim = p.getDimension();
    setDimension(pdim);
    for (int ind = 0; ind < pdim; ind++)
    {
      position[ind] += p.position[ind];
    }
  }
}

template<typename Pos>
Basic_Point<Pos> &operator+=(const Basic_Point<Pos> &&p)
{
  if (Basic_Shape::operator==(p))
  {
    const int dim = getDimension();
    for (int ind = 0; ind < dim; ind++)
    {
      position[ind] += p.position[ind];
    }
  }
  else if (Basic_Shape::operator>(p))
  {
    const int pdim = p.getDimension();
    for (int ind = 0; ind < pdim; ind++)
    {
      position[ind] += p.position[ind]:;
    }
  }
  else
  {
    const int dim = getDimension();
    for (int ind = 0; ind < dim; ind++)
    {
      p.position[ind] += position[ind];
    }
    position = p.position;
    p.position = nullptr;
  }

  return this;
}

template<typename Pos>
Basic_Point<Pos> &operator-=(const Basic_Point<Pos> &p)
{
  return this;
}

template<typename Pos>
Basic_Point<Pos> &operator-=(const Basic_Point<Pos> &&p)
{
  return this;
}

template<typename Pos>
Basic_Point<Pos> &operator*=(const Pos &m)
{
  return this;
}

template<typename Pos>
Basic_Point<Pos> &operator/=(const Pos &d)
{
  return this;
}

//Basic_Point_Arithmetic_Operator
template<typename Pos>
Basic_Point<Pos> operator-(void) const
{
  const int dim = getDimension();
  Basic_Point<Pos> minus(nullptr, dim);
  for (int ind = 0; ind < dim; ind++)
  {
    minus.position[ind] = -position[ind];
  }
  return minus;
}

template<typename Pos>
Basic_Point<Pos> operator+(const Basic_Point<Pos> &p) const
{

}

template<typename Pos>
Basic_Point<Pos> operator+(const Basic_Point<Pos> &&p) const
{

}

template<typename Pos>
Basic_Point<Pos> operator-(const Basic_Point<Pos> &p) const
{

}

template<typename Pos>
Basic_Point<Pos> operator-(const Basic_Point<Pos> &&p) const
{

}

template<typename Pos>
Basic_Point<Pos> operator*(const Pos &m) const
{
  const int dim = getDimension();
  Basic_Point<Pos> mult(nullptr, dim);
  for (int ind = 0; ind < dim; ind++)
  {
    mult.position[ind] = m*position[ind];
  }
  return mult;
}

template<typename Pos>
Basic_Point<Pos> operator/(const Pos &d) const;

template<typename Pos>
Pos &operator[](const int ind);

template<typename Pos>
const Pos &operator[](const int ind) const;

template<typename Pos>
bool operator==(const Basic_Point<Pos> &p) const;

template<typename Pos>
bool operator!=(const Basic_Point<Pos> &p) const;

//Basic_Point_Member_Function
template<typename Pos>
virtual void Basic_Point<Pos>::setDimension(const int newDim)
{
  const int dim = getDimension();
  if (dim != newDim)
  {
    int minDim = (dim < newDim) ? dim : newDim;
    Pos *temp = position;
    position = new Pos[newDim];
    for (int ind = 0; ind < minDim; ind++)
    {
      position[ind] = temp[ind];
    }
    // when getDimension() > changeDim, this area does not work
    for (int ind = minDim; ind < newDim; ind++)
    {
      position[ind] = 0;
    }
    delete[] temp;
    Basic_Shape::setDimension(newDim);
  }
}

template<typename Pos>
virtual void Basic_Point<Pos>::changeAxes(const int axe0, const int axe1)
{
  const int dim = getDimension();
  if (axe1 != axe0 &&
    axe0 > -1 && axe0 < dim &&
    axe1 < dim && axe1 > -1)
  {
    Pos temp = position[axe0];
    position[axe0] = position[axe1];
    position[axe1] = temp;
  }
  else
  {
    throw std::invalid_argument("Invalid argument in axe0 / axe1 of changeAxes");
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
Basic_Plane<Pos>::Basic_Plane(const Basic_Point<Pos> *p, const int dim) : Basic_Shape(dim)
{
  point[0] = p[0];
  point[1] = p[1];
  point[2] = p[2];
}

template<typename Pos>
Basic_Plane<Pos>::Basic_Plane(const Basic_Point<Pos> &p0, const Basic_Point<Pos> &p1, const Basic_Point<Pos> &p2, const int dim) : Basic_Shape(dim)
{
  point[0] = p0;
  point[1] = p1;
  point[2] = p2;
}

template<typename Pos>
bool Basic_Plane<Pos>::isContain(const Basic_Point<Pos> p)
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