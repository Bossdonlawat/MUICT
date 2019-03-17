abstract class Shape implements Comparable {
  static double PI = 3.14;
  private String color, description;

  public Shape(String color, String description) {
    this.color = color;
    this.description = description;
  }

  public void setColor(String color) {
    this.color = color;
  }

  public String getColor() {
    return color;
  }

  public String toString() {
    return this.description + " (color=" + this.getColor() + ", area=" + this.getArea() + ")";
  }

  public int compareTo(Object shape) {
    if (this.getArea() > ((Shape)shape).getArea()) {
      return 1;
    } else if (this.getArea() < ((Shape)shape).getArea()) {
      return -1;
    } else {
      return 0;
    }
  }

  public abstract double getArea();
}
