# include <iostream>
using namespace std;

class Rectangle {
private:
   int width ,height;

   public:
    Rectangle (int w,int h){
      width = w ;
      height = h;

    }

 int area (){
    return width * height ;
 }

};

 
 int main (){
   int width ,height ;
 cout <<"Welcome to this test trial" <<endl;
    
    cout << "Enter width: ";
     cin >> width ;
     cout << " Enter height :";
     cin >> height;
     Rectangle rect(width,height) ;
    cout << "Area is : " << rect.area () ;




    return 0;
 }