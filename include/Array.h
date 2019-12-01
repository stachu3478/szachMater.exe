#ifndef ARRAY_H
#define ARRAY_H

#include "RangeError.h"
#include <iostream>

template <class T> class Array
{
    public:
        Array()
        {
            items = new T[10];
            length = 0;
            max_index = 9;
        };
        Array(int init_length)
        {
            items = new T[init_length];
            length = 0;
            max_index = init_length - 1;
        };
        ~Array()
        {
            // if (length > max_index) delete next;
            // delete []items;
        }

        T &read()
        {
            try
            {
                int id;
                std::cin >> id;
                return refer(id);
            }
            catch(RangeError e)
            {
                std::cout << "Podano niewłaściwy inkeks!\n";
                return read();
            }
        }
        int len() { return length; };
        T &refer(int index)
        {
            if (index >= length) throw new RangeError();
            if (index >= max_index) return next->refer(index - max_index);
            else return *(items + index);
        }

        T &operator[](unsigned index)
        {
            if (index >= length) throw new RangeError();
            if (index >= max_index) return next->refer(index - max_index);
            else return *(items + index);
        }

        void printItems()
        {
            std::cout << "[ ";
            for (int i = 0; i < length; i++)
            {
                // std::cout << refer(i) << ", ";
            }
            std::cout << " ]\n";
        }

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
        int length;
        int max_index;
        T* items;
        Array<T>* next;
};

#endif // ARRAY_H
