#include <iostream>
#include "solver.h"

int main() {

    double dt = config::dt;
    double final_time = config::final_time;

    particle_state state(config::pos0,
                         config::vel0,
                         config::vel_g0,
                         config::particle_temperature,
                         config::particle_diameter);

    solver solver(dt, final_time, state);
    std::string method = config::method;

    std::ofstream out;
    std::string file = "/home/tsulayakris/CLionProjects/qubiq-solver/data";
    file += "_" + std::to_string(dt) + '_' + method;
    out.open(file);

    double duration = 0;
    while (duration < final_time) {
        solver.out(method, duration, out, file);
        solver.solve(method);
        duration += dt;
    }
    out.close();

    std::string run_line = "time_step: " + std::to_string(config::dt) + "\n" + "final_time: " + std::to_string(config::final_time) + "\n" + "Method: " + method;
    std::cout << run_line;
    return 0;
}
