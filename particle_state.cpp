#include "particle_state.h"

void particle_state::update_position(double dt) {
    for (int i = 0; i < position.size(); ++i)
        position[i] += dt * velocity[i];
}

void particle_state::update_velocity(double dt) {
    double a = dt * coefficient;

    for (int i = 0; i < velocity.size(); ++i)
        velocity[i] += a * slip_velocity[i];
}

void particle_state::update_velocity(double dt, particle_state& other_state, const double cheme_coefficient = 1) {
    double a = dt * cheme_coefficient * coefficient;
    double b = dt * cheme_coefficient * other_state.coefficient;

    for (int i = 0; i < velocity.size(); ++i)
        velocity[i] += a * slip_velocity[i] + b * other_state.slip_velocity[i];
}

void particle_state::update_base_vars() {
    double gas_density = config::gas_density;
    double gas_viscosity = config::gas_viscosity;
    double gas_heat_conductivity = config::gas_heat_conductivity;
    double heat_capacity = config::heat_capacity;

    double density = config::particle_density;

    calc_slip_velocity();
    double slip_velocity_norm = get_velocity_norm();

    Re = numerics::relations::calc_Reynolds_number(gas_density, slip_velocity_norm, diameter, gas_viscosity);
    double Pr = numerics::relations::calc_Prandtl_number(heat_capacity, gas_viscosity, gas_heat_conductivity);
    double Nu = numerics::relations::calc_Nu_number(Re, Pr);
    double drag_coefficient = numerics::relations::drag_coefficient(Re);

    coefficient = 0.75 * gas_density * drag_coefficient * slip_velocity_norm / (diameter * density);

}

double particle_state::get_velocity_norm() {
    double norm = 0;
    for (int i = 0; i < slip_velocity.size(); ++i)
        norm += std::pow(slip_velocity[i], 2);
    return std::sqrt(norm);
}

void particle_state::calc_slip_velocity() {
    for (int i = 0; i < slip_velocity.size(); ++i)
        slip_velocity[i] = velocity_g[i] - velocity[i];
}

