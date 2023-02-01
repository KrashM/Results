#include <iostream>
#include <string>

void shake (char* s, unsigned size)

{   int counter = 0;
    
 for(int i=0;i<size,i++)
    if('A'<=s[i]<='Z')
    { counter++;
     s[counter] = s[i];
    }
    else 
    {
        s[i+counter]= s [i];
    }
}

int main()
{
std::size_t Max_element;
char* array = new char[Max_element];
std::Cin.getline(array);

shake(array, Max_element);
return 0;


}