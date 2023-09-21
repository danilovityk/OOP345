//
//  AirportModels.hpp
//  w2p2
//
//  Created by Danik on 19.09.2023.
//

#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H
namespace sdds{

class Airport{
    char* m_code = nullptr;
    char* m_name = nullptr;
    char* m_city = nullptr;
    char* m_state = nullptr;
    char* m_country = nullptr;
    float m_latitude{};
    float m_longtitude{};
    
public:
    ~Airport();
    Airport(const Airport& source);
    char* getState() const;
    char* getCountry() const;
    void display() const;
    Airport& operator=(const Airport& source);
    Airport(const char* code, const char* name, const char* city, const char* state, const char* country, const float latitude, const float longtitude);
    Airport();
    Airport& set(const char* code, const char* name, const char* city, const char* state, const char* country, const float latitude, const float longtitude);
};

std::ostream& operator<<(std::ostream& osrt, const Airport& airport);
void deAloCopy (char*& destination, const char* source);


class AirportLog{

    Airport* m_airports = nullptr;
    size_t m_size{};
public:
    AirportLog();
    AirportLog(const AirportLog& source);
    AirportLog(AirportLog&& source);
    AirportLog& operator= (const AirportLog& source);
    AirportLog& operator= (AirportLog&& source);
    
    
    
    AirportLog(const char* filepath);
    void addAirport(const Airport& airport);
    AirportLog findAirport(const char* stateName,const char* countryName) const;
    Airport operator[](size_t index) const;
    operator size_t() const;
    
    ~AirportLog();
    
};



}
#endif
