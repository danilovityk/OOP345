#include "Directory.h"
using namespace std;

namespace sdds{

Directory::Directory(const std::string name){
    m_name = name;
    }


void Directory::update_parent_path(const std::string& path){
    m_parent_path = path;
    for (auto& item : m_contents){
        if(m_parent_path != "/"){
            item->update_parent_path(path);
        }
        
    }
    
}
NodeType Directory::type() const{
    return NodeType::DIR;
}
std::string Directory::path() const{
    return m_parent_path + m_name;
}
std::string Directory::name() const{
    return m_name;
}
int Directory::count() const{
    return int(m_contents.size());
}
size_t Directory::size() const{
    size_t size = 0;
    for (auto &item : m_contents){
        size += item->size();
    }
    return size;
}
Directory& Directory::operator+=(Resource* newItem){
    for(auto &item : m_contents){
        if(item->name() == newItem->name()){
            throw "Name already exists";
        }
    }
   
    m_contents.push_back(newItem);
    m_contents.back()->update_parent_path(path());
    
    return *this;
}
Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& arr){
    Resource* result = nullptr;
    for (auto &item : m_contents){
        if (item->type() == NodeType::DIR && arr.size() != 0){
            Directory* dir = dynamic_cast<Directory*>(item);
            result = dir->find(name, arr);
            //delete dir;
            if(result != nullptr){
                break;
            }
        }else{
            if(item->name() == name){
                result = item;
            }
        }
        
    }
    
    return result;
    
}
Directory::~Directory(){
    for (auto &item : m_contents) {delete item;}
    m_contents.clear();
}

Directory::Directory(){
    m_name = "";
    m_parent_path = "";
}

}
