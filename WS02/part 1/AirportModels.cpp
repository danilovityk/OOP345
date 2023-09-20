//
//  AirportModels.cpp
//  w2p2
//
//  Created by Danik on 19.09.2023.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "AirportModels.h"

using namespace std;
namespace sdds{

std::ostream& operator<<(std::ostream& ostr, const Airport& airport){
    airport.display();
    return ostr;
}


void Airport::display() const {
    if(m_code != nullptr)
    {
        cout << setw(20) << setfill ('.') << right << "Airport Code" << setw(3) << " : " <<  setw(30)<< setfill ('.') << left << m_code << endl;
        cout << setw(20) << setfill ('.') << right << "Airport Name" << setw(3) << " : " << setw(30) << setfill ('.') << left << m_name << endl;
        cout << setw(20) << setfill ('.') << right << "City" << setw(3) << " : " << setw(30) << setfill ('.') << left << m_city << endl;
        cout << setw(20) << setfill ('.') << right << "State" << setw(3) << " : " << setw(30) << setfill ('.') << left << m_state << endl;
        cout << setw(20) << setfill ('.') << right << "Country" << setw(3) << " : " << setw(30) << setfill ('.') << left << m_country << endl;
        cout << setw(20) << setfill ('.') << right << "Latitude" << setw(3) << " : " << setw(30) << setfill ('.') << left << m_latitude << endl;
        cout << setw(20) << setfill ('.') << right << "Longtitude" << setw(3) << " : " << setw(30) << setfill ('.') << left << m_longtitude << endl;
        
    }else {
        cout << "Empty Airport";
    }
};



AirportLog::AirportLog() {
    ;
}

AirportLog::AirportLog(const char *filepath) {
    ifstream file;
    file.open(filepath);
    
    if(file.is_open())
    {
        int counter = 0;
        char ch = '0';
        
        while (file.get(ch)) {
            if (ch == '\n') {
                counter++;
            }
        }
        
        --counter;
        
        m_size = counter;
        
    }else
    {
        cout << endl <<"file not opened (pasta with ketchup pizza with pineapples)" << endl;
    }
    
    file.close();
    file.open(filepath);
    
    if(file.is_open())
    {
        m_airports = new Airport[m_size];
        
        char ch{};
        char code[20]{};
        char name [100]{};
        char city [100]{};
        char state [100]{};
        char country [100]{};
        float latitude{};
        float longtitude{};
        
        while (file.get(ch)) {
            if (ch == '\n') {
                break;
            }
        }
        
        for (int i = 0; i < m_size; i++){
            
            file.getline(code, 100, ',');
            
            file.getline(name, 100, ',');
            
            file.getline(city, 100, ',');
            
            file.getline(state, 100, ',');
            
            file.getline(country, 100, ',');
            
            file >> latitude;
            file.ignore();
            file >> longtitude;
            file.ignore();
            
            m_airports[i].set(code, name, city, state, country, latitude, longtitude);
        }
        
        
        
    }
    
    
}

Airport& Airport::set(const char* code, const char* name, const char* city, const char* state, const char* country, const float latitude, const float longtitude){
    
    deAloCopy(m_code, code);
    deAloCopy(m_name, name);
    deAloCopy(m_city, city);
    deAloCopy(m_state, state);
    deAloCopy(m_country, country);
    m_latitude = latitude;
    m_longtitude = longtitude;
    
    return *this;
}

void AirportLog::addAirport(const sdds::Airport &airport) {
    
    Airport* temp = new Airport[m_size + 1];
    
    
    if (m_size != 0){
        for (int i = 0; i < m_size; i++){
            temp[i] = m_airports[i];
        }
        
        delete[] m_airports;
        
        temp[m_size] = airport;
        m_airports = temp;
        m_size++;
        
    }else{
        
        temp[0] = airport;
        m_size = 1;
        m_airports = temp;
        
    }
}

Airport& Airport::operator=(const Airport& source){
    
    if(this != &source)
    {
        deAloCopy(m_city, source.m_city);
        deAloCopy(m_code, source.m_code);
        deAloCopy(m_name, source.m_name);
        deAloCopy(m_state, source.m_state);
        deAloCopy(m_country, source.m_country);
        
        m_latitude = source.m_latitude;
        m_longtitude = source.m_longtitude;
        
    }
    return *this;
}

sdds::AirportLog &AirportLog::findAirport(char *stateName, char *countryName) const {
    AirportLog result;
    
    
    int counter = 0;
    for (int i = 0; i < m_size; i++)
    {
        if (strcmp(m_airports[i].getState(), stateName) == 0 && strcmp(m_airports[i].getCountry(), countryName) == 0)
        {
            result.addAirport(m_airports[i]);
        }
    }
    
    return result;
}

char* Airport::getState() const{
    return m_state;
}
char* Airport::getCountry() const{
    return m_country;
}

Airport &AirportLog::operator[](size_t index) const {
    
    bool flag = true;
    Airport emptyOne;
    
    if (index < 0 || index >= m_size)
    {
        flag = false;
    }
    
    
    return flag ? m_airports[index] : emptyOne;
}

AirportLog::operator size_t() const {
    return m_size;
}







void deAloCopy (char*& destination, const char* source)
{
    if(destination != nullptr){
        delete destination;
    }
    
    int size = (int)(strlen(source));
    destination = new char [size + 1];
    
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
    
}

Airport::Airport(){};

Airport::Airport(const char* code, const char* name, const char* city, const char* state, const char* country, const float latitude, const float longtitude){
    deAloCopy(m_code, code);
    deAloCopy(m_name, name);
    deAloCopy(m_city, city);
    deAloCopy(m_state, state);
    deAloCopy(m_country, country);
    m_latitude = latitude;
    m_longtitude = longtitude;
}

}
