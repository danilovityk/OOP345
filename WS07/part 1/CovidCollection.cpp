#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "CovidCollection.h"

using namespace std;

namespace sdds{

CovidCollection::CovidCollection(const std::string filename) {
    fstream file(filename);
    if(file.is_open()){
        Covid covid;
        string buffer;
        while (std::getline(file, buffer)){
                       
            covid.m_country = buffer.substr(0, 25);
            covid.m_city =  buffer.substr(25, 25);
            covid.m_variant = buffer.substr(50, 25);;
            covid.m_year = stod(buffer.substr(75, 5));
            covid.m_numOfCases = stoll(buffer.substr(80, 5));
            covid.m_numOfDeaths = stoll(buffer.substr(85, 5));
            
            covid.m_country = covid.m_country.erase(covid.m_country.find_last_not_of(' ') + 1);
            covid.m_city = covid.m_city.erase(covid.m_city.find_last_not_of(' ') + 1);
            covid.m_variant = covid.m_variant.erase(covid.m_variant.find_last_not_of(' ') + 1);
            
            if (covid.m_year < 2000 || covid.m_year > 2100) {covid.m_year = -1;}
            
            m_collection.push_back(covid);
            
        }
        
        
       
    }else{
        throw "bad file name";
    }
    
    file.close();
}

void CovidCollection::display(std::ostream &out) const {
    for_each(m_collection.begin(), m_collection.end(), [&](Covid item){out << item;});
}

std::ostream& operator<<(std::ostream& out, const Covid& theCovid){
    
    out << left << "| " << setw(21) << theCovid.m_country << " | " << setw(15) << theCovid.m_city << " | " << setw(20) << theCovid.m_variant << right << " | ";
    if (theCovid.m_year == -1) {out << "      ";} else {out << setw(6) << theCovid.m_year;}
    out << " | " << setw(4) << theCovid.m_numOfCases << " | " << setw(3) << theCovid.m_numOfDeaths << " |" << endl;
    return out;
}

}


