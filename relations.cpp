#include "relations.h"

double numerics::relations::drag_coefficient(double Re) {
    double result;
    if (Re < 1000)
        result = 24.0 / Re * (1.0 + 0.15 * std::pow(Re, 0.687));
    else
        result = 0.44;
    return result;
}

double numerics::relations::calc_Reynolds_number(const double density, const double velocity, const double diameter,
                                                 const double viscosity) {
    return (density * velocity * diameter / viscosity);
}

double numerics::relations::calc_Nu_number(double Re, double Pr) {
    return 2.0 + 0.6 * std::pow(Re, 0.5) * std::pow(Pr, 0.333);

}

double numerics::relations::calc_Prandtl_number(double heat_capacity, double gas_viscosity,
                                                double gas_heat_conductivity) {
    return (heat_capacity * gas_viscosity / gas_heat_conductivity);
}
