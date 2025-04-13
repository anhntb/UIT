package Robot;

import java.util.Random;

public class Pedion extends Robot {
    private int F; // hệ số linh hoạt (1 <= F <= 5)

    public Pedion(double M, double S) {
        super(M, S);
        this.F = new Random().nextInt(5) + 1; // từ 1 đến 5
    }

    public Pedion(double M, double S, int F) {
        super(M, S);
        this.F = F;
    }

    @Override
    public double tinhNangLuong() {
        return M * S + (F + 1) * S / 2.0;
    }

    public int getF() {
        return F;
    }

    public void setF(int f) {
        this.F = f;
    }

    @Override
    public String toString() {
        return "Pedion{" + super.toString() + ", F=" + F + "}";
    }
}

