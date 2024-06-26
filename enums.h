#include <iostream>
#include <map>

namespace grp {
    enum Names {
        Euler, Runge_kutta_2
    };
}

inline std::map<grp::Names, std::string> methods {
        {grp::Names::Euler,         "Euler"},
        {grp::Names::Runge_kutta_2, "Runge_kutta_2"}
};
