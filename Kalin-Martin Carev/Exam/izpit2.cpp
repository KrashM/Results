#include <iostream>

struct int_array

{
int *arr; unsigned int size;

}; //Function takes the elemts from the first array and prints them into a new array in the dynamic memory
void dublicate(int_array a[], std::size_t size)
{
    int_array a[]= new int_array[size*2];
     for (int i=0;i<size;i++)
     {
        a[i+1]=a[i]

     }
}

int main()
{
std::size_t array_size;
std::cout<<"enter array size"<std::endl;
std::cin>>array_size;
int_array Array[]= new int_array[array_size];
std::cout<<"Enter array elements"<<std::endl;
for (int i = 0;i<array_size;i++)
{
 std::cin>>array[i]

}
 dublicate(Array,array_size);



}