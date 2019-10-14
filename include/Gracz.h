#ifndef GRACZ_H
#define GRACZ_H

#include <string>

namespace Szachy
{
    class Gracz
    {
        public:
            Gracz(std::string nazwa);
            virtual ~Gracz();

        protected:

        private:
            std::string m_nazwa;
    };
}

#endif // GRACZ_H
