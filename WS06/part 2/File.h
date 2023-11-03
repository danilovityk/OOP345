// - Danylo Vityk
// - 176326213
// - dvityk@myseneca.ca
// - Nov 3, 2023

#ifndef SDDS_FILE_SDDS
#define SDDS_FILE_SDDS

#include "Resource.h"


namespace sdds{

class File : public Resource{
    
    std::string m_contents;
public:
    File();
    File(const std::string filename, const std::string represent = "");
    void update_parent_path(const std::string& filepath);
    NodeType type() const;
    std::string path() const;
    std::string name() const;
    int count() const;
    size_t size() const;
};

}
#endif /* File_hpp */
