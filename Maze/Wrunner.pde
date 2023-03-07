class Wrunner implements AlgoRunner //concrete class for command pattern
{
  private Wilson w;
  
  public Wrunner(Wilson w)
  {
    this.w = w;
  }
  
  public void execute()
  {
    w.On();
  }
}
