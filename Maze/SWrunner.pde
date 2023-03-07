class SWrunner implements AlgoRunner //concrete class for command pattern
{
  private Sidewinder sw;
  
  public SWrunner(Sidewinder sw)
  {
    this.sw = sw;
  }
  
  public void execute()
  {
    sw.On();
  }
}
