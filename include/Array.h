/*! \file Array.h
    \brief Plik nagłówkowy dla klasy Array
*/

#ifndef ARRAY_H
#define ARRAY_H

#include "RangeError.h"
#include <cstdlib>
#include <iostream>

template <class T> class Array
{
    public:
        /*!
            \brief Konstruktor klasy array (bez parametrów)
            Przygotowuje listę 10 elementów o podanym typie
        */
        Array()
        {
            items = new T[10];
            length = 0;
            max_index = 9;
        };
        /*!
            \brief Konstruktor klasy array
            \param init_length Określa początkowy rozmiar listy
        */
        Array(int init_length)
        {
            items = new T[init_length];
            length = 0;
            max_index = init_length - 1;
        };
        ~Array()
        {}

        /*!
            \brief Używa standardowego wejścia
            do wybrania jednego elementu z listy
            Przyjmuje liczby od 1 do ilości elementów
            W przypadku podania niewłaściwego indeksu zwraca wyjątek RangeError
        */
        T &read()
        {
            try
            {
                int id;
                std::cin >> id;
                return refer(id - 1);
            }
            catch(RangeError e)
            {
                std::cout << "Podano niewłaściwy inkeks!\n";
                return read();
            }
        }
        /*!
            \brief Zwraca losowy element z listy
        */
        T &random()
        {
            return refer(rand() % length);
        }

        /*!
            \brief Zwraca obecną ilość elementów na liście
        */
        int len() { return length; };

        /*!
            \brief Implementuje pobieranie elementu
            przy użyciu operatora nawiasowego
            \param index Indeks pobieranego elementu (począwszy od 0)
            W przypadku podania niewłaściwej wartości zwraca wyjątek RangeError
        */
        T &operator[](unsigned index)
        {
            if (index >= length) throw new RangeError();
            if (index >= max_index) return next->refer(index - max_index);
            else return *(items + index);
        }

        /*!
            \brief Dodaje nowy element do listy
            \param item Element, który ma być dodany
        */
        T push(T item)
        {
            //std::cout << "push " << (5 << 1) << std::endl;
            if (++length > max_index)
            {
                if (length == max_index + 1) {
                    //std::cout << "new array" << std::endl;
                    next = new Array<T>(length << 1);
                }
                //std::cout << "into new array" << length << max_index << std::endl;
                return next->push(item);
            }
            else
            {
                return items[length - 1] = item;
            }
        }

    protected:

    private:
        T &refer(int index)
        {
            if (index >= length) throw RangeError();
            if (index >= max_index) return next->refer(index - max_index);
            else return *(items + index);
        }

        int length;
        int max_index;
        T* items;
        Array<T>* next;
};

#endif // ARRAY_H
