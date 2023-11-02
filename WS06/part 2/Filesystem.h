#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H

#include "Directory.h"

namespace sdds{

class Filesystem{
    Directory* m_root;
    Directory* m_current;
    
public:
    Filesystem(const std::string filename, const std::string root = "");
    Filesystem& operator=( Filesystem&&);
    Filesystem (Filesystem&&);
    Filesystem& operator+=(Resource*);
    Directory* change_directory(const std::string& = "");
    Directory* get_current_directory() const;
    ~Filesystem();

    
    Filesystem& operator=(const Filesystem&) = delete;
    Filesystem (const Filesystem&) = delete;

};


}

#endif /* Filesystem_hpp */
