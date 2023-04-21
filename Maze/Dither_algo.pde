PImage maze;
float[][] ditherMatrix = {
  {0, 0.75, 0.1875, 0.9375},
  {0.5, 0.25, 0.6875, 0.4375},
  {0.125, 0.875, 0.0625, 0.8125},
  {0.625, 0.375, 0.5625, 0.3125}
};

void setup() {
  size(500, 500);
  maze = loadImage("maze.jpg");
  maze.resize(width, height);
  noLoop();
}

void draw() {
  background(255);
  
  loadPixels();
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int index = x + y * width;
      
      // Get the brightness value from the maze image
      int colorValue = (int) brightness(maze.pixels[index]);
      
      // Apply dithering
      int ditheredColorValue = ditherColor(x, y, colorValue);
      pixels[index] = color(ditheredColorValue);
    }
  }
  updatePixels();
}

int ditherColor(int x, int y, int colorValue) {
  float ditherLevel = 0;
  for (int i = 0; i < ditherMatrix.length; i++) {
    for (int j = 0; j < ditherMatrix[i].length; j++) {
      if ((x + j) % ditherMatrix.length == i && (y + j) % ditherMatrix[i].length == j) {
        ditherLevel = ditherMatrix[i][j] + random(-0.9, 0.3);
        break;
      }
    }
  }
  return constrain(colorValue + int(ditherLevel * 255), 0, 255);
}
