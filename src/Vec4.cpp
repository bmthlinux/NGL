/*
  Copyright (C) 2009 Jon Macey

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "Vec4.h"
#include "Vec3.h"
#include "Vec2.h"

#include "NGLassert.h"
#include "Mat4.h"
#include <cmath>
#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

//----------------------------------------------------------------------------------------------------------------------
/// @file Vec3.cpp
/// @brief implementation files for Vec3 class
//----------------------------------------------------------------------------------------------------------------------
namespace ngl
{



//----------------------------------------------------------------------------------------------------------------------
Real Vec4::dot(const Vec4& _v )const noexcept
{
	return m_x * _v.m_x + m_y * _v.m_y + m_z * _v.m_z;
}

//----------------------------------------------------------------------------------------------------------------------
void Vec4::set( Real _x, Real _y, Real _z, Real _w) noexcept
{
	m_x=_x;
	m_y=_y;
	m_z=_z;
	m_w=_w;
}

//----------------------------------------------------------------------------------------------------------------------
void Vec4::set( const Vec4& _v) noexcept
{
   m_x=_v.m_x;
   m_y=_v.m_y;
   m_z=_v.m_z;
   m_w=_v.m_w;
}
//----------------------------------------------------------------------------------------------------------------------
void Vec4::set( const Vec3 &_v ) noexcept
{
  m_x=_v.m_x;
  m_y=_v.m_y;
  m_z=_v.m_z;
  m_w=1.0f;
}

//----------------------------------------------------------------------------------------------------------------------
void Vec4::null() noexcept
{
	m_x=0.0f;
	m_y=0.0f;
	m_z=0.0f;
	m_w=1.0f;
}

//----------------------------------------------------------------------------------------------------------------------
Real& Vec4::operator[](const size_t  &_i ) noexcept
{
	NGL_ASSERT(_i >=0 && _i<=3);
	return (&m_x)[_i];
}

//----------------------------------------------------------------------------------------------------------------------
Real Vec4::length() const noexcept
{
  return sqrtf((m_x*m_x)+(m_y*m_y)+(m_z*m_z));
}


//----------------------------------------------------------------------------------------------------------------------
Vec4 &Vec4::operator-() noexcept
{
  m_x=-m_x;
  m_y=-m_y;
  m_z=-m_z;
  return *this;
}

//----------------------------------------------------------------------------------------------------------------------
Vec4 &Vec4::normalize() noexcept
{
  Real len=sqrtf(m_x*m_x+m_y*m_y+m_z*m_z);
	NGL_ASSERT(len!=0.0f);
	m_x/=len;
	m_y/=len;
	m_z/=len;
	return *this;
}

//----------------------------------------------------------------------------------------------------------------------
void Vec4::cross( const Vec4& _v1, const Vec4& _v2) noexcept
{
	m_x=_v1.m_y*_v2.m_z-_v1.m_z*_v2.m_y;
	m_y=_v1.m_z*_v2.m_x-_v1.m_x*_v2.m_z;
	m_z=_v1.m_x*_v2.m_y-_v1.m_y*_v2.m_x;
}

//----------------------------------------------------------------------------------------------------------------------
Vec4 Vec4::cross(const Vec4& _v )const noexcept
{
	return Vec4(
								m_y*_v.m_z - m_z*_v.m_y,
								m_z*_v.m_x - m_x*_v.m_z,
								m_x*_v.m_y - m_y*_v.m_x,
								0.0f
							 );

}

//----------------------------------------------------------------------------------------------------------------------
void Vec4::operator+=( const Vec4& _v) noexcept
{
	m_x+=_v.m_x;
	m_y+=_v.m_y;
	m_z+=_v.m_z;
}

//----------------------------------------------------------------------------------------------------------------------
void Vec4::operator/=(Real _v) noexcept
{
	NGL_ASSERT(_v !=0.0f);
	m_x/=_v;
	m_y/=_v;
	m_z/=_v;
}
//----------------------------------------------------------------------------------------------------------------------
void Vec4::operator*=(Real _v) noexcept
{
	m_x*=_v;
	m_y*=_v;
	m_z*=_v;
}
//----------------------------------------------------------------------------------------------------------------------
void Vec4::operator-=( const Vec4& _v) noexcept
{
	m_x-=_v.m_x;
	m_y-=_v.m_y;
	m_z-=_v.m_z;
}

//----------------------------------------------------------------------------------------------------------------------
Vec4 Vec4::operator/(Real _v )const noexcept
{
	return Vec4(m_x/_v,m_y/_v,m_z/_v,m_w);
}

//----------------------------------------------------------------------------------------------------------------------
Vec4 Vec4::operator+(const Vec4& _v )const noexcept
{
	return Vec4(
								m_x+_v.m_x,
								m_y+_v.m_y,
								m_z+_v.m_z,
								m_w
								);
}

//----------------------------------------------------------------------------------------------------------------------
Vec4 Vec4::operator-(const Vec4& _v )const noexcept
{
	return Vec4(
								m_x-_v.m_x,
								m_y-_v.m_y,
								m_z-_v.m_z,
								m_w
							 );
}

//----------------------------------------------------------------------------------------------------------------------
bool Vec4::operator==(const Vec4& _v   )const noexcept
{
	return (
					FCompare(_v.m_x,m_x)  &&
					FCompare(_v.m_y,m_y)  &&
					FCompare(_v.m_z,m_z)
				 );
}
//----------------------------------------------------------------------------------------------------------------------
bool Vec4::operator!=( const Vec4& _v  )const noexcept
{
	return (
					!FCompare(_v.m_x,m_x) ||
					!FCompare(_v.m_y,m_y) ||
					!FCompare(_v.m_z,m_z)
				 );
}
//----------------------------------------------------------------------------------------------------------------------
Vec4 Vec4::operator*( const Vec4& _v )const noexcept
{
	return Vec4(
								m_x*_v.m_x,
								m_y*_v.m_y,
								m_z*_v.m_z,
								m_w
							 );
}

//----------------------------------------------------------------------------------------------------------------------
Vec4 Vec4::operator/(const Vec4& _v )const noexcept
{
	return Vec4(
								m_x/_v.m_x,
								m_y/_v.m_y,
								m_z/_v.m_z,
								m_w
								);
}

//----------------------------------------------------------------------------------------------------------------------
Vec4 Vec4::operator *( Real _i )const noexcept
{
	return Vec4(
								m_x*_i,
								m_y*_i,
								m_z*_i,
								m_w
							 );
}

//----------------------------------------------------------------------------------------------------------------------
Real Vec4::angleBetween( const Vec4& _v  )const noexcept
{
 // uses cos(t) = |a| . |b|
// create tmp Vec3s so we don't have to
// normalize existing ones
  Vec4 v1 = _v;
  Vec4 v2 = *this;
  v1.normalize();
  v2.normalize();
  return acosf(v1.dot(v2));
}

//----------------------------------------------------------------------------------------------------------------------
Real Vec4::inner(const Vec4& _v  )const noexcept
{
	return (
					(m_x * _v.m_x) +
					(m_y * _v.m_y) +
					(m_z * _v.m_z)
				 );
}

//----------------------------------------------------------------------------------------------------------------------
Vec4 Vec4::outer(const Vec4& _v  )  const noexcept
{
	Real x = (m_y * _v.m_z) - (m_z * _v.m_y);
	Real y = (m_z * _v.m_x) - (m_x * _v.m_z);
	Real z = (m_x * _v.m_y) - (m_y * _v.m_x);

	return Vec4(x,y,z,m_w);
}


//----------------------------------------------------------------------------------------------------------------------
Vec4 & Vec4::operator=( const Vec4& _v) noexcept
{
	m_x = _v.m_x;
	m_y = _v.m_y;
	m_z = _v.m_z;
	m_w = _v.m_w;
	return *this;
}

//----------------------------------------------------------------------------------------------------------------------
Vec4 & Vec4::operator=( const Vec3& _v) noexcept
{
  m_x = _v.m_x;
  m_y = _v.m_y;
  m_z = _v.m_z;
  m_w = 0.0f;
  return *this;
}

//----------------------------------------------------------------------------------------------------------------------
Vec4 & Vec4::operator=( Real _v) noexcept
{
  m_x = _v;
  m_y = _v;
  m_z = _v;
  m_w = 0.0f;
  return *this;
}


//----------------------------------------------------------------------------------------------------------------------
Real Vec4::lengthSquared() const noexcept
{
  return m_x * m_x+m_y * m_y+ m_z*m_z;
}

//----------------------------------------------------------------------------------------------------------------------
Vec4 Vec4::operator*(const Mat4 &_m ) const noexcept
{

	 Vec4 v(
						m_x*_m.m_00 + m_y*_m.m_10 + m_z*_m.m_20+ m_w*_m.m_30,
						m_x*_m.m_01 + m_y*_m.m_11 + m_z*_m.m_21+ m_w*_m.m_31,
						m_x*_m.m_02 + m_y*_m.m_12 + m_z*_m.m_22+ m_w*_m.m_32,
						m_x*_m.m_03 + m_y*_m.m_13 + m_z*_m.m_23+ m_w*_m.m_33
				 );

   return v;
 }


namespace py = pybind11;

void pyInitVec4(py::module & m)
{

    py::class_<Vec4>(m, "Vec4")
        .def(py::init<>())
        .def(py::init<Real,Real,Real,Real>(),py::arg("_x") = 0.0f,py::arg("_y") = 0.0f,py::arg("_z") = 0.0f,py::arg("_w") = 1.0f)
        .def(py::init<Vec4 &>())
        .def(py::init<Vec3 &,Real >(),py::arg("_v"),py::arg("_w") = 1.0f)
        .def("set", (void (Vec4::*)(Real,Real,Real,Real)) &Vec4::set)
        .def("set", (void (Vec4::*)(const Vec3 &)) &Vec4::set)
        .def("set", (void (Vec4::*)(const Vec4 &)) &Vec4::set)
        .def("dot", &Vec4::dot)
        .def("null", &Vec4::null)
        .def("__getitem__",(Real& (Vec4::*)(const size_t &)) &Vec4::operator[])
        .def("normalize", &Vec4::normalize)
        .def("inner", &Vec4::inner)
        .def("outer", &Vec4::outer)
        .def("length", &Vec4::length)
        .def("lengthSquared", &Vec4::lengthSquared)
        .def("cross",(void (Vec4::*)(const Vec4&, const Vec4&)) &Vec4::cross)
        .def("cross",( Vec4 (Vec4::*)(const Vec4&) const) &Vec4::cross)
        .def_static("up", &Vec4::up)
        .def_static("down", &Vec4::down)
        .def_static("left", &Vec4::left)
        .def_static("right", &Vec4::right)
        .def_static("inV", &Vec4::in) // note in is a reserved word so use inV
        .def_static("out", &Vec4::out)
        .def_static("zero", &Vec4::zero)

        .def(py::self == py::self)
        .def(py::self != py::self)
        .def(py::self += py::self)
        .def(py::self -= py::self)
        .def(py::self * ngl::Real())
        .def(ngl::Real() * py::self)
        .def(py::self + py::self)
        .def(py::self - py::self)
        .def(py::self * py::self)
        .def(py::self / ngl::Real())
        .def(py::self / py::self)
        .def(py::self /= ngl::Real())
        .def(py::self *= ngl::Real())
        .def(py::self * ngl::Mat4())
        .def("__neg__",(Vec4 & (Vec4::*)()) &Vec4::operator-)
        .def("__repr__",
                [](const Vec4 &v) {
                    return "["+std::to_string(v.m_x)+","+
                        std::to_string(v.m_y)+","+
                        std::to_string(v.m_z)+","+
                        std::to_string(v.m_w)
                        +"]";})
        ;

}


} // end namspace ngl



