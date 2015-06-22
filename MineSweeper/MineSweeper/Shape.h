#ifndef SHAPE_H_
#define SHAPE_H_

//Shape class template : abstract class
//----Declaration

class Basic_Shape
{
private :
  int dimension;
protected :
  void setDimension(int dim = 2){ dimension = dim; }
public :
  Basic_Shape(int dim = 2){ dimension = dim; }
  int getDimension(void){ return dimension; }
  virtual void changeAxes(int axe1 = 0, int axe2 = 1) = 0;
  virtual void changeDimension(int changeDim = 2) = 0;
};


//Basic_Point class template
//----Declaration

template<typename Pos>
class Basic_Point : public Basic_Shape
{
private :
  Pos *position;
public :
  Basic_Point(Pos *pos = nullptr, int dim = 2);
  Basic_Point(Basic_Point<Pos> &p);
  ~Basic_Point();
  Basic_Point<Pos>
  virtual void changeAxes(int axe1 = 0, int axe2 = 1);
  virtual void changeDimension(int changeDim = 2);
};

//Basic_Point class template
//--Definition

template<typename Pos>
Basic_Point<Pos>::Basic_Point(Pos *pos, int dim) : Basic_Shape(dim)
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
Basic_Point<Pos>::Basic_Point(Basic_Point<Pos> &p) : Basic_Shape(p)
{
  position = new Pos[p.getDimension()];
  for (int ind = 0; ind < p.getDimension(); ind++)
  {
    position[ind] = p.position[ind];
  }
}

template<typename Pos>
Basic_Point<Pos>::~Basic_Point()
{
  delete[] position;
}

template<typename Pos>
virtual void Basic_Point<Pos>::changeAxes(int axe1, int axe2)
{
  int currentDim = getDimension();
  if (axe2 == axe1 &&
    axe1 > -1 && axe1 < currentDim &&
    axe2 < currentDim && axe2 > -1)
  {
    Pos temp = position[axe1];
    position[axe1] = position[axe2];
    position[axe2] = temp;
  }
}

template<typename Pos>
virtual void Basic_Point<Pos>::changeDimension(int changeDim)
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
  Basic_Plane(Basic_Point<Pos> *p = nullptr, int dim = 2);
  Basic_Plane(Basic_Point<Pos> p1, Basic_Point<Pos> p2, Basic_Point<Pos> p3, int dim = 2);
  bool inPlane(Basic_Point<Pos> p);
  virtual void changeAxes(int axe1, int axe2);
  virtual void changeDimension(int dim);
};

//Basic_Plane class template
//--Definition

template<typename Pos>
Basic_Plane<Pos>::Basic_Plane(Basic_Point<Pos> *p, int dim)
{
  point[0] = p[0];
  point[1] = p[1];
  point[2] = p[2];
}

template<typename Pos>
class Basic_Rect : public Basic_Shape
{
private :
  Basic_Point<Pos> p[2];
  Basic_Plane<Pos> inPlane;
public :

};

#endif