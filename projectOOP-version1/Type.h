#include <iostream>
#include <string.h>
#include <fstream>
#include "Manager.h"

using namespace std;

#ifndef __TYPE_H__
#define __TYPE_H__

class Type
{
    public:
        virtual ~Type() {}
        virtual void print() const = 0;
};
#endif
