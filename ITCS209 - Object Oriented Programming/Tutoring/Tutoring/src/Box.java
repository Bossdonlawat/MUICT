public class Box {
  private int num;
  private String name;

  public Box() {
    this.name = "unknown";
    this.num = 0;
  }

  public Box(String name, int num) {
    this.num = num;
    this.name = name;
  }

  public Box(int num, String name) {
    this.num = num;
    this.name = name;
  }

  public int getNum() {
    return this.num;
  }

  public String getName() {
    return this.name;
  }

  public void addNum(int a) {
    this.num += a;
  }

  public void printProvider() {
    System.out.println("O");
  }

  public void printNum(int a) {
    System.out.println("[INT]: " + a);
  }

  public void printNum(int a, int b) {

  }

  public void printNum(double a) {
    System.out.println("[DOUBLE]: " + a);
  }

  public void printNum(String a) {
    System.out.println("[STRING]: " + a);
  }

}
