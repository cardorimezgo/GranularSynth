int rectSz = 100;
int or = 5;
void setup()
{
  size(400 , 400);
  rect(or, or, rectSz, rectSz);
  rect((width/2) + or, or, rectSz, rectSz);
}

void draw()
{
  if (mouseX > or && 
      mouseX < or + rectSz &&
      mouseY > or &&
      mouseY < or + rectSz)
      {
        println("On");
      }
      else
      {
        println("Off");
      }       
}
