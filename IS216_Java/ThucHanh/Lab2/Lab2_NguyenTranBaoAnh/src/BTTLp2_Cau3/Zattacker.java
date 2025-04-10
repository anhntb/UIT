package BTTLp2_Cau3;

import java.util.Random;

public class Zattacker extends Robot {
    private int P; // sức mạnh (20 <= P <= 30)

    public Zattacker(double M, double S) {
        super(M, S);
        this.P = new Random().nextInt(11) + 20; // từ 20 đến 30
    }

    public Zattacker(double M, double S, int P) {
        super(M, S);
        this.P = P;
    }

    @Override
    public double tinhNangLuong() {
        return M * S + P * P * S;
    }

    public int getP() {
        return P;
    }

    public void setP(int p) {
        this.P = p;
    }

    @Override
    public String toString() {
        return "Zattacker{" + super.toString() + ", P=" + P + "}";
    }
}

