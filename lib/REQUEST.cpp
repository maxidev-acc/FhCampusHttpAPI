#include "Jahrgang.h"
#include "Studierender.h"
#include "Hilfsfunktionen.h"
#include "REQUEST.h"
#include "FH.h"




REQUEST::REQUEST(const std::string &i_url)
  : url(i_url)
  
{
};


REQUEST::~REQUEST()
{
};


std::string REQUEST::returnPayload(std::string& url, FH& fh) {
 
       
        if (url.find(this->student_url) != std::string::npos) {
            std::string id = url.substr(this->student_url.length());
            std::string payload = fh.StudentAPIModell(id);
          
            return payload;  
        };
        if (url.find(this->employee_url) != std::string::npos) {
            std::string id = url.substr(this->employee_url.length());
            std::string payload = fh.EmployeeAPIModell(id);
            
            return payload;  
        };
         if (url.find(this->jahrgang_url) != std::string::npos) {
            std::string id = url.substr(this->jahrgang_url.length());
            std::string payload = fh.JahrgangAPIModell(id);
            return payload;  
        };
         if (url.find(this->fh_url) != std::string::npos) {
            
            std::string payload = fh.FhAPIModell();
            return payload;  
        };
       



    return "Error. Incorrect URL given.";
}
 
 




