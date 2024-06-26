#include "vector"
#include "string"
#include "enums.h"

namespace config {

    extern double final_time;
    extern double dt;
    extern std::string method;

    extern std::vector<double> pos0;
    extern std::vector<double> vel0;
    extern double particle_temperature;
    extern double particle_diameter;

    extern double gas_temperature;

    extern std::vector<double> vel_g0;

    extern double gas_density;
    extern double gas_viscosity;
    extern double gas_heat_conductivity;
    extern double heat_capacity;

    extern double particle_density;
}