#include "vec4.h"


#include <iomanip>


vec4::vec4(float x, float y, float z, float w) 
    : data({x, y, z, w}) 
{}

vec4::vec4() 
    : vec4(0, 0, 0, 0)
{}

vec4::vec4(const vec4 &v2)
    : data(v2.data)
{}

float vec4::operator[](unsigned int index) const {

    if (index >= data.size()) {
        std::string err_message = "index " + std::to_string(index) + " out of bounds.";
        throw std::out_of_range(err_message);
    } else {
        return data[index];
    }
}


float& vec4::operator[](unsigned int index) {

    if (index >= data.size()) {
        std::string err_message = "index " + std::to_string(index) + " out of bounds.";
        throw std::out_of_range(err_message);
    } else {
        return data[index];
    }
}


vec4& vec4::operator=(const vec4 &v2) {
    if (this == &v2) { // Ensure we do not self-assign
        return *this;
    } else {
        this->data = v2.data;
     return *this; // Return the vec4 pointed at by this (which becomes vec4&)
    }
}


bool vec4::operator==(const vec4 &v2) const {
    return this->data == v2.data;
}

bool vec4::operator!=(const vec4 &v2) const {
    return !(*this == v2); // Using the operator== definition above
}


vec4& vec4::operator+=(const vec4 &v2) {
    for (int i = 0; i < 4; ++i) {
        this->data[i] += v2.data[i];
    }
    return *this; 
}


vec4& vec4::operator-=(const vec4 &v2) {
    for (int i = 0; i < 4; ++i) {
        this->data[i] -= v2.data[i];
    }
    return *this; 
}


vec4& vec4::operator*=(float c) {
    for (int i = 0; i < 4; ++i) {
        this->data[i] *= c;
    }
    return *this; 
}


vec4& vec4::operator/=(float c) {
    if (c == 0) {
        throw std::invalid_argument("division by zero.");
    } else {
        *this *= (1 / c);
        return *this;
    }
}  


vec4  vec4::operator+(const vec4 &v2) const {
    vec4 result;
    for (int i = 0; i < 4; ++i) {
        result[i] = this->data[i] + v2.data[i];
    }
    return result;
}



vec4  vec4::operator-(const vec4 &v2) const {
    vec4 result;
    for (int i = 0; i < 4; ++i) {
        result[i] = this->data[i] - v2.data[i];
    }
    return result;
}


vec4  vec4::operator*(float c) const {
    vec4 result;
    for (int i = 0; i < 4; ++i) {
        result[i] = this->data[i] * c;
    }
    return result;
}


vec4  vec4::operator/(float c) const {
    if (c == 0) {
        throw std::invalid_argument("division by zero.");
    } else {
        vec4 result;
        for (int i = 0; i < 4; ++i) {
            result[i] = this->data[i] / c;
        }
        return result;
    }
}


float dot(const vec4 &v1, const vec4 &v2) {
    float result = 0.0;
    for (int i = 0; i < 4; ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}


vec4 cross(const vec4 &v1, const vec4 &v2) {
    vec4 result;

    result[0] = v1[1] * v2[2] - v1[2] * v2[1];
    result[1] = v1[2] * v2[0] - v1[0] * v2[2];
    result[2] = v1[0] * v2[1] - v1[1] * v2[0];
    result[3] = 0.0;

    return result;
}


float length(const vec4 &v) {
    return std::sqrt(dot(v, v));
}

vec4 operator*(float c, const vec4 &v) {
    return v * c;
}

vec4 normalize(const vec4& v) {
    return v / length(v);vec4 elementWiseProduct(const vec4 &v1, const vec4 &v2);

}

std::ostream &operator<<(std::ostream &o, const vec4 &v) {

    o << std::fixed << std::setprecision(2); // Set stream options prior to content

    for (int i = 0; i < 4; ++i) {

        if (i == 0) {
            o << "\t";
        }
        o << v[i];

        if (i < 3) {
            o << ", "; // Add spacing between components, but not at the end
        }
    }

    return o;
}




