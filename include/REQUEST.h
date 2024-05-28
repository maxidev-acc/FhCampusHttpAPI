#pragma once

#include <string>
#include <vector>
#include <map>



class Studierender;
class Mitarbeiter; 
class FH;

class REQUEST
{
    public:
        // 'structors
        REQUEST() = delete;
        REQUEST(const std::string &i_url);
        REQUEST(const REQUEST &i_src) = delete;    
        ~REQUEST();
        REQUEST &operator=(const REQUEST &i_src) = delete;

        const std::string getURL() const { return url; }
        std::string returnPayload(std::string& url, FH& fh); 
        
       

    private:
        std::string url;
        const std::string student_url = "fh/student/";
        const std::string jahrgang_url = "fh/jahrgang/"; 
        const std::string employee_url = "fh/angestellter/"; 
        const std::string fh_url = "fh/info"; 
        
};