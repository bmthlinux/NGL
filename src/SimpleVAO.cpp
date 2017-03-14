#include <pybind11/pybind11.h>
#include "SimpleVAO.h"
#include <iostream>
namespace ngl
{
  SimpleVAO::~SimpleVAO()
  {
    removeVAO();
  }

  void SimpleVAO::draw() const
  {
    if(m_allocated == false)
    {
      std::cerr<<"Warning trying to draw an unallocated VOA\n";
    }
    if(m_bound == false)
    {
      std::cerr<<"Warning trying to draw an unbound VOA\n";
    }
    glDrawArrays(m_mode, 0, static_cast<GLsizei>(m_indicesCount));
  }

  void SimpleVAO::removeVAO()
  {
    if(m_bound == true)
    {
      unbind();
    }
    if( m_allocated ==true)
    {
        glDeleteBuffers(1,&m_buffer);
    }
    glDeleteVertexArrays(1,&m_id);
    m_allocated=false;
    }

  void SimpleVAO::setData(const VertexData &_data)
  {
    if(m_bound == false)
    {
      std::cerr<<"trying to set VOA data when unbound\n";
    }
    if( m_allocated ==true)
    {
        glDeleteBuffers(1,&m_buffer);
    }

    glGenBuffers(1, &m_buffer);
    // now we will bind an array buffer to the first one and load the data for the verts
    glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
    glBufferData(GL_ARRAY_BUFFER,static_cast<GLsizeiptr>( _data.m_size), &_data.m_data, _data.m_mode);
    m_allocated=true;

  }

  namespace py = pybind11;
  void pyInitSimpleVAO(py::module & m)
  {
    py::class_<SimpleVAO,AbstractVAO>(m, "SimpleVAO")
        .def_static("create",&SimpleVAO::create)
        .def("draw", &SimpleVAO::draw)
        .def("bind", &SimpleVAO::bind)
        .def("unbind", &SimpleVAO::unbind)
        .def("removeVAO", &SimpleVAO::removeVAO)
        .def("setData", &SimpleVAO::setData)
        .def("getBufferID", &SimpleVAO::getBufferID)
        .def("setVertexAttributePointer",(void(SimpleVAO::*)(GLuint , GLint , GLenum , GLsizei , unsigned int , bool)) &SimpleVAO::setVertexAttributePointer)

        ;

  }


}// end namespace
