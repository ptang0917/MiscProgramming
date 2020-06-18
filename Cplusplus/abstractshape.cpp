#include <iostream>
 
using namespace std;

// The purpose of an abstract class (often referred to as an ABC) is to provide an appropriate base class from which other classes can inherit. 
// Abstract classes cannot be used to instantiate objects and serves only as an interface. 
// Attempting to instantiate an object of an abstract class causes a compilation error.

 
// Base class
class Shape {
   public:
      // pure virtual function providing interface framework.
      virtual double getArea() = 0;
      void setWidth(double w) {
         width = w;
      }
   
      void setHeight(double h) {
         height = h;
      }
   
   protected:
      double width;
      double height;
};
 
// Derived classes
class Rectangle: public Shape {
   public:
      double getArea() {
         return (width * height);
      }
};

class Triangle: public Shape {
   public:
      double getArea() {
         return (width * height)/2;
      }
};

class Circle: public Shape{
   public:
      double getArea() {
         return (width * width * 3.14);
      }

};
 
int main(void) {
   Rectangle Rect;
   Triangle  Tri;
   Circle Cir;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
   
   // Print the area of the object.
   cout << "Total Rectangle area: " << Rect.getArea() << endl;

   Tri.setWidth(5);
   Tri.setHeight(7);
   
   // Print the area of the object.
   cout << "Total Triangle area: " << Tri.getArea() << endl;

   Cir.setWidth(5);
   cout << "Total Circle Area: " << Cir.getArea() << endl; 

   return 0;
}