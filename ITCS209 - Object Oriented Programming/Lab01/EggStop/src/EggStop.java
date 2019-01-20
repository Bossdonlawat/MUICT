public class EggStop {
  public static  void shape(int i) {
    if(i==0) {
      System.out.println("  ------");
      System.out.println(" /      \\");
      System.out.println("/        \\");
      System.out.println("\\        /");
      System.out.println(" \\      /");
      System.out.println("  ------");
    }
    else {
      System.out.println("  ------");
      System.out.println(" /      \\");
      System.out.println("/        \\");
      System.out.println("\\  STOP  |");
      System.out.println("\\        /");
      System.out.println(" \\      /");
      System.out.println("  ------");
    }
  }
  public static void main(String args[]) {
    shape(0);
    System.out.println();
    shape(0);
    System.out.println("+--------+");
    shape(1);
  }
}
