package Robot;

public abstract class Robot {
    protected double M; // trọng lượng
    protected double S; // quãng đường (km)

    public Robot(double M, double S) {
        this.M = M;
        this.S = S;
    }

    public abstract double tinhNangLuong();

    // Getter
    public double getM() {
        return M;
    }

    public double getS() {
        return S;
    }
    
    // Setter
    public void setM(double m) {
        this.M = m;
    }
    
    public void setS(double s) {
        this.S = s;
    }

    @Override
    public String toString() {
        return "M=" + M + ", S=" + S;
    }
}

