#include "Plain.h"

Plain::Plain(int speed, int heightFlight)
{
    this->speed = speed;
    this->heightFlight = heightFlight;
}

ostream& operator<<(ostream& os, const Plain& obj)
{
    os << "Speed: " << obj.speed << "\nHeight: " << obj.heightFlight << "\n";
    return os;
}