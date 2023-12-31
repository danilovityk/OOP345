// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <memory>
#include <utility>
#include "DataBase.h"
#include "Profile.h"
#include "Utilities.h"
#include "algorithm"

using namespace std;

namespace sdds {
DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
        DataBase<Profile> result;
        // TODO: Add your code here to build a collection of Profiles.
        //         The result should contain only profiles from `allProfiles`
        //         which are not in `bannedProfiles` using Raw Pointers.
        for(size_t i = 0; i < allProfiles.size(); ++i) {
            bool isBanned = false;

            for(size_t j = 0; j < bannedProfiles.size(); ++j) {
                if(allProfiles[i].m_age == bannedProfiles[j].m_age &&
                    allProfiles[i].m_name.first_name == bannedProfiles[j].m_name.first_name &&
                    allProfiles[i].m_name.last_name == bannedProfiles[j].m_name.last_name) {
                    isBanned = true;
                    j = bannedProfiles.size();
                }
            }
            if(!isBanned) {
                Profile* prof = new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age);
                std::string abobaError = "*** Invalid Address ***";
                try {
                    prof->validateAddress();
                    result += *prof;
                } catch(...) {
                    delete prof;
                    throw abobaError;
                }
                delete prof;
            }
        }
        return result;
    }
}
