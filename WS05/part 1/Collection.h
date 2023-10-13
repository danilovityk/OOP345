#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>

namespace sdds{

template <typename T>
class Collection{
    std::string m_name{};
    T* m_array = nullptr;
    size_t m_size = 0;
    void (*m_observer)(const Collection<T>&, const T&) = nullptr;
public:
    Collection(const std::string& name){
        m_name = name;
        m_array = nullptr;
        m_size = 0;
        m_observer = nullptr;
    }
    Collection(const Collection& source) = delete;
    Collection(const Collection&& source) = delete;
    Collection& operator=(const Collection& a) = delete;
    Collection& operator=(const Collection&& a) = delete;
    ~Collection(){
        delete[] m_array;
    }
    const std::string& name() const{
        return m_name;
    }
    size_t size() const{
        return m_size;
    }
    void setObserver(void (*observer)(const Collection<T>&, const T&)){
        m_observer = observer;
    }
    Collection<T>& operator+=(const T& item){
        
        bool duplicate = false;
        
        for (size_t i = 0; i < m_size; i++){
            if (m_array[i].title() == item.title()){duplicate = true;}
        }
        
        if (!duplicate){
            T* tempArray = new T[m_size + 1];
            
            for (int i = 0; i < int(m_size); i++) {
                tempArray[i] = m_array[i];
            }
            
            tempArray[m_size] = item;
            ++m_size;
            
            delete[] m_array;
            m_array = tempArray;
            if (m_observer){
                m_observer(*this, item);
            }
        }
          
        return *this;
    }
    
    T& operator[](size_t idx) const{
        if (idx >= m_size || idx < 0){
            throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
        }
        return m_array[idx];
    }
    
    T* operator[](const std::string& title) const{
        T* buffer = nullptr;
        for(size_t i = 0; i < m_size; i++){
            if(title == m_array[i].title()){
                buffer = &m_array[i];
                i = m_size;
            }
        }
        return buffer;
    }
};


template<typename T>
std::ostream& operator<<(std::ostream& os, const Collection<T>& coll){
    for (size_t i = 0; i < coll.size(); i++) {
            os << coll[i];
        }
    return os;
}

}
#endif /* Collection_hpp */
