
/*
 * The Rectangle class, subclass of Shape
 */
public class Rectangle extends Shape {
  // Private member variables
  //add your code here
  private double length, width;

  // Constructors
  public Rectangle()
  {
    super();
  }
  public Rectangle(String color, double length, double width) {
    super(color);
    this.length = length;
    this.width = width;
  }

  @Override
  public String toString() {
    return "Rectangle[length=" + this.length + ",width=" + this.width + ",Shape[color=" + this.getColor() + "]]";
  }

  // Override the inherited getArea() to provide the proper implementation
  @Override
  public double getArea() {
    return this.length * this.width;
  }

  public double getArea(double length, double width) {
    this.length = length;
    this.width = width;
    return length * width;
  }
}
