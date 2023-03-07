public class BinaryTree //<>// //<>//
{
  public void On()
  {
    g.create_grid();
    g.config_cells();

    Direction[] dirs = new Direction[]{Direction.SOUTH, Direction.EAST};
    Random random = new Random();

    for (int r = 0; r < g.rows; r++)
    {
      for (int c = 0; c < g.cols; c++)
      {
        Cell cell = g.visit_cell(r, c);  
        List <Cell> n = cell.get_neighbors(dirs); ///get_neighbors returns a list of cell 

        if (n.size() == 0)
        {
          return;
        }
        int neighbor_ran = random.nextInt(n.size()); //neighbors can't be empty
        n.get(neighbor_ran).link(cell);
      }
    }
  }
}
