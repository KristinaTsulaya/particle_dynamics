#include "vector"
#include "string"
#include "fstream"
#include "particle_state.h"

class solver {
public:
    double dt;
    double final_time;

    particle_state state;

    solver(double _dt, double _final_time, particle_state &_p) : dt(_dt), final_time(_final_time), state(_p) {}

    void solve(std::string &method);

    void euler();
    void runge_kutta_2();

    double step_update();
//    void get_vars_value(double var);
    void out(std::string &method, double duration, std::ofstream &out, const std::string& file);
};