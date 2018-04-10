//
// Created by Larry Hsiao on 4/7/2018.
//

#ifndef LETO_TEMPERATURE_H
#define LETO_TEMPERATURE_H

#include <sensors/sensor.h>
#include <string>

class Temperature {
    virtual std::string value()=0;
};

#endif //LETO_TEMPERATURE_H
