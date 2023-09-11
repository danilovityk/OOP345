#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

extern float g_taxrate;
extern float g_discount;

namespace sdds {

class RideRequest{
    
private:
    char m_name [10];
    char m_details [25];
    float m_price;
    bool m_discount;
    
public:
    RideRequest();
    std::istream& read(std::istream& istr);
    void display() const;
    
};

}

#endif /* SDDS_RIDEREQUEST_H */
