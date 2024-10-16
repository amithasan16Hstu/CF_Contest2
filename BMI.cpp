#include <bits/stdc++.h>
using namespace std;
class BMI
{
  double height, weight;
  string name;
  int age;

public:
  BMI(string na, int a, double we, double he)
  {
    name = na;
    age = a;
    weight = we;
    height = he;
  }
  double getHeight()
  {
    return height;
  }
  double getWeight()
  {
    return weight;
  }
  double getBMI()
  {
    return weight / (height * height);
  }
  void status()
  {
    if (getBMI() < 18.5)
      cout << "Underweight" << endl;
    else if (getBMI() <= 24.9)
      cout << "Normal range" << endl;
    else if (getBMI() <= 29.9)
      cout << "Overweight" << endl;
    else if (getBMI() >= 30)
    {
      cout << "Obese" << endl;
      obese_class();
    }
  }
  void obese_class()
  {
    if (getBMI() <= 34.9)
      cout << "Obese class I" << endl;
    else if (getBMI() <= 39.9)
      cout << "Obese class II" << endl;
    else
      cout << "Obese class III" << endl;
  }
};
int main()
{
  string n;
  cout << "Enter Your Name: ";
  cin >> n;
  int ag;
  cout << "Enter Your age: ";
  cin >> ag;
  double weight, height;
  cout << "Enter Your Weight: ";
  cin >> weight;

  cout << "-------Select Units For Height-------" << endl;
  int choose;
  cout << "1.For Feet " << endl;
  cout << "2.For Inchs " << endl;
  cout << "3.For Meter " << endl;
  cout << "4.For Centimeter" << endl;

  switch (choose)
  {
    cout << "Now Enter Your Height: ";
    cin >> choose;
  case 1:
    cin >> height;
    height = height * 0.3048;
    break;

  case 2:
    cin >> height;
    height = (height * 12) * 0.3048;
    break;

  case 3:
    cin >> height;
    break;
  case 4:
    cin >> height;
    height = height * 0.01;
    break;

  default:
    break;
  }

  BMI obj(n, ag, weight, height);

  cout << obj.getWeight() << endl;
  cout << obj.getHeight() << endl;
  cout << "--------Body Mass Index------" << endl;
  cout << obj.getBMI() << endl;
  cout << "--------Body Mass Index Status------" << endl;
  obj.status();
}