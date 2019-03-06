public class Kerry extends Box {
  public Kerry() {
    super(); // Box()
  }

  public Kerry(String name, int num) {
    super(name, num); // Box(name, num)
  }

  public Kerry(int num, String name) {
    super(name, num);
  }

  public void lomjow() {
    System.out.println("O");
  }

  @Override
  public void printProvider() {
    System.out.println("Kerry Express");
  }
}
