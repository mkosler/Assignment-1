#ifndef _VECTOR_JAR_H_
#define _VECTOR_JAR_H_

#include <vector>
#include "jar.h"

class VectorJar : public Jar
{
    private:
        vector<Marble> elem;

    public:
        VectorJar();

        ~VectorJar();

        void add(const Marble& m);

        bool is_in_jar(const Marble& m) const;

        const Marble get_marble(const int i) const;

        void remove(const Marble& m);

        Marble remove_any();

        void clear();

        int marble_number() const;

        int marble_nsize(Marble::Size s) const;

        int marble_ncolor(Marble::Color c) const;

        bool is_empty() const;

        void merge(const Jar& jar1, const Jar& jar2);

        void intersect(const Jar& jar1, const Jar& jar2);

        void difference(const Jar& jar1, const Jar& jar2);
};

#endif
