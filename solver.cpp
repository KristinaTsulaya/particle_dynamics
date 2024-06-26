#include "solver.h"

void solver::solve(std::string& method) {
    state.update_base_vars();

    if (method == methods.at(grp::Names::Euler))
        euler();
    else if (method == methods.at(grp::Names::Runge_kutta_2))
        runge_kutta_2();
}

void solver::euler() {
    state.update_position(dt);
    state.update_velocity(dt);
}

void solver::runge_kutta_2() {
    particle_state tmp_state(state);
    particle_state origin_state(state);

    tmp_state.update_position(dt);
    tmp_state.update_velocity(dt);

    double RK2_coefficient = 0.5;

    for (size_t i = 0; i < state.velocity.size(); i++)
        state.velocity[i] += tmp_state.velocity[i];
    state.update_position(dt * RK2_coefficient);

    tmp_state.update_base_vars();

    state.velocity = origin_state.velocity;
    state.update_velocity(dt, tmp_state ,RK2_coefficient);
}

void solver::out(std::string& method, double duration, std::ofstream& out, const std::string& file) {
    out << duration << " ";
    for (int i = 1; i < state.position.size(); ++i)
        out << state.position[i] << " ";
    for (int i = 1; i < state.velocity.size(); ++i)
        out << state.velocity[i] << " ";
    out << std::endl;
}
