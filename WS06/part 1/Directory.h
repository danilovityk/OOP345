#ifndef SDDS_DIRECTORY_H
#define SDDS_DIRECTORY_H

#include <vector>
#include "Resource.h"

namespace sdds{

class Directory : public Resource{
    std::vector<Resource> m_contents;
public:
    Directory(const std::string name);
    void update_parent_path(const std::string&);
    NodeType type() const;
    std::string path() const;
    std::string name() const;
    int count() const;
    size_t size() const;
    Directory& operator+=(Resource*);
    Resource* find(const std::string&, const std::vector<OpFlags>&);
    Directory& operator=(const Directory& source) = delete;
    Directory& operator=(const Directory&& source) = delete;
    ~Directory();
};


}

#endif /* Directory_hpp */
