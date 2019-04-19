import java.util.ArrayList;
import java.util.Collections;

public class FullBinaryTreeTester {

  public static void inOrderTraverse(Node root)
  {
    if (root != null) {
      // Do recursive in left node
      inOrderTraverse(root.left);

      // Print current node
      System.out.print(root.id + " ");

      // Do recursive in right node
      inOrderTraverse(root.right);
    }
  }

  public static boolean isFullBinTree(Node root)
  {
    // Case 1 - If node is empty
    if (root == null) return true;

    // Case 2 - If node not have sub-node
    if (root.left == null && root.right ==  null) return true;

    // Case 3 - Check condition inside sub-node recursively
    if (root.left != null &&root.right != null) return isFullBinTree(root.left) && isFullBinTree(root.right);

    // Reject any unmatched condition
    return false;
  }

  public static void normalTester()
  {
    Node[] ts = new Node[7];
    int count = 0;
    ts[count++] = null;
    ts[count++] = new Node(16, null, null);

    ts[count++] = new Node(16, new Node(14, null, null), null);

    ts[count++] = new Node(1, new Node(3, new Node(6, null, null), new Node(7, null, null)),
        new Node(4, new Node(8, null, null), new Node(10, null, null)));

    ts[count++] = new Node(1, new Node(3, null, null),
        new Node(4, new Node(8, null, null), new Node(10, null, null)));

    ts[count++] = new Node(1, new Node(3, new Node(6, null, null), null),
        new Node(4, new Node(8, null, null), new Node(10, null, null)));

    ts[count++] = new Node(1, new Node(3, new Node(6, null, null), new Node(7, null, null)),
        null);

    for(int i = 0; i < ts.length; i++)
    {
      System.out.print("[T"+i+"] in-order: ");
      inOrderTraverse(ts[i]);
      System.out.println("\n[T"+i+"] is"+(isFullBinTree(ts[i])?" ":" NOT ")+"a full binary tree.\n");
    }

  }


  /**************BONUS STARTS***************/
  public static void printBinTree(Node root)
  {
    // Check if not is not empty
    if (root != null) {
      // Make sure both sub-node are exists
      if (root.left != null && root.right != null) {
        // Print current node
        System.out.println("  " + root.id);

        // Print left arm if left sub-node is exists
        if (root.left!=null) System.out.print(" /");

        // Print right arm if right sub-node is exists
        if(root.right!=null) System.out.print(" \\");
        System.out.println();

        // Print node at the edge of left sub-node
        if(root.left!=null) System.out.print(root.left.id);
        else System.out.print(" ");
        System.out.print("   ");

        // Print node at the edge of right sub-node
        if(root.right!=null) System.out.print(root.right.id);
        else System.out.print(" ");
        System.out.println("\n");

        // Sub-node is doing the same
        printBinTree(root.left);
        printBinTree(root.right);
      }
    }
  }

  /**
   * Get the size of binary tree
   * @param node  Binary tree
   * @return Size of binary tree
   */
  public static int getTreeSize(Node node) {
    if (node == null)
      return 0;
    else
      return getTreeSize(node.left) + getTreeSize(node.right) + 1;
  }

  static ArrayList<Integer> tree = new ArrayList<Integer>();

  /**
   * Convert binary tree into array
   * @param node
   */
  public static void binaryToArray(Node node) {
    if (node != null) {
      // Convert binary on left side
      if(node.left != null)
        binaryToArray(node.left);

      // Push node to array
      tree.add(node.id);

      //  Convert binary on right side
      if(node.right != null)
        binaryToArray(node.right);
    }
  }

  /**
   * Convert array into binary search tree
   * @param start start index
   * @param end   end index
   * @return
   */
  public static Node createBinarySearchTree(int start, int end) {
    // Avoid buffer overflow
    if (start > end) return null;

    // Find middle point
    int middle = (start + end) / 2;

    // Create node
    Node node = new Node(tree.get(middle), createBinarySearchTree(start, middle - 1), createBinarySearchTree(middle + 1, end));
    return node;
  }

  public static Node getBinSearchTree(Node root)
  {
    // Calculate tree size
    int treeSize = getTreeSize(root);

    // Convert tree to array
    binaryToArray(root);

    // Sort
    Collections.sort(tree);

    // Convert array to binary search tree
    return createBinarySearchTree(0, tree.size() - 1);
  }

  public static void bonusTester()
  {
    Node t = new Node(1, new Node(3, new Node(6, null, null), new Node(7, null, null)),
        new Node(4, new Node(8, null, null), new Node(10, null, null)));
    System.out.println("Before Transforming: ");
    printBinTree(t);
    System.out.println("After Transforming: ");
    printBinTree(getBinSearchTree(t));

  }
  /**************BONUS ENDS***************/



  public static void main(String[] args)
  {
    normalTester();

    //Uncomment for bonus
    bonusTester();
  }
}
