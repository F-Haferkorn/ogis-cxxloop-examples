#pragma once

#include <iostream>
#include <loop>



template<typename TValuePtr, typename TSizeRows, typename TSizeCols>
inline void matrix_print(TValuePtr ptr,  TSizeRows nbofRows, TSizeCols nbofColums)
{
    loop(nbofRows)
    {
        loop(nbofColums, ptr++)
            std::cout<< *ptr<< "\t";
        std::cout<<"\n";
    }
}



