#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

namespace ngl
{
namespace py = pybind11;
// each cpp file will have an init function to do the binding
// see http://pybind11.readthedocs.io/en/master/faq.html#how-can-i-reduce-the-build-time
extern void pyInitVec4(py::module & m);
extern void pyInitVec3(py::module & m);
extern void pyInitAABB(py::module & m);
extern void pyInitAbstractMesh(py::module & m);
extern void pyInitAbstractVAO(py::module & m);
extern void pyInitBBox(py::module & m);
extern void pyInitBezierCurve(py::module & m);
extern void pyInitCamera(py::module & m);
extern void pyInitColour(py::module & m);
extern void pyInitImage(py::module & m);
extern void pyInitLight(py::module & m);

PYBIND11_PLUGIN(pyngl)
{
    py::module m("pyngl", "pyngl module ");


    pyInitVec4(m);
    pyInitVec3(m);
    pyInitAABB(m);
    pyInitAbstractMesh(m);
    pyInitAbstractVAO(m);
    pyInitBBox(m);
    pyInitBezierCurve(m);
    pyInitCamera(m);
    pyInitColour(m);
    pyInitImage(m);
    pyInitLight(m);
    return m.ptr();
}

}
