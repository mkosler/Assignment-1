#include "vector_jar.h"

using namespace std;

VectorJar::VectorJar()
{
    this->elem = vector<Marble>();
}

VectorJar::~VectorJar()
{
    delete this;
}

void VectorJar::add(const Marble& m)
{
    elem.push_back(m);
}

bool VectorJar::is_in_jar(const Marble& m) const
{
    for (int i = 0; i < elem.size(); ++i)
    {
        if (m == elem[i])
        {
            return true;
        }
    }

    return false;
}

const Marble VectorJar::get_marble(int i) const
{
    return elem[i];
}

void VectorJar::remove(const Marble& m)
{
    for (int i = 0; i < elem.size(); ++i)
    {
        if (m == elem[i])
        {
            elem.erase(elem.begin() + i);
        }
    }
}

Marble VectorJar::remove_any()
{
    Marble temp = elem[elem.size() - 1];
    elem.pop_back();
    return temp;
}

void VectorJar::clear()
{
    elem.clear();
}

int VectorJar::marble_number() const
{
    return elem.size();
}

int VectorJar::marble_nsize(Marble::Size s) const
{
    int count = 0;

    for (int i = 0; i < elem.size(); ++i)
    {
        if (s == elem[i].get_size())
        {
            ++count;
        }
    }

    return count;
}

int VectorJar::marble_ncolor(Marble::Color c) const
{
    int count = 0;

    for (int i = 0; i < elem.size(); ++i)
    {
        if (c == elem[i].get_color())
        {
            ++count;
        }
    }

    return count;
}

bool VectorJar::is_empty() const
{
    return elem.empty();
}

void VectorJar::merge(const Jar& jar1, const Jar& jar2)
{
    VectorJar jar3 = VectorJar();

    const int jar1Size = jar1.marble_number();
    const int jar2Size = jar2.marble_number();

    for (int i = 0; i < jar1Size; ++i)
    {
        jar3.add(jar1.get_marble(i));
    }

    for (int i = 0; i < jar2Size; ++i)
    {
        jar3.add(jar2.get_marble(i));
    }
}

void VectorJar::intersect(const Jar& jar1, const Jar& jar2)
{
    VectorJar jar3 = VectorJar();

    const int jar1Size = jar1.marble_number();

    for (int i = 0; i < jar1Size; ++i)
    {
        Marble temp = jar1.get_marble(1);

        if (jar2.is_in_jar(temp))
        {
            jar3.add(temp);
        }
    }
}

void VectorJar::difference(const Jar& jar1, const Jar& jar2)
{
    VectorJar jar3 = VectorJar();

    const int jar1Size = jar1.marble_number();

    for (int i = 0; i < jar1Size; ++i)
    {
        Marble temp = jar1.get_marble(1);

        if (!jar2.is_in_jar(temp))
        {
            jar3.add(temp);
        }
    }
}
