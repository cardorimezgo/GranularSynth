class HKrunner implements AlgoRunner //concrete class for command pattern
{
  private Hunt_and_Kill hk;
  
  public HKrunner(Hunt_and_Kill hk)
  {
    this.hk = hk;
  }
  
  public void execute()
  {
    hk.On();
  }
}
