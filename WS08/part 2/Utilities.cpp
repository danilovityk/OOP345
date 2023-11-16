// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <memory>
#include <utility>
#include "DataBase.h"
#include "Profile.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
        DataBase<Profile> result;

        for(size_t i = 0; i < allProfiles.size(); ++i) {
            bool isBanned = false;

            for(size_t b = 0; b < bannedProfiles.size(); ++b) {
                if(allProfiles[i].m_age == bannedProfiles[b].m_age &&
                    allProfiles[i].m_name.first_name == bannedProfiles[b].m_name.first_name &&
                    allProfiles[i].m_name.last_name == bannedProfiles[b].m_name.last_name) {
                    isBanned = true;
                    b = bannedProfiles.size();
                }
            }
            if(!isBanned) {
                Profile* tempProfile = new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age);
                std::string abobaError = "*** Invalid Address ***";
                try {
                    tempProfile->validateAddress();
                    result += *tempProfile;
                } catch(...) {
                    delete tempProfile;
                    throw abobaError;
                }
                delete tempProfile;
            }
        }
        return result;
    }

DataBase<Profile> excludeSmart(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
        DataBase<Profile> result;
    
        for(size_t i = 0; i < allProfiles.size(); ++i) {
            
            bool banned = false;
            
            for(size_t b = 0; b < bannedProfiles.size(); ++b) {
                
                if(allProfiles[i].m_age == bannedProfiles[b].m_age && allProfiles[i].m_name.first_name == bannedProfiles[b].m_name.first_name && allProfiles[i].m_name.last_name == bannedProfiles[b].m_name.last_name) {
                    
                    banned = true;
                    b = bannedProfiles.size();
                    
                }
                
            }
            if(!banned) {
                std::unique_ptr<Profile> tempProfile(new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age));
                std::string abobaError = "*** Invalid Address ***";
                try {
                    tempProfile->validateAddress();
                    result += *tempProfile;
                } catch(...) {
                    throw abobaError;
                }
            }
        }
        
        
        
        
            return result;
        }
}
