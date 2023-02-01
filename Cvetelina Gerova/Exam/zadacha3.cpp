#include <iostream> 

struct Point {
    double x, y;
};

struct Mesh {
    Point* array;
};

Mesh positive (Mesh m){
    Point* newArr = new Point; 
    
    for (int i = 0; i < sizeof(m); i++) {if (m[i].x )
}