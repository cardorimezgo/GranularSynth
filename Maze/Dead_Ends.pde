// run each algo x num times //<>// //<>// //<>// //<>// //<>// //<>//
// accumulate num of dead_ends per algo
// report average of dead_ends 

class Dead_Ends
{
  BTrunner bt_runner = new BTrunner(bt); //concrete class 
  ABrunner ab_runner = new ABrunner(ab); //concrete class 
  SWrunner sw_runner = new SWrunner(sw); //concrete class  
  Wrunner w_runner = new Wrunner(w); //concrete class 
  HKrunner hk_runner = new HKrunner(hk); //concrete class
  RBrunner rb_runner = new RBrunner(rb); //concrete class
  Maze_Algo m_a = new Maze_Algo();  //invoker of command pattern
  
  double cien = 100;
  double total_sq = maze_w * maze_l;
  
  void run (int runs)
  {
    m_a.addAlgo(bt_runner);
    m_a.addAlgo(ab_runner);
    m_a.addAlgo(sw_runner);
    m_a.addAlgo(w_runner);
    m_a.addAlgo(hk_runner);
    m_a.addAlgo(rb_runner);

    for (int i = 0; i < m_a.listAlgo().size(); i++)
    { 
      int p_h_cnt = 0;
      for (int j = 0; j < runs; j++)
      {
        m_a.runAlgo(i);
        p_h_cnt += dead_ends();
      }
      int avg = p_h_cnt / runs;
      double percent = (avg) * (cien / total_sq);
      println("algo:"+m_a.listAlgo().get(i)+" "+"avg:"+""+avg+" "+"percentage:"+percent+"%");
    }
  }

  int dead_ends()
  {
    int cnt = 0;
    for (int r = 0; r < g.rows; r++)
    {
      for (int c = 0; c < g.cols; c++)
      {
        Cell cell = g.matrix[r][c];
        if (cell.links().size() == 1)
        {
          cnt++;
        }
      }
    }
    return cnt;
  }
}
