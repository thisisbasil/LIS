#include "lis.h"

LIS::LIS(std::shared_ptr<LIS_model> _model)
{
    this->setModel(_model);
}

LIS::infoTuple LIS::runModel(std::vector<int> list)
{
    LIS::infoTuple retval;
    auto start = std::chrono::system_clock::now();
    retval.lis = this->model->run(list);
    auto end = std::chrono::system_clock::now();
    retval.runtime = std::chrono::duration_cast<std::chrono::nanoseconds>
                     (end-start).count();
    return retval;
}

void LIS::setModel(std::shared_ptr<LIS_model> _model)
{
    this->model = _model;
}
