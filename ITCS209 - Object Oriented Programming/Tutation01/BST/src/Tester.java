public class Tester {
  public static Node BST(Node root, int key) {
    if (root == null || root.key == key) {
      return root;
    }

    if (root.key > key) {
      return BST(root.left, key);
    } else {
      return BST(root.right, key);
    }
  }

  public static void main (String[] args) {
    Node root = new Node(
        8,
        new Node(
            3,
            new Node(
                1,
                null,
                null),
            new Node(
                6,
                new Node(
                    4,
                    null,
                    null),
                new Node(
                    7,
                    null,
                    null))),
        new Node(
            10,
            null,
            new Node(
                14,
                new Node(
                    13,
                    null,
                    null),
                null)));

    Node res = BST(root, 4);

    System.out.println(res.key);
  }
}
