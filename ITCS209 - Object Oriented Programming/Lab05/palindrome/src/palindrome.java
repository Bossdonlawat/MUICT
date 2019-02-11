import java.util.Scanner;

public class palindrome {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    System.out.print("Enter a word or phrase to check if it is a palindrome: ");
    String string = in.nextLine();

    boolean isPalindrom = false;
    char[] check = string.toCharArray();
    if (check.length%2 == 0){
      for (int i = 0; i < check.length/2-1; i++){
        if (check[i] != check[check.length-i-1]){
          isPalindrom = false;
          break;
        } else {
          isPalindrom = true;
        }
      }
    } else {
      for (int i = 0; i < (check.length-1)/2-1; i++){
        if (check[i] != check[check.length-i-1]){
          isPalindrom = false;
          break;
        } else {
          isPalindrom = true;
        }
      }
    }

    if (isPalindrom == true) {
      System.out.println("The input word \"" + string + "\" is a palindrome");
    } else {
      System.out.println("The input phrase \"" + string + "\" is not a palindrome");
    }
  }
}
