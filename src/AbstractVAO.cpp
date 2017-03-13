#include <pybind11/pybind11.h>

#include "AbstractVAO.h"
#include <iostream>
namespace ngl
{
  AbstractVAO::AbstractVAO(GLenum _mode)
  {
    // first we create a vertex array Object
    glGenVertexArrays(1, &m_id);
    m_mode=_mode;
  }

  GLenum AbstractVAO::getMode() const
  {
    return m_mode;
  }

  void AbstractVAO::setMode(const GLenum &_mode)
  {
    m_mode = _mode;
  }

  //----------------------------------------------------------------------------------------------------------------------
  void AbstractVAO::bind()
  {
    glBindVertexArray(m_id);
    m_bound=true;
  }
  //----------------------------------------------------------------------------------------------------------------------
  void AbstractVAO::unbind()
  {
    glBindVertexArray(0);
    m_bound=false;
  }


  void AbstractVAO::setVertexAttributePointer(GLuint _id, GLint _size, GLenum _type, GLsizei _stride, unsigned int _dataOffset, bool _normalise )
  {
    if(m_bound !=true)
    {
      std::cerr<<"Warning trying to set attribute on Unbound VOA\n";
    }
    // set and enable the generic vertex attribute
    glVertexAttribPointer(_id,_size,_type,_normalise,_stride,static_cast<Real *>(NULL)  + _dataOffset);//   ((Real *)NULL + (_dataOffset)));
    glEnableVertexAttribArray(_id);
  }


  namespace py = pybind11;

  void pyInitAbstractVAO(py::module & m)
  {
    py::class_<AbstractVAO>(m, "AbstractVAO")
      .def("bind", &AbstractVAO::bind)
      .def("unbind", &AbstractVAO::unbind)
      .def("setData", &AbstractVAO::setData)
      .def("setVertexAttributePointer",&AbstractVAO::setVertexAttributePointer)
      .def("setNumIndices",&AbstractVAO::setNumIndices)
      .def("numIndices", &AbstractVAO::numIndices)
      .def("getBufferID",&AbstractVAO::getBufferID)
      .def("getMode", &AbstractVAO::getMode)
      .def("setMode",&AbstractVAO::setMode)
        ;

    py::class_<AbstractVAO::VertexData>(m, "VertexData")
        .def(py::init<size_t,const GLfloat &, GLenum >())
        ;


  }

}

