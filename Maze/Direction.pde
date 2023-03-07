import java.util.*;

 enum Direction
{
  NORTH,
  SOUTH,
  WEST,
  EAST;

  private static final HashMap<Integer, Direction>DIR_NUM = new HashMap();

  static {  
    DIR_NUM.put(0, NORTH);
    DIR_NUM.put(1, SOUTH);
    DIR_NUM.put(2, WEST);
    DIR_NUM.put(3, EAST);
  }

  public static Direction to(int index)
  { 
    if (index < 0 || index > 3)
    {
      println("Index Should be between 0 and 3");
    }
    return DIR_NUM.get(index);
  }
}
