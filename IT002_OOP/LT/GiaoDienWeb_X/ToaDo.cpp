class ToaDo
{
private:
    double x;
    double y;

    friend class ThanhPhan;
    
public:
    ToaDo(double x=0, double y=0)
    {
        this->x = x;
        this->y = y;
    }

    void setX(double x)
    {
        this->x = x;
    }

    void setY(double y)
    {
        this->y = y;
    }

    double getX() const
    {
        return x;
    } 

    double getY() const
    {
        return y;
    } 
};