class KichThuoc
{
private:
    double iDai;
    double iRong;

    friend class ThanhPhan;
    
public:
    KichThuoc(double iDai=0, double iRong=0)
    {
        this->iDai = iDai;
        this->iRong = iRong;
    }

    void setDai(double iDai)
    {
        this->iDai = iDai;
    }

    void setRong(double iRong)
    {
        this->iRong = iRong;
    }

    double getDai() const
    {
        return iDai;
    } 

    double getRong() const
    {
        return iRong;
    } 
};