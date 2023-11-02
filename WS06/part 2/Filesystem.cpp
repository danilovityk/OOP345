#include <fstream>
#include <string>
#include "Filesystem.h"
#include "File.h"
using namespace std;
namespace sdds{

Filesystem::Filesystem(const std::string filename, const std::string root) {
    m_root = new Directory(root);
    fstream file;
    file.open(filename);
    if(file.is_open()){
        while(file){
            string buffer = "";
            string fileP = "";
            string fileCont = "";
            m_current = m_root;
            getline(file, buffer);
            if(!buffer.empty()){
                size_t delimiterPos = buffer.find('|');
                
                if (delimiterPos != std::string::npos) {
                    fileP = buffer.substr(0, delimiterPos);
                    fileCont = buffer.substr(delimiterPos + 1);
                } else {
                    
                    fileP = buffer;
                    fileCont = "";
                }
                fileP.erase(0, fileP.find_first_not_of(" "));
                fileP.erase(fileP.find_last_not_of(" ") + 1);
                
                if (fileP.back() != '/'){
                    // object is a file
                    fileCont.erase(0, fileCont.find_first_not_of(" "));
                    fileCont.erase(fileCont.find_last_not_of(" ") + 1);
                    
                    File* file = new File(fileP.substr(fileP.find_last_of("/") + 1), fileCont);
                    
                    std::vector<std::string> folders;
                    size_t start = 0;
                    size_t end = 0;
                    while ((end = fileP.find('/', start)) != std::string::npos) {
                        folders.push_back(fileP.substr(start, (end - start) + 1));
                        start = end + 1;
                    }
                    Directory* directory1 = nullptr;
                    m_current = m_root;
                    for (auto &folder : folders){
                        
                        if (m_root->find(folder) == nullptr){
                            directory1 = new Directory(folder);
                            m_current->operator+=(directory1);
                            m_current = directory1;
                        }else{
                            m_current = dynamic_cast<Directory*>(m_root->find(folder));
                        }
                    }
                    m_current->operator+=(file); //need to add the file to the last directory
                    
                }else{
                    // object is a directory
                    std::vector<std::string> folders;
                    size_t start = 0;
                    size_t end = 0;
                    while ((end = fileP.find('/', start)) != std::string::npos) {
                        folders.push_back(fileP.substr(start, (end - start) + 1));
                        start = end + 1;
                    }
                    
                    Directory* directory1 = nullptr;
                    m_current = m_root;
                    for (auto &folder : folders){
                        
                        if (m_root->find(folder) == nullptr){
                            directory1 = new Directory(folder);
                            m_current->operator+=(directory1);
                        }else{
                            m_current = dynamic_cast<Directory*>(m_root->find(folder));
                        }
                    }
                }
            }
        }
        file.close();
         
    }else{
        throw "File cannot be opened";
    }
    
}

Filesystem& Filesystem::operator=(Filesystem && source) {
    if(this != &source){
        delete m_root;
        delete m_current;
        
        m_root = source.m_root;
        m_current = source.m_current;
        
        source.m_root = nullptr;
        source.m_current = nullptr;
    }
    
    
    return *this;
}

Filesystem::Filesystem( Filesystem && source) {
    *this = std::move(source);
}

Filesystem &Filesystem::operator+=(Resource * added) {
    m_current->operator+=(added);
    return *this;
}

Directory *Filesystem::change_directory(const std::string & name) {
    if(name == ""){
        m_current = m_root;
    }else{
        if(m_current->find(name) != nullptr){
            m_current = dynamic_cast<Directory*>(m_current->find(name));
        }else{
            throw std::invalid_argument("Cannot change directory! DIR_NAME not found!");
        }
    }
    return m_current;
}

Directory *Filesystem::get_current_directory() const {
    return m_current;
}

Filesystem::~Filesystem() {
    // THIS MIGHT BE THE PROBLEM
    delete m_root;
//    delete m_current;
}

}
