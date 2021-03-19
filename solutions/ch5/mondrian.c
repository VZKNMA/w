/*
 *This program creates a random vertical/horizontal line drawing
 *gcc mondrian.c -o a -L ../../l -l cs -lm
 原因主要是没有定义“cos”函数，或者说没有找到“cos”函数的实现，虽然我们在函数开头声明了数学函数库，但还是没有找到cos的实现，这时我们就需要指定sin函数的具体路径了。系统一些默认库的位置在/lib/下面，我们可以在编译时，加上参数"-lm",‘l’代表lib，而‘m’代表math库，这就形成了“-lm”
 */

#include<stdio.h>
#include "../../i/genlib.h"
#include "../../i/random.h"
#include "../../i/graphics.h"

#define MinArea 0.5
#define MinEdge 0.15

static void SubdivideCanvas(double x,double y,double width,double height);

int main(void)
{
  InitGraphics();
  Randomize();
  SubdivideCanvas(0,0,GetWindowWidth(),GetWindowHeight());
  return 0;
}

static void SubdivideCanvas(double x,double y,double width,double height)
{
  double divider;
  if(width*height>=MinArea){
    if(width>height){
      divider=width*RandomReal(MinEdge,1-MinEdge);
      MovePen(x+divider,y);
      DrawLine(0,height);
      SubdivideCanvas(x,y,divider,height);
      SubdivideCanvas(x+divider,y,width-divider,height);
    }else{
      divider=height*RandomReal(MinEdge,1-MinEdge);
      MovePen(x,y+divider);
      DrawLine(width,0);
      SubdivideCanvas(x,y,width,divider);
      SubdivideCanvas(x,y+divider,width,height-divider);
    }
  }
}

