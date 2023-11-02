#ifndef SDDS_DIRECTORY_H
#define SDDS_DIRECTORY_H

#include <vector>
#include "Resource.h"

namespace sdds{

class Directory : public Resource{
    std::vector<Resource*> m_contents;
public:
    Directory();
    Directory(const std::string name);
    void update_parent_path(const std::string& path);
    NodeType type() const;
    std::string path() const;
    std::string name() const;
    int count() const;
    size_t size() const;
    
    void remove(const std::string&, const std::vector<OpFlags>& = std::vector<OpFlags>());
    void display(std::ostream&, const std::vector<FormatFlags>& = std::vector<FormatFlags>()) const;
    
    Directory& operator+=(Resource* newItem);
    Resource* find(const std::string& name, const std::vector<OpFlags>& arr = std::vector<OpFlags>());
    Directory& operator=(const Directory& source) = delete;
    Directory& operator=(const Directory&& source) = delete;
    Directory (const Directory& ) = delete;
    Directory (const Directory&&) = delete;
    ~Directory();
};


}

#endif /* Directory_hpp */
