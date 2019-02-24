import static java.lang.Math.PI;

public class Circle extends Shape {
  private double radius;

  public Circle() {
    super();
  }

  public Circle(String color, double radius) {
    super(color);
    this.radius = radius;
  }

  @Override
  public String toString() {
    return "Rectangle[radius=" + this.radius + ",Shape[color=" + this.getColor() + "]]";
  }

  @Override
  public double getArea() {
    return this.radius * this.radius * PI;
  }

  public double getArea(double radius) {
    this.radius = radius;
    return radius * radius * PI;
  }
}
