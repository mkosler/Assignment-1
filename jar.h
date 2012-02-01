#ifndef _JAR_H_
#define _JAR_H_

#include "marble.h"

class Jar
{
    private:

    public:
        Jar() {};

        ~Jar() {};

        // Abstract functions
        virtual void add(const Marble& m) = 0;

        virtual bool is_in_jar(const Marble& m) const = 0;

        virtual const Marble get_marble(const int i) const = 0;

        virtual void remove(const Marble& m) = 0;

        virtual Marble remove_any() = 0;

        virtual void clear() = 0;

        virtual int marble_number() const = 0;

        virtual int marble_nsize(Marble::Size s) const = 0;

        virtual int marble_ncolor(Marble::Color c) const = 0;

        virtual bool is_empty() const = 0;

        virtual void merge(const Jar& jar1, const Jar& jar2) = 0;

        virtual void intersect(const Jar& jar1, const Jar& jar2) = 0;

        virtual void difference(const Jar& jar1, const Jar& jar2) = 0;
};

#endif
