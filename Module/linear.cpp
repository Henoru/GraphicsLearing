#include "linear.h"
#include <cmath>
#include <cstdio>
#include <iostream>
double sqr(double x)
{
  return x*x;
}
vctr4d::vctr4d(){v[0]=v[1]=v[2]=v[3]=0;}
vctr4d::vctr4d(double x,double y,double z,double w)
{
  v[0]=x,v[1]=y,v[2]=z,v[3]=w;
}
double vctr4d::operator[](int x)const {return v[x];}
double& vctr4d::operator[](int x){return v[x];}
vctr4d vctr4d::operator+(const vctr4d& other)const//点与向量相加，向量与向量相加
{
  vctr4d a=*this;
  //if((*this)[3] && other[3]) throw "vctr4d::points can't add points\n";
  for(int i=0;i<4;i++)
    a[i]+=other[i];
  return a;
}
vctr4d vctr4d::normalise()const
{
  //if(v[3]) return vctr4d(v[0]/v[3],v[1]/v[3],v[2]/v[3]);
  //else
  //{
    double len=sqrt(sqr(v[0])+sqr(v[1])+sqr(v[2]));
    return vctr4d(v[0]/len,v[1]/len,v[2]/len,0);
  //}
}
vctr4d vctr4d::operator-(const vctr4d& other)const//点与点相减，向量与向量相减，点与向量相减
{
  // if((*this)[3]==0 && other[3]) throw "vctr4d::vector can't minus point\n";
  // if((*this)[3] && other[3])
  // { 
  //   vctr4d a=this->normalise(),b=other.normalise();
  //   return vctr4d(a[0]-b[0],a[1]-b[1],a[2]-b[2],a[3]-b[3]);
  // }
  // else
  // {
    const vctr4d& a=*this,b=other;
    return vctr4d(a[0]-b[0],a[1]-b[1],a[2]-b[2],a[3]-b[3]);
  //}
}
vctr4d vctr4d::operator*(const vctr4d& other)const //叉乘
{
  if((*this)[3] || other[3]) throw "vctr4d::only vector can have cross product\n";
  const vctr4d& a=*this,b=other;
  return vctr4d(a[1]*b[2]-b[1]*b[2],a[2]*b[0]-a[0]*b[2],a[0]*b[2]-a[1]*b[0],0);
}
double dot(const vctr4d& a,const vctr4d& b)
{
  if(a[3] || b[3]) throw "vctr4d::only vector can have dot product\n";
  double ans=0;
  for(int i=0;i<3;i++)
    ans+=a[i]*b[i];
  return ans;
}
mtrx4d::mtrx4d()
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      v[i][j]=0;
}
mtrx4d::mtrx4d(double argv[])
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      v[i][j]=argv[4*i+j];
}
double* mtrx4d::operator[](int x){return v[x];}
const double* mtrx4d::operator[](int x)const{return v[x];}
mtrx4d mtrx4d::operator*(const mtrx4d& other)const
{
  mtrx4d c;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
      c[i][j]=0;
      for(int k=0;k<4;k++)
        c[i][j]+=(*this)[i][k]*other[k][j];
    }
  return c;
}
mtrx4d mtrx4d::operator+(const mtrx4d& other)const
{
  mtrx4d c;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      c[i][j]=(*this)[i][j]+other[i][j];
  return c;
}
mtrx4d mtrx4d::operator-(const mtrx4d& other) const
{
  mtrx4d c;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      c[i][j]=(*this)[i][j]-other[i][j];
  return c;
}
vctr4d operator*(const mtrx4d& M,const vctr4d& V)
{
  vctr4d c;
  for(int i=0;i<4;i++)
  {
    c[i]=0;
    for(int j=0;j<4;j++)
      c[i]+=M[i][j]*V[j];
  }
  return c;
}
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
