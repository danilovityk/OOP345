#include "Directory.h"
using namespace std;

namespace sdds{

Directory::Directory(const std::string name){
    m_name = name;
    m_name += '/';
}


void Directory::update_parent_path(const std::string&){
     
}
NodeType Directory::type() const{}
std::string Directory::path() const{}
std::string Directory::name() const{}
int Directory::count() const{}
size_t Directory::size() const{}
Directory& Directory::operator+=(Resource*){}
Resource* Directory::find(const std::string&, const std::vector<OpFlags>&){}
Directory::~Directory(){
    
}

}
