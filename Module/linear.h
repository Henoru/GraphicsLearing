class vctr
{
  /*
    向量和点类
  */
private:
public:
  double v[4];
  vctr(double x,double y,double z,double w=1);
  vctr operator+(const vctr&);
  vctr operator*(const vctr&);  //叉乘
  bool operator==(const vctr&);
  double operator[](const int&);
};
double dot(const vctr&,const vctr&);
class mtrx
{
  /*
    矩阵类
  */
private:
public:
  double v[4][4];
  mtrx operator*(const mtrx&);
  mtrx operator+(const mtrx&);
  double* operator[](const int&);
};
vctr operator*(const mtrx&,const vctr&);
mtrx scale(double Sx,double Sy,double Sz);
mtrx scaleX(double Sx);
mtrx scaleY(double Sy);
mtrx scaleZ(double Sz);
mtrx translate(double Tx,double Ty,double Tz);
mtrx translateX(double Tx);
mtrx translateY(double Ty);
mtrx translateZ(double Tz);
mtrx rotate(const vctr &axis,double angle);
mtrx rotateX(double angle);
mtrx rotateY(double angle);
mtrx rotateZ(double angle);
mtrx ViewCamera(const vctr &pos,const vctr &up,const vctr &sight);
mtrx orthographic();//正交投影
mtrx perspective();//透视投影
mtrx viewport();
