#ifndef _MPOINTS_H_
#define _MPOINTS_H_

class MPoints
{
public:
  MPoints(int mxin, int myin)
    : x(mxin), y(myin) { }
  int mx()
    {return this->x;}
  int my()
    {return this->y;}
  int x, y;
protected:
private:
};

#endif