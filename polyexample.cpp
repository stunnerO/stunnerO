# include <iostream>
using namespace std;

/*classAnimal  {
 public:
    void speed() {
        cout <<"Who is the fastest animal" <<endl;
    }
 
 };*/
  
class Cheetah  {//: public Animal {
    public :
      void speed() {
        cout << " Cheetah :I am the fastest animal on land"<< endl;
      }
};
class Dolphin  {// : public Animal {
    public :
     void speed(){
        cout << " Dolphin: I am the fastest animal in the sea"<<endl;
     }
};


int main(){
   // Animal a;
    Cheetah c;
    Dolphin d;

    string cheetah ;
    string dolphin;


    cout << " Who is the fastest animal  on land ?"<<endl;
    cin >>  cheetah ;
    cout << "Who is the fastest animal in the sea?"<<endl;
    cin >> dolphin ; 

  //  a.speed();
    c.speed();
    d.speed( );

 return 0;
}