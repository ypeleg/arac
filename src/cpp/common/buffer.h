// Part of Arac Neural Network Composition Library.
// (c) 2008 by Justin S Bayer, <bayer.justin@googlemail.com>


#ifndef Arac_COMMON_BUFFER_INCLUDED
#define Arac_COMMON_BUFFER_INCLUDED


#include <cassert>

#include "typedefs.h"


namespace arac {
namespace common {


class Buffer
{
    public:
        
        Buffer(int rowsize, bool owner=true);
        virtual ~Buffer();
        
        // Add the contents at the given pointer to the last buffer row.
        void add(double* addend_p, int index=-1);
        
        // Add another row to the buffer's contents.
        void expand();
        
        // Set all the contents to zero. 
        void clear();
        
        // Free the memory held by the Buffer object.
        void free_memory();
        
        // Add the given pointer as a row.
        void append(double* row);
        
        // Make the Buffer own the memory.
        void make_owner();
        
        // Tell wether the Buffer owns the memory.
        bool owner();
        
        // Return the size of a single row in the Buffer.
        int rowsize();
        
        // Return the number of rows in the buffer.
        int size();
        
        // Return the pointer at the given index.
        double* operator [](int index);
        
    protected:
        
        DoublePtrVec _content;
        int _rowsize;
        bool _owner;
    
};


inline 
int
Buffer::rowsize()
{
    return _rowsize;
}


inline
int 
Buffer::size()
{
    return _content.size();
}

    
inline
double*
Buffer::operator[] (int index)
{
    return _content[index];
}


inline
void
Buffer::append(double* row)
{
    _owner = false;
    _content.push_back(row);
}


inline
void
Buffer::make_owner()
{
    _owner = true;
}


inline
bool
Buffer::owner()
{
    return _owner;
}


}
}


#endif
