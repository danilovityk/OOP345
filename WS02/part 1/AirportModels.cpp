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
        cout << setw(20) << setfill ('.') << right << "Airport Code :" << setw(30)<< setfill ('.') << left << m_code << endl;
        cout << setw(20) << setfill ('.') << right << "Airport Name :" << setw(30) << setfill ('.') << left << m_name << endl;
        cout << setw(20) << setfill ('.') << right << "Airport City :" << setw(30) << setfill ('.') << left << m_city << endl;
        cout << setw(20) << setfill ('.') << right << "Airport State :" << setw(30) << setfill ('.') << left << m_state << endl;
        cout << setw(20) << setfill ('.') << right << "Airport Country :" << setw(30) << setfill ('.') << left << m_country << endl;
        cout << setw(20) << setfill ('.') << right << "Airport Latitude :" << setw(30) << setfill ('.') << left << m_latitude << endl;
        cout << setw(20) << setfill ('.') << right << "Airport Longtitude :" << setw(30) << setfill ('.') << left << m_longtitude << endl;
        
    }else {
        cout << "Empty Airport" << endl;
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
        
    }else
    {
        cout << endl <<"file not opened (pasta with ketchup pizza with pineapples)" << endl;
    }
    
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
        if (strcmp(m_airports[i].getState(), stateName) && strcmp(m_airports[i].getCountry(), countryName))
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







void deAloCopy (char* destination, const char* source)
{
    if(destination != nullptr) delete destination;
    
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
