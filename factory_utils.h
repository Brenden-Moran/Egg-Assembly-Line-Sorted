#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
#include "Conveyor.h"

#ifndef FACTORY_UTILS_H
#define FACTORY_UTILS_H

void load_conveyors(std::vector<Conveyor*>& assembly_line);


std::string basic_report(const std::vector<Conveyor*>& assembly_line);

std::string vertical_report(const std::vector<Conveyor*>& assembly_line);

std::string horizontal_report(const std::vector<Conveyor*>& assembly_line);

#endif
