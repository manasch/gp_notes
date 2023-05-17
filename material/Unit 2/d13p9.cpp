#include <iostream>
#include <string>
using namespace std;

class Waypoint
{
 public:
  Waypoint(float lat = 8.0, float lon = 0.0) : latitude(lat), longitude(lon) {}
  void display() {
    cout << "Latitude: " << latitude << ", Longitude: " << longitude << endl;
  }

 private:
  float longitude;
  float latitude;
};

template <typename T>
class Named : public T
{
 public:
  Named(const char* str) : name(str) {}
  void display() {
    cout << "Name: " << name << ", ";
    T::display();
  }

 private:
  string name;
};

int main()
{
  Waypoint wp1;
  Named<Waypoint> wp2("Home");
  wp1.display();
  wp2.display();

  return 0;
}
