class Cho extends DongVat implements BietChay {
    public Cho() {
        super("Cho", "Dong vat nuoi than thien", "Gau gau");
    }

    @Override
    public String getLoai() {
        return "Cho";
    }

    @Override
    public String chay() {
        return "chay";
    }
}

class Meo extends DongVat implements BietChay {
    public Meo() {
        super("Meo", "Dong vat nho nhanh nhen", "Meo meo");
    }

    @Override
    public String getLoai() {
        return "Meo";
    }

    @Override
    public String chay() {
        return "chay";
    }
}

class Ho extends DongVat implements BietChay, BietGam {
    public Ho() {
        super("Ho", "Thu san moi manh me", "Gao");
    }

    @Override
    public String getLoai() {
        return "Ho";
    }

    @Override
    public String chay() {
        return "chay";
    }

    @Override
    public String gam() {
        return "gam";
    }
}

class CaHeo extends DongVat implements BietBoi {
    public CaHeo() {
        super("Ca heo", "Dong vat co vu thong minh", "Click click");
    }

    @Override
    public String getLoai() {
        return "Ca heo";
    }

    @Override
    public String boi() {
        return "boi";
    }
}

class CaSau extends DongVat implements BietBoi, BietBo {
    public CaSau() {
        super("Ca sau", "Bo sat song nuoc", "Khuc khuc");
    }

    @Override
    public String getLoai() {
        return "Ca sau";
    }

    @Override
    public String boi() {
        return "boi";
    }

    @Override
    public String bo() {
        return "bo";
    }
}

class ChimCuMeo extends DongVat implements BietBay {
    public ChimCuMeo() {
        super("Chim cu meo", "Chim san dem", "Hu hu");
    }

    @Override
    public String getLoai() {
        return "Chim cu meo";
    }

    @Override
    public String bay() {
        return "bay";
    }
}

class ChimBoNong extends DongVat implements BietBoi, BietChay, BietBay {
    public ChimBoNong() {
        super("Chim bo nong", "Chim lon co kha nang da dang", "Quac quac");
    }

    @Override
    public String getLoai() {
        return "Chim bo nong";
    }

    @Override
    public String boi() {
        return "boi";
    }

    @Override
    public String chay() {
        return "chay";
    }

    @Override
    public String bay() {
        return "bay";
    }
}
