//
// Created by Larry Hsiao on 4/6/2018.
//

#ifndef LETO_SENSOR_TEMPERATURE_H
#define LETO_SENSOR_TEMPERATURE_H

#include "sensor.h"

class TemperatureSensor : public Sensor{
    double value() override;
};

#endif //LETO_SENSOR_TEMPERATURE_H
