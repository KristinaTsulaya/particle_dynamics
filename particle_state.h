#include "vector"
#include "cmath"
#include "relations.h"
#include "config_file.h"

class particle_state {
public:
    std::vector<double> position;
    std::vector<double> velocity;

    std::vector<double> velocity_g;

    double diameter;
    double temperature;

    std::vector<double> slip_velocity {0.0, 0.0, 0.0};

    double Re, coefficient;

    particle_state(std::vector<double> &_pos0, std::vector<double> &_vel0, std::vector<double> &_vel_g0, double _temperature, double _diameter) : position(
            _pos0), velocity(_vel0), velocity_g(_vel_g0), temperature(_temperature), diameter(_diameter), Re(0), coefficient(0) {};


    particle_state(particle_state& other) {
        slip_velocity = other.slip_velocity;
        velocity = other.velocity;
        position = other.position;
        Re = other.Re;
        coefficient = other.coefficient;
        velocity_g = other.velocity_g;
        diameter = other.diameter;
        temperature = other.temperature;
    };

    ~particle_state() = default;

    void update_position(double dt);
    void update_velocity(double dt);

    void update_velocity(double dt, particle_state& other_state, double cheme_coefficient);

    void update_base_vars();
    double get_velocity_norm();
    void calc_slip_velocity();
};
