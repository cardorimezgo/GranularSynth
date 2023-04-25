import oscP5.*; /// libraries for communication with supercollider via OSC
import netP5.*;

OscP5 osc;
NetAddress supercollider;

int maze_l = 20; /// check for blank squares when low count
int maze_w = 20; /// check for blank squares when low count
int cell_size= 25;
float cent = 50;
int count = 0;

Grid g = new Grid(maze_l, maze_w);

BinaryTree bt = new BinaryTree();
Sidewinder sw = new Sidewinder();
AldousBroder ab = new AldousBroder();
Wilson w = new Wilson();
Hunt_and_Kill hk = new Hunt_and_Kill();
Recursive_Backtracker rb = new Recursive_Backtracker();

Colored_Grid cg = new Colored_Grid(maze_l, maze_w);
Dead_Ends dead = new Dead_Ends();

// work in progress 
Polar_Grid pg= new Polar_Grid(7); //maze_l

void setup()
{
  size(600, 600); 
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
  ab.On(); // AldousBroder Maze
  //w.On(); // Wilson's Maze
  //hk.On(); // Hunt and kill Maze
  //rb.On(); // Recursive Backtracker Maze
  ////////////
  //pg.draw_polar_grid();
  //dead.run(3); //calculate average n deadends per algo 
  g.display_Maze();
  println(g.dist.get(g.matrix[10][10]));
}

void draw()
{
  //cg.color_flood(count);
  //count = count + 30;
}
