import oscP5.*; /// libraries for communication with supercollider via OSC
import netP5.*;

OscP5 osc;
NetAddress supercollider;

PGraphics pg;

int maze_l = 64; /// check for blank squares when low count
int maze_w = 64; /// check for blank squares when low count
int cell_size= 8;
int margin = 0;
int count = 0;
boolean max_dist_done = false; //finished calculating longest_dist for sc
///// Circle cursor /////
int rad = 0;
int xc = 0, yc = 0;
int lastPressTime = 0;

Grid g = new Grid(maze_l, maze_w);
//////////Maze algos////////////////////
BinaryTree bt = new BinaryTree();
Sidewinder sw = new Sidewinder();
AldousBroder ab = new AldousBroder();
Wilson w = new Wilson();
Hunt_and_Kill hk = new Hunt_and_Kill();
Recursive_Backtracker rb = new Recursive_Backtracker();

Colored_Grid cg = new Colored_Grid(maze_l, maze_w);
Dead_Ends dead = new Dead_Ends();

// work in progress 
Polar_Grid pgrid= new Polar_Grid(7); //maze_l
Draw_Circle drawC= new Draw_Circle();

void setup()
{
  size(512 , 512); 
  background(10, 10, 10);
  
  /*
  ////// OSC_COM ///////////////////
  osc = new OscP5(this, 12000);
  supercollider = new NetAddress("127.0.0.1" , 57120);
  ///////////////////////////////////////////////////
  */
  
  /// Algo ////
  //bt.On(); // Binary Tree Maze
  //sw.On(); //Sidewinder Maze
  //ab.On(); // AldousBroder Maze
  w.On(); // Wilson's Maze
  //hk.On(); // Hunt and kill Maze
  //rb.On(); // Recursive Backtracker Maze
  ////////////
  
  //pgrid.draw_polar_grid();
  //dead.run(3); //calculate average n deadends per algo 
  //g.display_Maze(); //<- elapsed time increase for storing distance values 
  //println("cell[10][10]"+" "+g.dist.get(g.matrix[10][10]));
  //cg.color_flood(maze_l * maze_w); //test
  pg = createGraphics(width , height);
}

void draw()
{   ///////////////////BUG IN HOW THE SQUARES ARE DRAWN!!! ^
  //cg.color_flood(count,pg);
  //count = count + 30;
  if(count < maze_l * maze_w)
  {
    pg.beginDraw();
    cg.color_flood(count , pg);
    pg.endDraw();
    count += 20;
  }
 image(pg, 0, 0);
  /* 
  ///////////// Sending info. supercollider
  if(max_dist_done)
  {
    println("longest_path:"+" "+g.max_dist);
    sendOscMessage("/num_segments" , g.max_dist);
    max_dist_done = false;
  }
  */
  mouse_click();
}

void sendOscMessage(String address , int value)
{
  OscMessage msg =  new OscMessage(address);
  msg.add(value);
  osc.send(msg, supercollider);
}

void mouse_click()
{
  
  if(mousePressed && mouseButton == LEFT) {
    if(millis() - lastPressTime > 100) {  // If half a second has passed
      if(rad < cell_size) {  // If the radius is less than 8
        rad++;  // Increase the radius
      }
      lastPressTime = millis();  // Update the last press time
    }
    xc = mouseX/cell_size;  // Update the position of the circle
    yc = mouseY/cell_size;

    int x = rad, y = 0;  // Starting position

    // Initial decision parameter
    int p = 1 - rad; 

    drawC.drawCirclePoints(xc, yc, x, y, cell_size);

    while(x > y) {
      y++;

      // Decision parameter is less than 0
      if(p <= 0) {
        p = p + 2*y + 1;  
      }
      else { // Decision parameter is greater than 0
        x--;
        p = p + 2*y - 2*x + 1;
      }

      // Draw the points
      if(x < y) {
        break;
      }

      drawC.drawCirclePoints(xc, yc, x, y, cell_size);

      // If the generated point is on the line x = y then the perimeter points have already been printed
      if(x != y) {
        drawC.drawCirclePoints(xc, yc, y, x, cell_size);
      }
    }
  } else {
    rad = 0;  // Reset the radius when the mouse is not pressed
  }
  
}
