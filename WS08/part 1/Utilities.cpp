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
        for(size_t i = 0; i < allProfiles.size(); ++i){
            for(size_t b = 0; b < bannedProfiles.size(); ++b){
                if(allProfiles[i].m_age != bannedProfiles[b].m_age && allProfiles[i].m_name.first_name != bannedProfiles[b].m_name.first_name && allProfiles[i].m_name.last_name != bannedProfiles[b].m_name.last_name){
                    Profile* aboba = new Profile(allProfiles[i]);
                    try{
                        aboba->validateAddress();
                        result += *aboba;
                    }catch(const char *){
                       
                        //cerr << "addres is not valid in exclude raw function";
                    }
                    delete aboba;
                    b = bannedProfiles.size();
                }
            }
        }





		return result;
	}
}
