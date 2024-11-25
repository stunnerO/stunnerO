# include <iostream>
# include <string>
using namespace std;

class Car{
 private:   
     string color;
     string make;
     string  model ;

public:
     Car (string carColor,string carMake,string carModel)  {    
         color = carColor ;
         make = carMake;
         model = carModel;

     }

    

    void  displayCarDetails() {
         cout <<"Car Details: " <<endl;
         cout <<"Colour :"<<color <<endl;
          cout <<"MAke :" << make<<endl;
           cout <<"Model :"  <<model<<endl ;
    }


};

int main(){
    Car myCar("cyan blue", "Mercedes Benz"," S class");

    myCar.displayCarDetails();
    





    return 0;
}
