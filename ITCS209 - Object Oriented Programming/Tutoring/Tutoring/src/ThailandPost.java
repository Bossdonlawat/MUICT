public class ThailandPost extends Box {
  public ThailandPost() {
    super(); // Box()
  }

  public ThailandPost(String name, int num) {
    super(name, num);
  }



  @Override
  public void printProvider() {
    System.out.println("Thailand Post");
  }
}
