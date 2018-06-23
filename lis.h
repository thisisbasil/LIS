#ifndef LIS_H
#define LIS_H

#include <vector>
#include <chrono>
#include <memory>
#include "lis_model.h"

class LIS
{
public:
    struct infoTuple
    {
        unsigned long runtime;
        std::vector<int> lis;
    };

    LIS(std::shared_ptr<LIS_model>);
    void setModel(std::shared_ptr<LIS_model>);
    infoTuple runModel(std::vector<int>);


private:
    std::shared_ptr<LIS_model> model;
};

#endif // LIS_H
