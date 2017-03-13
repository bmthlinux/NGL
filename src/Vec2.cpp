/*
  Copyright (C) 2011 Jon Macey

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
#include <pybind11/pybind11.h>
#include "Vec2.h"
#include "Vec4.h"
#include "NGLassert.h"
#include <cmath>
//----------------------------------------------------------------------------------------------------------------------
/// @file Vec2.cpp
/// @brief implementation files for Vec2 class
//----------------------------------------------------------------------------------------------------------------------
namespace ngl
{

//----------------------------------------------------------------------------------------------------------------------
void Vec2::set(Real _x, Real _y) noexcept
{
	m_x=_x;
	m_y=_y;
}

//----------------------------------------------------------------------------------------------------------------------
void Vec2::set(const Vec2& _v  ) noexcept
{
   m_x=_v.m_x;
   m_y=_v.m_y;
}
//----------------------------------------------------------------------------------------------------------------------
void Vec2::set(const Vec2* _v	) noexcept
{
	m_x=_v->m_x;
	m_y=_v->m_y;
}

//----------------------------------------------------------------------------------------------------------------------
void Vec2::null() noexcept
{
	m_x=0.0f;
	m_y=0.0f;
}

//----------------------------------------------------------------------------------------------------------------------
Real& Vec2::operator[]( int _i) noexcept
{
	NGL_ASSERT(_i >=0 || _i<=2);
	return (&m_x)[_i];
}



//----------------------------------------------------------------------------------------------------------------------
Vec2 Vec2::operator-() const noexcept
{
	return Vec2(-m_x,-m_y);
}


//----------------------------------------------------------------------------------------------------------------------
void Vec2::operator+=(const Vec2& _v  ) noexcept
{
	m_x+=_v.m_x;
	m_y+=_v.m_y;
}

//----------------------------------------------------------------------------------------------------------------------
void Vec2::operator/=(Real _v  ) noexcept
{
  NGL_ASSERT(_v !=0.0);
	m_x/=_v;
	m_y/=_v;
}
//----------------------------------------------------------------------------------------------------------------------
void Vec2::operator*=(Real _v) noexcept
{
	m_x*=_v;
	m_y*=_v;
}
//----------------------------------------------------------------------------------------------------------------------
void Vec2::operator-=(const Vec2& _v ) noexcept
{
	m_x-=_v.m_x;
	m_y-=_v.m_y;
}

//----------------------------------------------------------------------------------------------------------------------
Vec2 Vec2::operator/( Real _v )const noexcept
{
	return Vec2(m_x/_v,m_y/_v);
}

//----------------------------------------------------------------------------------------------------------------------
Vec2 Vec2::operator+(const Vec2& _v )const noexcept
{
	return Vec2(m_x+_v.m_x,m_y+_v.m_y);
}

//----------------------------------------------------------------------------------------------------------------------
Vec2 Vec2::operator-( const Vec2& _v  )const noexcept
{
	return Vec2(m_x-_v.m_x,	m_y-_v.m_y );
}

//----------------------------------------------------------------------------------------------------------------------
bool Vec2::operator==(const Vec2& _v )const noexcept
{
	return (
					FCompare(_v.m_x,m_x)  &&
					FCompare(_v.m_y,m_y)
				 );
}
//----------------------------------------------------------------------------------------------------------------------
bool Vec2::operator!=(const Vec2& _v  )const noexcept
{
	return (
					!FCompare(_v.m_x,m_x) ||
					!FCompare(_v.m_y,m_y)
				 );
}
//----------------------------------------------------------------------------------------------------------------------
Vec2 Vec2::operator*(const Vec2& _v  )const noexcept
{
	return Vec2(
								m_x*_v.m_x,
								m_y*_v.m_y
							);
}

//----------------------------------------------------------------------------------------------------------------------
Vec2 Vec2::operator/( const Vec2& _v )const noexcept
{
	return Vec2(m_x/_v.m_x,	m_y/_v.m_y	);
}

//----------------------------------------------------------------------------------------------------------------------
Vec2 Vec2::operator *(Real _i )const noexcept
{
	return Vec2(m_x*_i,m_y*_i );
}



//----------------------------------------------------------------------------------------------------------------------
Vec2 & Vec2::operator=(const Vec2& _v) noexcept
{
	m_x = _v.m_x;
	m_y = _v.m_y;
	return *this;
}

//----------------------------------------------------------------------------------------------------------------------
void Vec2::normalize() noexcept
{
  Real len=sqrtf(m_x*m_x+m_y*m_y);
  NGL_ASSERT(len!=0.0);
  m_x/=len;
  m_y/=len;
}






Real Vec2::dot(const Vec2& _v )const noexcept
{
  return m_x * _v.m_x + m_y * _v.m_y;
}


//----------------------------------------------------------------------------------------------------------------------
Real Vec2::lengthSquared() const noexcept
{
  return (m_x*m_x)+(m_y*m_y);
}






//----------------------------------------------------------------------------------------------------------------------
Real Vec2::length() const noexcept
{
  return sqrtf((m_x*m_x)+(m_y*m_y));
}

namespace py = pybind11;

void pyInitVec2(py::module & m)
{
  py::class_<Vec2>(m, "Vec2")
      .def(py::init<>())
      .def(py::init<const Vec2 &>())
      .def(py::init<Real,Real>(),py::arg("_x")=0.0f,py::arg("_y")=1.0f)
   //   .def(py::init<Real>())
//      .def("set",(void(Vec2::*)(const Vec2&)) &Vec2::set)
//      .def("set",(void(Vec2::*)(const Vec3&)) &Vec2::set)
//      .def("set",(void(Vec2::*)(const Vec4&)) &Vec2::set)
//      .def("set",(void(Vec2::*)(Real,Real)) &Vec2::set)
     ;
      #warning finish this and tidy the class anyway
}

} // end namspace ngl



