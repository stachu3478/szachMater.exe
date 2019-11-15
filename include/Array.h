#ifndef ARRAY_H
#define ARRAY_H

template <class T> class Array
{
    public:
        Array();
        Array(int init_length);
        virtual ~Array();

        int len() { return length; };
        T &operator[](unsigned index);
        T push();

    protected:

    private:
        int length;
        int max_length;
        T* items;
        Array* next;
};

#endif // ARRAY_H
