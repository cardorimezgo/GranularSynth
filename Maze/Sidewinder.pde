// 1 clean upper row
// 2 move to next row
// continue carving east until randomly stop and randomly choose 
// one of the cells you already carved through(run set) and carve
// a passage north
// 3 clear the run set
// continue moving east until you have to move to the next row
// (!)Improtant condition is that if you are at the extreme north
// or at the extreme east and you have to carve, if you are north
// your only option will be to carve north as we did in step (1), 
// if you are at the extre cell at east your only option is to carve north
///////////////////////////////////////////////////////////////////////////

class Sidewinder
{
  void On()
  {
    g.create_grid();
    g.config_cells();

    Random random = new Random(); 
    List <Cell> run = new ArrayList<Cell>(); 
    for (int c = 0; c < g.cols; c++) //<>//
    {
      for (int r = 0; r < g.rows; r++)
      {          
        Cell cell = g.visit_cell(r, c);
        run.add(g.visit_cell(r, c));
        boolean east_bound =  r == (g.rows - 1);
        boolean north_bound = c == 0;
        boolean close = east_bound || (! north_bound && random.nextInt(2) == 0);

        if (east_bound && north_bound)
        { 
          run.clear();
          continue;
        }
        if (close) // if true we're at the last col or we are randomly  
        {          // choosing to walk north and we are not at the north-most row 
          if (run.size() > 0)
          {
            int index = random.nextInt(run.size()); 
            Cell member = run.get(index);
            member.link(member.get_neighbor(Direction.NORTH));
          }
          run.clear();
        } else
        {
          cell.link(cell.get_neighbor(Direction.EAST));
        }
      }
    }
  }
}
