#include <iostream>



void shift_left(int* array,unsigned int n,std::size_t k)
{

 int temp;
    for ( int i=0;i<n;i++)
    {
        temp=array[i];
        array[i]=array[k-n+i];
        array [k-n+i]= temp;
    
    }
    


}
int main ()
 {
std::size_t j;
unsigned int n;
std::cout<<"Enter number of elemtns";
std::cin>>j;

std::cout<<"Enter n"<< std::endl;
std::cin>>n;

int *array=new int[j];
std::cout<<"Enter array elements";
 
    for (int i=0; i<j;i++)
    {
        std::cin>>array[i];

    }
    shift_left(array,n,j);

    for(int i =0; i<j; i++)
    {
        std::cout<< array[i] <<'\t';
    }




return 0;



    
}