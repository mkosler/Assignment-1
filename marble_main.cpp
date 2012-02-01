#include "marble.h"
#include <ctime>

using namespace std;

Marble::Color char_to_color (char c)
{
	c = tolower(c);
    if (c == 'r')
    {
        return Marble::red;
    }
    else if (c == 'b')
    {
        return Marble::blue;
    }
    else if (c == 'y')
    {
        return Marble::yellow;
    }
    else if (c == 'g')
    {
        return Marble::green;
    }
    else
    {
        throw "Bad color\n";
    }
}

Marble::Size char_to_size (char s)
{
    if (s == 's')
    {
        return Marble::small;
    }
    else if (s == 'm')
    {
        return Marble::medium;
    }
    else if (s == 'l')
    {
        return Marble::large;
    }
    else
    {
        throw "Bad size!\n";
    }
}

int main()
{
    try
    {
        srand(time(0));

        Marble m1;
        Marble m2(Marble::blue);
        Marble m3(Marble::large);
        Marble m4(Marble::green, Marble::small);

        cout << "Using the four constructors:\n";
        cout << "Randon color and random size: " << m1 << endl;
        cout << "Chosen color and random size: " << m2 << endl;
        cout << "Random color and chosen size: " << m3 << endl;
        cout << "Chosen color and chosen size: " << m4 << endl;

        while (true)
        {
            cout << "\n\nInput a color (r,b,y,g) and a size (s,m,l) for marble A.\n";
            char c, s;
            cin >> c >> s;
            Marble mA(char_to_color(c), char_to_size(s));
            cout << "\nInput a color (r,b,y,g) and a size (s,m,l) for marble B.\n";
            cin >> c >> s;
            Marble mB(char_to_color(c), char_to_size(s));
            if (mA == mB)
            {
                cout << "Equal!\n";
            }
            else
            {
                cout << "Not equal!\n";
            }
            cout << "\n\nContinue? (Type 'n' to quit)\n";
            cin >> c;
            if (c == 'n')
            {
                break;
            }
        }
    }
    catch (char* str)
    {
        cerr << str << endl;
    }
}
