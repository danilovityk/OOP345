
//- Danylo Vityl
//- 176326213
//- dvityk@myseneca.ca
//- 15 Sep 2023

#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

extern float g_taxrate;
extern float g_discount;

namespace sdds {

class RideRequest{
    
private:
    char m_name [10];
    char* m_details;

    float m_price;
    bool m_discount;
    
public:
    RideRequest();
    RideRequest(const RideRequest& source);
    ~RideRequest();
    RideRequest& operator=(const RideRequest& source);
    std::istream& read(std::istream& istr);
    void display() const;
    
};

}

#endif /* SDDS_RIDEREQUEST_H */
