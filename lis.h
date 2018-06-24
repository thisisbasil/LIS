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
        std::vector<int> list;
        friend std::ostream& operator<<(std::ostream& os, const infoTuple& t)
        {
            os << "length of sequence: " << t.list.size()
               << " runtime: " << t.runtime << "ns\n";
            for (auto i : t.list)
                os << i << ' ';
            os << std::endl;
            return os;
        }
    };
    LIS(){}
    LIS(std::shared_ptr<LIS_model>);
    void setModel(std::shared_ptr<LIS_model>);
    infoTuple runModel(std::vector<int>);


private:
    std::shared_ptr<LIS_model> model;
};

#endif // LIS_H
