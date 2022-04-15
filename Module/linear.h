#include<cmath>
class vctr4d
{
  /*
    向量和点类
  */
private:
public:
  double v[4];
  vctr4d();
  vctr4d(double x,double y,double z,double w);
  double operator[](int x)const;
  double& operator[](int x);
  vctr4d operator+(const vctr4d& other)const;
  vctr4d normalise()const;
  vctr4d operator-(const vctr4d& other)const;
  vctr4d operator*(const vctr4d& other)const;
};
double dot(const vctr4d&,const vctr4d&);
class mtrx4d
{
  /*
    矩阵类
  */
private:
public:
  double v[4][4];
  mtrx4d();
  mtrx4d(double argv[]);
  double* operator[](int x);
  const double* operator[](int x)const;
  mtrx4d operator*(const mtrx4d& other)const;
  mtrx4d operator+(const mtrx4d& other)const;
  mtrx4d operator-(const mtrx4d& other)const;
};
vctr4d operator*(const mtrx4d& M,const vctr4d& V);
namespace trans
{
  mtrx4d scale(double Sx,double Sy,double Sz);
  mtrx4d scaleX(double Sx);
  mtrx4d scaleY(double Sy);
  mtrx4d scaleZ(double Sz);
  mtrx4d translate(double Tx,double Ty,double Tz);
  mtrx4d translateX(double Tx);
  mtrx4d translateY(double Ty);
  mtrx4d translateZ(double Tz);
  mtrx4d rotate(const vctr4d &axis,double angle);
  mtrx4d rotateX(double angle);
  mtrx4d rotateY(double angle);
  mtrx4d rotateZ(double angle);
  mtrx4d ViewCamera(const vctr4d &pos,const vctr4d &up,const vctr4d &sight);
  mtrx4d orthographic();//正交投影
  mtrx4d perspective();//透视投影
  mtrx4d viewport();
}