
#ifndef COMPARABLE_H
#define COMPARABLE_H

#include <memory>
#include <cstdlib>
#include <iostream>

using namespace std;

class Comparable {
    public:
	Comparable();
    virtual int compare_to(shared_ptr<Comparable> c);
    virtual ~Comparable();
};

typedef shared_ptr<Comparable> comparable_ref;
#endif
