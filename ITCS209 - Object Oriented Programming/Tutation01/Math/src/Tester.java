public class Tester {
  public int factorial (int n) {
    if (n == 1) {
      return n;
    } else {
      return n * factorial(n - 1);
    }
  }

  /**
   * Recursive:
   *
   * factorial(10) -> n = 10
   * > 10 * factorial(9) -> n = 9
   * > 10 * (9 * factorial(8)) -> n = 8
   * ...
   * > 10 * (9 * (8 * (7 * factorial(6)))) -> n = 6
   * > 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 -> O(n)
   *
   * ------
   *
   * Looping:
   *
   * 1 * 1 = 1
   * 1 * 2 = 2
   * 2 * 3 = 6
   * 6 * 4 = 24
   * ... -> O(n^2)
   */

  public static void main (String[] args) {
    int res = 1;
    int n = 40;
    for (int i = 1 ; i <=n ; i++) {
      res *= i;
    }
    System.out.println(res);
  }
}
