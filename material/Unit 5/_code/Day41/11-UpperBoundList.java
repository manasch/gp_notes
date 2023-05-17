import java.util.ArrayList;
import java.util.List;

abstract class Shape {
    public abstract void draw(Canvas c);
}

class Circle extends Shape {
    private int x, y, radius;

    public Circle(int x, int y, int radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    public void draw(Canvas c) {
        System.out.println("Drawing a circle at (" + x + ", " + y + ") with radius " + radius);
    }
}

class Rectangle extends Shape {
    private int x, y, width, height;

    public Rectangle(int x, int y, int width, int height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    public void draw(Canvas c) {
        System.out.println("Drawing a rectangle at (" + x + ", " + y + ") with width " + width + " and height " + height);
    }
}

class Canvas {
    public void draw(Shape s) {
        s.draw(this);
    }

    public void drawAll(List<? extends Shape> shapes) {
        for (Shape s : shapes) {
            s.draw(this);
        }
    }
}

public class UpperBoundList {
    public static void main(String[] args) {
        Circle circle = new Circle(10, 20, 30);
        Rectangle rectangle = new Rectangle(40, 50, 100, 200);

        List<Circle> circleList = new ArrayList<>();
        circleList.add(circle);

        List<Rectangle> rectangleList = new ArrayList<>();
        rectangleList.add(rectangle);

        List<Shape> shapeList = new ArrayList<>();
        shapeList.add(circle);
        shapeList.add(rectangle);

        Canvas canvas = new Canvas();
        canvas.drawAll(circleList);
        canvas.drawAll(rectangleList);
        canvas.drawAll(shapeList);
    }
}
