// - Danylo Vityk
// - 176326213
// - dvityk@myseneca.ca
// - Nov 3, 2023

#include "File.h"

using namespace std;
namespace sdds {

File::File(const std::string filename, const std::string represent) {
    m_name = filename;
    m_contents = represent;
}

void File::update_parent_path(const std::string & filepath) {
    m_parent_path = filepath;
}

NodeType File::type() const {
    return NodeType::FILE;
}

std::string File::path() const {
    return m_parent_path + m_name;
}

std::string File::name() const {
    return m_name;
}

int File::count() const {
    return -1;
}

size_t File::size() const {
    return m_contents.length();
}

File::File(){
    m_contents = "";
}


}
