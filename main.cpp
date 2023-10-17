#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using std::string;

//RUBRIC3: project code is organized into classes with class attributes
//RUBRIC4: all class data members are explicitly defined as public
class MotoRacer
{
  public:
    int distance = 0;
    int speed = 0;  

    double CalcTime() {
      double time = distance / speed;
      return time;
    }
};

//RUBRIC5: inheritance hierarchies are logical
class Car : public MotoRacer
{
  public:
    Car() {
    distance = 500; //distance in miles
    speed = rand() % 150 + 80; //speed in miles per hour 
    }
};


class Boat : public MotoRacer
{
  public:
    Boat() {
    distance = 300; //distance in miles
    speed = rand() % 80 + 10; //speed in miles per hour
    }
};

class Plane : public MotoRacer
{
  public:
    Plane() {
    distance = 3000; //distance in miles
    speed = rand() % 800 + 200; //speed in miles per hour
    }
};

//RUBRIC1: project code is clearly organized into functions
//RUBRIC2: project accepts input from a user as part of necessary operation of the program
string Intro() {
  std::string type;
  std::cout << "Would you like to race a car, boat or plane?" << "\n";
  std::cin >> type; 
  return type;
}

void Winner(double time1, double time2) {
  if (time1 < time2) {
    std::cout << "You won the race! Congratulations! \n";
  }
  else {
    std::cout << "Sorry! You lost this race. Better luck next time! \n";
  }   
}

void RSG() {
  std::this_thread::sleep_for(std::chrono::seconds(1));  
  std::cout << "Ready...\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));  
  std::cout << "Set...\n";  
  std::this_thread::sleep_for(std::chrono::seconds(1));  
  std::cout << "Go! \n";  
  std::this_thread::sleep_for(std::chrono::seconds(2)); 
}

int main() {

    string type = Intro();
    if (type == "car") {
        Car car1;
        Car car2;
        double ctime1 = car1.CalcTime();
        double ctime2 = car2.CalcTime();
        std::cout << "You chose to race a car! \n";
        RSG();
        std::cout << "Your car's speed was " << car1.speed << " miles per hour. Your car completed the course in " << ctime1 << " hours. \n";
        std::this_thread::sleep_for(std::chrono::seconds(2)); 
        std::cout << "Your competitor's speed was " << car2.speed << " miles per hour. Your competitor's car completed the course in " << ctime2 << " hours.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        Winner(ctime1, ctime2);
    }
    else if (type == "boat") {
        Boat boat1;
        Boat boat2;
        double btime1 = boat1.CalcTime();
        double btime2 = boat2.CalcTime(); 
        std::cout << "You chose to race a boat! \n";
        RSG();
        std::cout << "Your boat's speed was " << boat1.speed << " miles per hour. Your boat completed the course in " << btime1 << " hours. \n";
        std::this_thread::sleep_for(std::chrono::seconds(2)); 
        std::cout << "Your competitor's speed was " << boat2.speed << " miles per hour. Your competitor's boat completed the course in " << btime2 << " hours. \n";
        std::this_thread::sleep_for(std::chrono::seconds(2)); 
        Winner(btime1, btime2);      
    }
    else if (type == "plane") {
        Plane plane1;
        Plane plane2;
        double ptime1 = plane1.CalcTime();
        double ptime2 = plane2.CalcTime(); 
        std::cout << "You chose to race a plane! \n";
        RSG();
        std::cout << "Your plane's speed was " << plane1.speed << " miles per hour. Your plane completed the course in " << ptime1 << " hours. \n";
        std::this_thread::sleep_for(std::chrono::seconds(2)); 
        std::cout << "Your competitor's speed was " << plane2.speed << " miles per hour. Your competitor's plane completed the course in " << ptime2 << " hours. \n";    
        std::this_thread::sleep_for(std::chrono::seconds(2)); 
        Winner(ptime1, ptime2);                 
    }
    else {
        main();  
    } 
    string response;
    std::cout << "Would you like to play again? Y/N \n";
    std::cin >> response;
    if (response == "N") { std::cout << "Game over \n";}
    else if (response == "n") { std::cout << "Game over \n";}
    else {main();}
    return 0;
}