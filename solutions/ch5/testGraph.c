#include<stdio.h>
#include<math.h>
#include "../../util/exception.h"
#include "../../util/graphics.h"

int main()
{
  InitGraphics();
  MovePen(2.0,0.5);
  DrawLine(1.0,0.0);
  DrawLine(0.0,1.0);
  DrawArc(0.5,0,180);
  DrawLine(0.0,-1.0);
}
