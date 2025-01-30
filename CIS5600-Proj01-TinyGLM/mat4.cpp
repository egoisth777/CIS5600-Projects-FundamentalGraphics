#include "mat4.h"

#include <iomanip> // std::setprecision()


mat4::mat4(const vec4 &col0, const vec4 &col1, const vec4 &col2, const vec4 &col3)
    : data({col0, col1, col2, col3})
{}

mat4::mat4(float diag)
    : mat4(vec4({diag, 0, 0, 0}),
           vec4({0, diag, 0, 0}),
           vec4({0, 0, diag, 0}),
           vec4({0, 0, 0, diag}))
{}

mat4::mat4()
    : mat4(1.0)
{}

mat4::mat4(const mat4 &m2)
    : data(m2.data) // Assumes that std::array has valid copy constructor
{}



vec4 mat4::operator[](unsigned int index) const {
    if (index >= data.size()) {
        std::string err_message = "index " + std::to_string(index) + " out of bounds.";
        throw std::out_of_range(err_message);
    } else {
        return data[index];
    }
}


vec4& mat4::operator[](unsigned int index) {
    if (index >= data.size()) {
        std::string err_message = "index " + std::to_string(index) + " out of bounds.";
        throw std::out_of_range(err_message);
    } else {
        return data[index];
    }
}


vec4 row(const mat4 &m, unsigned int index) {
    if (index >= 4) {
        std::string err_message = "index " + std::to_string(index) + " out of bounds.";
        throw std::out_of_range(err_message);
    } else {
        return vec4({m[0][index],
                     m[1][index],
                     m[2][index],
                     m[3][index]});
    }
}

mat4 transpose(const mat4 &m) {
    return mat4({row(m, 0), row(m, 1), row(m, 2), row(m, 3)});
}

mat4 mat4::rotate(float angle, float x, float y, float z) {
    float angle_radians = angle * (3.1415 / 180);

    // Rodrigeus' formula
    mat4 I = mat4();
    mat4 K = mat4({vec4({0, z, -y, 0}),
                   vec4({-z, 0, x, 0}),
                   vec4({y, -x, 0, 0}),
                   vec4({0, 0, 0, 0})});
    mat4 R = I + (sin(angle_radians)) * K + (1 - cos(angle_radians)) * K * K;


    return R;
}

mat4 mat4::translate(float x, float y, float z) {
    mat4 m = mat4();

    m[3] = vec4({x, y, z, 1});

    return m;
}

mat4 mat4::scale(float x, float y, float z) {
    return mat4({vec4({x, 0, 0, 0}),
                 vec4({0, y, 0, 0}),
                 vec4({0, 0, z, 0}),
                 vec4({0, 0, 0, 1})});
}



mat4 mat4::identity() {
    return mat4();
}



mat4& mat4::operator=(const mat4 &m2) {
    data = m2.data;
    return *this; // Turn mat4* this into mat4 with *dereference, then implicitly cast to ref
}

bool mat4::operator==(const mat4 &m2) const {
    return data == m2.data; // std::array::operator== does in fact do element-wise comparison
}

bool mat4::operator!=(const mat4 &m2) const {
    return data != m2.data;
}


mat4& mat4::operator+=(const mat4 &m2) {
    for (int i = 0; i<4; ++i) {
        data[i] = data[i] + m2.data[i];
    }
    return *this;
}

mat4& mat4::operator-=(const mat4 &m2) {
    for (int i = 0; i<4; ++i) {
        data[i] = data[i] - m2.data[i];
    }
    return *this;
}


mat4& mat4::operator*=(float c) {
    for (int i = 0; i<4; ++i) {
        data[i] = data[i] * c;
    }
    return *this;
}

mat4& mat4::operator/=(float c) {
    if (c == 0) {
        throw std::invalid_argument("division by zero.");
    } else {
        for (int i = 0; i<4; ++i) {
            data[i] = data[i] / c;
        }
        return *this;
    }
}

mat4 mat4::operator+(const mat4 &m2) const {
    mat4 copy_of_this = *this; // Since we can't modify itself (const function)
    return copy_of_this += m2;
}


mat4 mat4::operator-(const mat4 &m2) const {
    mat4 copy_of_this = *this;
    return copy_of_this -= m2;
}

mat4 mat4::operator*(float c) const {
    mat4 copy_of_this = *this;
    return copy_of_this *= c;
}

mat4 mat4::operator/(float c) const {
    if (c == 0) {
        throw std::invalid_argument("division by zero.");
    } else {
        mat4 copy_of_this = *this;
        return copy_of_this /= c;
    }

}



mat4 mat4::operator*(const mat4 &m2) const {

    mat4 m = mat4();

    // m[0][0] = dot(row(copy_of_this, 0), m2[0]);
    // m[0][1] = dot(row(copy_of_this, 1), m2[0]);
    // ...

    // m[2][0] = dot(row(copy_of_this, 0), m2[2);


    for (int col = 0; col<4; ++col) {
        for (int roww = 0; roww<4; ++roww) {
            m[col][roww] = dot(row(*this, roww), m2[col]);
        }
    }

    return m;

}

vec4 mat4::operator*(const vec4 &v) const {
    vec4 result;
    for (int i = 0; i<4; ++i) {
        result[i] = dot(row(*this, i), v);
    }
    return result;
}



vec4 operator*(const vec4 &v, const mat4 &m) {
    vec4 result;
    for (int i = 0; i<4; ++i) {
        result[i] = dot(v, m[i]);
    }
    return result;
}


mat4 operator*(float c, const mat4 &m) {
    mat4 result;
    for (int i = 0; i<4; ++i) {
        result[i] = m[i] * c; // Because this is implemented for vec4
    }
    return result;
}

std::ostream& operator<<(std::ostream &o, const mat4 &m) {

    o << std::fixed << std::setprecision(2); // Set stream options prior to content


    for (int row = 0; row<4; ++row) {
        for (int col = 0; col<4; ++col) {

            if (col == 0) {
                o << "\t";
            }

            o << m[col][row];

            if (col < 3) {
                o << ", ";
            } else {
                o << std::endl;

            }

        }
    }

    return o;
}




