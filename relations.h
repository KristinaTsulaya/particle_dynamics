#include "cmath"

namespace numerics {
    namespace relations {
        double drag_coefficient(double Re);
        double calc_Reynolds_number(const double density, const double velocity, const double length, const double viscosity);
        double calc_Nu_number(double Re, double Pr);
        double calc_Prandtl_number(double heat_capacity, double gas_viscosity, double gas_heat_conductivity);
    }
}
