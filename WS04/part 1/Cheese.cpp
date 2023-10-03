#include <string>
#include <iomanip>
#include <iostream>
#include "Cheese.h"

using namespace std;

namespace sdds{

std::string trim(const std::string& input) {
    size_t start = input.find_first_not_of(" ");
    size_t end = input.find_last_not_of(" ");
    return input.substr(start, end - start + 1);
}

Cheese::Cheese(const std::string &str) {
    
    int i = 0;
    m_name = "";
        while(str[i] != ','){
            m_name += str[i];
            i++;
        }
        i++;
    
    string weight{};
        while(str[i] != ','){
            weight += str[i];
            i++;
        }
    m_weight = stoul(weight);
    i++;
    
    string price{};
        while(str[i] != ','){
            price += str[i];
            i++;
        }
    m_price = stod(price);
    i++;
    
    while(i != str.length()){
        m_features += str[i];
        i++;
    }
    
    
    m_name = trim(m_name);
    for(int i = 0; i < m_features.length(); i++)
    {
        if(m_features[i] == ' '){
            m_features.erase(i, 1);
            --i;
        }
    }
    
    for(int i = 0; i < m_features.length(); i++){
        if(m_features[i] == ','){
            m_features[i] = ' ';
        }
    }
}

Cheese Cheese::slice(size_t weight) {
    Cheese result;
    if (m_weight >= weight){
        result = *this;
        result.m_weight = weight;
        m_weight -= weight;
    }
    
    
    return result;
}

std::string Cheese::getName() const {
    return m_name;
}

size_t Cheese::getWeight() const {
    return m_weight;
}

double Cheese::getPrice() const {
    return m_price;
}

std::string Cheese::getFeatures() const{
    return m_features;
}


std::ostream& operator<<(std::ostream& os, const Cheese& cheese){
    cout << '|' <<
    left << setw(21) << cheese.getName() <<
    '|' <<
    setw(5) << cheese.getWeight() <<
    '|' <<
    setprecision(2) << fixed << setw(5) << cheese.getPrice() <<
    '|' <<
    right << setw(34) << cheese.getFeatures() <<
    '|' << endl;
    return os;
}


}


