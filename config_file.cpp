#include "config_file.h"

namespace config {

    double final_time = 1.0;
    double dt = 125.0e-5;
    std::string method = methods.at(grp::Runge_kutta_2);

    std::vector<double> pos0 {0.0, 0.49, 0.1};
    std::vector<double> vel0 {0.0, -15.0, 0.0};
    double particle_temperature = 450;
    double particle_diameter = 10e-4;

    double gas_temperature = 460;

    std::vector<double> vel_g0 {0.0, 0.0, 10};

    double gas_density = 0.47;
    double gas_viscosity = 1.7e-5;
    double gas_heat_conductivity = 0.021;
    double heat_capacity = 1.27;

    double particle_density = 780;
}
