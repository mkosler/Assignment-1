#include "marble.h"

using namespace std;

Marble::Marble()
{
    this->color = Marble::Color(random_color());
    this->size = Marble::Size(random_size());
}

Marble::Marble(Color c)
{
    this->color = c;
    this->size = Marble::Size(random_size());
}

Marble::Marble(Size s)
{
    this->color = Marble::Color(random_color());
    this->size = s;
}

Marble::Marble(Color c, Size s)
{
    this->color = c;
    this->size = s;
}

int Marble::random_color()
{
    return rand() % 4;
}

int Marble::random_size()
{
    return rand() % 3;
}

Marble::Color Marble::get_color() const
{
    return color;
}

void Marble::set_color (Marble::Color c)
{
    this->color = c;
}

Marble::Size Marble::get_size() const
{
    return size;
}

void Marble::set_size (Marble::Size s)
{
    this->size = s;
}

bool operator== (const Marble& m1, const Marble& m2)
{
    return m1.get_size() == m2.get_size() && m1.get_color() == m2.get_color();
}

ostream& operator<< (ostream& os, const Marble& m)
{
    int s = m.get_size();
    string sString;
    switch (s)
    {
        case 0:
        {
            sString = "small";
            break;
        }
        case 1:
        {
            sString = "medium";
            break;
        }
        case 2:
        {
            sString = "large";
            break;
        }
        default:
        {
            throw("Unknown size\n");
        }
    }

    int c = m.get_color();
    string cString;
    switch (c)
    {
        case 0:
        {
            cString = "red";
            break;
        }
        case 1:
        {
            cString = "blue";
            break;
        }
        case 2:
        {
            cString = "yellow";
            break;
        }
        case 3:
        {
            cString = "green";
            break;
        }
        default:
        {
            throw("Unknown color\n");
        }
    }

    return os << "Marble (Size " << sString <<
        " Color " << cString << ')';
}

istream& operator>> (istream& is, Marble& m)
{
    int c, s;
    is >> c >> s;
    m.set_color(Marble::Color(c));
    m.set_size(Marble::Size(s));
    return is;
}























