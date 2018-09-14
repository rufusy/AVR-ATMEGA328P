/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

int main()
{
    int size = 10;
    
    /* c style array */
    int sarray[10];
    int *darray = new int[size];
    for (int i=0; i<size; ++i)
    {
        sarray[i] = i;
        darray[i] = i;
    }
    // prevent mem lick
    delete [] darray;
    /* end c style array */
    
    /* array with vector */ 
    typedef std::vector<int> int_vect_t;
    int_vect_t array(size);     // make room for 10 integers
                                // and initialize them to 10
    for (int i=0; i<size; i++)
    {
        array[i] = i;
    }
    /*
        vector combines advantages of both static and the dynamic array.
        it takes a non-const size param such as the dynamic one and automatically 
        deletes the used memmory like the static one
    */
    /* end array with vector */
    
    for (int i=0; i<size; i++)
    {
        std::cout<<"array at["<<i<<"]: "<< array[i]<<std::endl;
    }
    
    std::cout<<std::endl;
    /*
        depending on the implementation, this snippet produces 
        different output
    */
    for (int i=0; i<size; i++)
    {
        try
        {
            std::cout<<"array at["<<i<<"]: "<< array.at(i)<<std::endl;
        }
        catch(std::out_of_range o)
        {
            std::cout<<o.what()<<std::endl;
        }
    }
   
    /* what if you don't know number of elements? */
    std::vector<char> c_array;
    char c = 0;
    while (c != 'x')
    {
        std::cin>>c;
        c_array.push_back(c);
    }
    
    /*  to avoid a too-often reallocation of the vector's storage 
        use a reserve() member function
    */
    std::vector<char> c_array2;
    char s = 0;
    c_array2.reserve(10);   // make room for 10 elements
    while (s != 'x')
    {
        std::cin>>s;
        c_array2.push_back(s);
    }
    
    return 0;
}
