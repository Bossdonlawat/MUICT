import java.util.ArrayList;

public class Start {
  public static void main(String[] args) {

    ArrayList<Kerry> boxes = new ArrayList<Kerry>();

    for (int i = 0 ; i < 112 ; i++) {
      boxes.add(new Kerry("O", i));
    }

    int size = boxes.size(); // 112

    for (int i = 0 ; i < size ; i++) {
      boxes.get(i).lomjow();
    }

  }
}
