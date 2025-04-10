package BTTLp2_Cau3;

import java.util.Random;

public class Carrier extends Robot {
    private int E; // hệ số vận chuyển (50 <= E <= 100)

    public Carrier(double M, double S) {
        super(M, S);
        this.E = new Random().nextInt(51) + 50; // từ 50 đến 100
    }

    public Carrier(double M, double S, int E) {
        super(M, S);
        this.E = E;
    }

    @Override
    public double tinhNangLuong() {
        return M * S + 4 * E * S;
    }

    public int getE() {
        return E;
    }

    public void setE(int e) {
        this.E = e;
    }

    @Override
    public String toString() {
        return "Carrier{" + super.toString() + ", E=" + E + "}";
    }
}
