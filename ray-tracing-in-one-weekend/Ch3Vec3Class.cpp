#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
 private:
  double e[3];

 public:
  vec3();
  vec3(double e1, double e2, double e3);
  ~vec3();

  double x() const { return e[0]; }
  double y() const { return e[1]; }
  double z() const { return e[2]; }
  double length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
  }
  double length() const { return sqrt(length_squared()); }

  vec3 operator-() const { return vec3{-e[0], -e[1], -e[2]}; }
  double operator[](int i) const { return e[i]; }
  double& operator[](int i) { return e[i]; }
  vec3 operator+=(const vec3& v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
  }
  vec3 operator*=(const double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
  }
  vec3 operator/=(const double t) { return *this *= 1 / t; }
};

vec3::vec3() : e{0, 0, 0} {}
vec3::vec3(double e1, double e2, double e3) : e{e1, e2, e3} {}

vec3::~vec3() {}

using point3 = vec3;
using color = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
  return out << v.x() << " " << v.y() << " " << v.z();
}

inline vec3 operator+(const vec3& u, const vec3& v) {
  return vec3{u.x() + v.x(), u.y() + v.y(), u.z() + v.z()};
}

inline vec3 operator*(const vec3& u, const vec3& v) {
  return vec3{u.x() * v.x(), u.y() * v.y(), u.z() * v.z()};
}

inline vec3 operator*(const vec3& u, const double t) {
  return vec3{u.x() * t, u.y() * t, u.z() * t};
}

inline vec3 operator*(const double t, const vec3& u) { return u * t; }

inline vec3 operator/(const vec3& u, const double t) {
  return vec3{u.x() / t, u.y() / t, u.z() / t};
}

inline double dot(const vec3& u, const vec3& v) {
  return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

inline vec3 cross(const vec3& u, const vec3& v) {
  return vec3{u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(),
              u.x() * v.y() - u.y() * v.x()};
}

inline vec3 unit_vector(const vec3& u) { return u / u.length(); }

// vec3 operator+(const vec3& v, int a) { return vec3{v.x() + a, 0, 0}; }
// vec3 operator+(int a, const vec3& v) { return vec3{v.x() + a, 0, 0}; }

#endif

// vec3 a;
// int main() {
//   a + 1;
//   1 + a;
// }
