int squareSize = 15;

void setup() {
  size(600, 600);
}

void draw() {
  background(255);
  drawGrid();
  int row = mouseY / squareSize;
  int col = mouseX / squareSize;
  fill(255, 0, 0, 128);
  rect(col * squareSize, row * squareSize, squareSize, squareSize);
  println("row:"+row+""+"col:"+col);
  println(((row) * (col)));
}

void drawGrid() {
  for (int i = 0; i < width; i += squareSize) {
    for (int j = 0; j < height; j += squareSize) {
      stroke(0);
      noFill();
      rect(i, j, squareSize, squareSize);
    }
  }
}
