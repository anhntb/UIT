public class PhanSo {
    private int tuSo;
    private int mauSo;

    // * Constructor
    public PhanSo() {
        tuSo = 0;
        mauSo = 1;
    }

    public PhanSo(int tuSo, int mauSo) {
        this.tuSo = tuSo;
        if (mauSo == 0) {
            System.err.println("Mau so phai khac 0!");
            System.exit(1);
        }
        else {
            this.mauSo = mauSo;
        }
    }

    public PhanSo(int tuSo) {
        this.tuSo = tuSo;
        this.mauSo = 1;
    }

    // * Functions
    // Rút gọn
    public PhanSo rutGonPS() {
        

    }

    // Tổng 2 Phân số
    public PhanSo cong(PhanSo ps) {

    }


    // * Getter & Setter
    public int getTuSo() {
        return tuSo;
    }

    public int getMauSo() {
        return mauSo;
    }

    public void setTuSo(int tuSo) {
        this.tuSo = tuSo;
    }

    public void setMauSo(int mauSo) {
        if (mauSo == 0) {
            System.err.println("Mau so phai khac 0!");
        } 
        else {
            this.mauSo = mauSo;
        }
    }
}
