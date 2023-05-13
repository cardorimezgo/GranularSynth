class Draw_Circle
{ 
  void drawCirclePoints(int xc, int yc, int x, int y, int grid) {
  rect(grid*(xc+x), grid*(yc+y), grid, grid);
  rect(grid*(xc-x), grid*(yc+y), grid, grid);
  rect(grid*(xc+x), grid*(yc-y), grid, grid);
  rect(grid*(xc-x), grid*(yc-y), grid, grid);
  rect(grid*(xc+y), grid*(yc+x), grid, grid);
  rect(grid*(xc-y), grid*(yc+x), grid, grid);
  rect(grid*(xc+y), grid*(yc-x), grid, grid);
  rect(grid*(xc-y), grid*(yc-x), grid, grid);
}

}
