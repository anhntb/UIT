public class Point2D {
    private double x;
    private double y;

    public Point2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void translate(double dx, double dy) {
        x += dx;
        y += dy;
    }

    public void scale(double factor) {
        x *= factor;
        y *= factor;
    }

    public void rotate(double degree) {
        double rad = Math.toRadians(degree);
        double cos = Math.cos(rad);
        double sin = Math.sin(rad);

        double newX = x * cos - y * sin;
        double newY = x * sin + y * cos;

        x = newX;
        y = newY;
    }

    public double distanceTo(Point2D other) {
        double dx = x - other.x;
        double dy = y - other.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    @Override
    public String toString() {
        return String.format("(%.2f, %.2f)", x, y);
    }
}
