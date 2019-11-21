package Java.book_and_practice.book;
// this 可以用在建構子，若是要把參數傳給自己的時候
class Circle {
    double pi = 3.14;
    double radius;
    void show_radius(){
        System.out.println("The radius is "+this.radius);
    }
    void show_area(){
        System.out.println("The area is " + this.pi*this.radius*this.radius);
    }
}
public class this_usage
{
    public static void main(String[] args) {
        Circle circle = new Circle();
        circle.radius = 2.0;
        circle.show_area();
        circle.show_radius();
    }
}