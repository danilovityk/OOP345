#include <iostream>
#include <iomanip>
#include <string.h>
#include "RideRequest.h"

float g_taxrate{};
float g_discount{};

using namespace std;

namespace sdds{
    
    RideRequest::RideRequest() {
        
        m_name[0] = '\0';
        m_details = nullptr;
        m_price = 0;
        m_discount = false;
        
    }

    std::istream &RideRequest::read(std::istream &istr) {
        if (istr){
            size_t sizet = 0;
            
            char temp_flag;
            char details[100];
            
            istr.get(m_name, 9, ',');
            istr.ignore();
           
            
            istr.get(details, 100, ',');
            istr.ignore();
            
            delete m_details;
            sizet = strlen(details);
            int size = (int)sizet;
            m_details = new char [size + 1];
            
            for(int i = 0; i < size; i++){
                m_details[i] = details[i];
            }
            
            istr >> m_price;
            istr.ignore();
            
            istr.get(temp_flag);
            
            if (temp_flag == 'Y' || temp_flag == 'y')
                m_discount = true;
            
            if (temp_flag == 'N' || temp_flag == 'n')
                m_discount = false;
            
            istr.ignore();
            
        }
        
        return istr;
    }

    void RideRequest::display() const {
      
        static int counter = 0;
        counter++;
        cout << left << setw(2) << counter << ". ";
        
        if (m_name[0] != '\0')
        {
//            Name          |Ride Description         |Price w/ Tax|Price with Discount
//            1 . Jack      |North York               |10.16       |
//            2 . Julian    |Mississauga              |9.03        |         7.88
//            3 . Susan     |East York                |8.58        |
//            4 . John      |Scarborough              |7.90        |         6.75
//            5 . Nika      |Thornhill                |6.77        |
            
            cout << left << setw(10) << m_name << '|';
            cout << left << setw(25) << m_details << '|';
            cout << left << setw(12) << setprecision(2) << fixed << (m_price * g_discount) << '|';
            cout << left << setw(13);
            
            if (m_discount)
                cout << right << setprecision(2) << (m_price * g_discount * g_taxrate);
            
            
            
        }else{
            cout << "No Ride Request";
        }
        
        cout << endl;
    }

RideRequest::RideRequest(const sdds::RideRequest &source) {
    m_details = nullptr;
    *this = source;
}

RideRequest::~RideRequest() { 
    delete[] m_details;
}

sdds::RideRequest &RideRequest::operator=(const sdds::RideRequest &source)
{
    
    if (this != &source)
    {
        delete[] m_details;
        
        strcpy(m_name, source.m_name);
        m_price = source.m_price;
        m_discount = source.m_discount;
        
        size_t sizet = strlen(source.m_details);
        int size = (int)sizet;
        m_details = new char[size+1];
        
        for(int i = 0; i < size; i++)
        {
            m_details[i] = source.m_details[i];
        }
        
        m_details[size] = '\0';
        
    }
    
    
    return *this;
}


    
}



