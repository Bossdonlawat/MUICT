import java.util.ArrayList;

public class Maaiinn {
  public static void main(String[] args) {
    ArrayList<Box> boxes = new ArrayList<Box>();

    Box box1 = new Box(9);
    Box box2 = new Box(10);

    boxes.add(box1);
    boxes.add(box2);

    boxes.add(new Box(8));

    boxes.remove(1);

//    for (int i = 0 ; i < boxes.size() ; i++) {
//      Box box = boxes.get(i);
//      if (box.equals(new Box(10)) == true) {
//        boxes.remove(i);
//      }
//    }

    for (int i = 0 ; i < boxes.size() ; i++) {
      System.out.println("[" + i + "] " + boxes.get(i).toString());
    }

    System.out.println("OK");
  }
}
