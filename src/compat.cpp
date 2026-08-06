#include "compat.h"

extern "C" float roundevenf(float x) {
    int save_round = std::fegetround();
    std::fesetround(FE_TONEAREST);
    float result = std::nearbyintf(x);
    std::fesetround(save_round);
    return result;
}

extern "C" double roundeven(double x) {
    int save_round = std::fegetround();
    std::fesetround(FE_TONEAREST);
    double result = std::nearbyint(x);
    std::fesetround(save_round);
    return result;
}
