#include <exception>
#include <string>

class FHException : public std::exception
{
    public:
        FHException(const std::string &i_message) : m_strMessage(i_message) {}
        ~FHException() {}

        const std::string &getMessage() const { return m_strMessage; }

    private:
        std::string m_strMessage;
};