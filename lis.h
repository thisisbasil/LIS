#ifndef LIS_H
#define LIS_H

#include <vector>
#include <chrono>
#include <memory>
#include <iostream>
#include "lis_model.h"

class LIS
{
public:
    struct infoTuple
    {
        unsigned long runtime;
        int length;
        friend std::ostream& operator<<(std::ostream& os, const infoTuple& t)
        {
            os << "length of sequence: " << t.length
               << " runtime: " << t.runtime << "ns";
            return os;
        }
    };

    LIS(std::shared_ptr<LIS_model>);
    void setModel(std::shared_ptr<LIS_model>);
    infoTuple runModel(std::vector<int>);


private:
    std::shared_ptr<LIS_model> model;
};

#endif // LIS_H
