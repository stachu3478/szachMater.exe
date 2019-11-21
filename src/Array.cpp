#include "Array.h"

template <class T> Array<T>::Array(int init_length)
{
    items = new T[init_length];
    length = 0;
    max_length = init_length;
}

template <class T> Array<T>::Array()
{
    items = new T[10];
    length = 0;
    max_length = 10;
}

template <class T> T Array<T>::push(T item)
{
    if (length++ > max_length)
    {
        if (length == max_length + 1) next = new Array<T>(max_length << 1);
        next.push(item);
    }
    else
    {
        items[length - 1] = item;
    }
}

template <class T> T& Array<T>::operator[](unsigned index)
{
    if (index >= max_length) return next[index - max_length];
    else return *(items + index);
}

template <class T> Array<T>::~Array()
{
    if (length > max_length) delete next;
    delete []items;
}
