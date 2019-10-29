#ifndef PIONEKJUZZBITYEXCEPTION_H
#define PIONEKJUZZBITYEXCEPTION_H

#include <stdexcept>

namespace Szachy
{
    class PionekJuzZbityException : public std::exception
    {
        public:
            PionekJuzZbityException(std::string msg);

            std::string getMessage() { return message; }

        protected:

        private:
            std::string message;
    };
}

#endif // PIONEKJUZZBITYEXCEPTION_H
