#ifndef MATHF_H
#define MATHF_H

#include <cmath>

namespace math {
    inline float toRadians(float degrees){
        return (degrees * M_PI) / 180.0f;
    }

    inline float toDegrees(float radians){
        return (radians * 180.0f) / M_PI;
    }

    inline float cotangent(float value){
        float angle = toRadians(value);
        return (1.0f / ((float)tan(angle)));
    }

};

#endif
