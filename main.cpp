#include "Module/tgaimage.h"
#include "Module/linear.h"
#include <cstdio>
#include <iostream>

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color)
{ 
    bool steep=false;
    if (std::abs(x0-x1)<std::abs(y0-y1))      //遍历差距更大的，使得线更加准确
    { 
        std::swap(x0, y0); 
        std::swap(x1, y1); 
        steep = true; 
    }
    if(x0>x1) //使得起点在中点的左边
    {
      std::swap(x0,x1);
      std::swap(y0,y1);
    }
    //按比例打点,将除法变成加减法
    int dx=x1-x0,dy=y1-y0;
    float step=dy/float(dx);//y的步长
    float cur=0;
    for(int x=x0,y=y0;x<=x1;x++)
    {
      if(steep) image.set(y,x,color);
      else image.set(x,y,color);
      cur+=step;
      if(cur>=0.5) y++,cur--;
    }
}

int main() 
{
    vctr4d a(1,2,3,0),b(1,2,3,0);
    double c[16]={2,0,0,0,0,2,0,0,0,0,2,0,0,0,0,2};
    mtrx4d C(c);
    printf("%.2f\n",(a*b)[0]);
    return 0;
}
