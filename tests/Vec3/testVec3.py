#!/usr/bin/python
import unittest
import sys
sys.path.append('../../lib')
from  pyngl import Vec3

class TestVec3(unittest.TestCase) :
  
  def testdefaultCtor(self):
    test=Vec3()
    result=Vec3(0.0,0.0,0.0)
    self.assertTrue(test==result)

  def test_floatCtorAndSet(self):
    test=Vec3(1.0,2.0,3.0);
    result=Vec3()
    result.set(1.0,2.0,3.0);
    self.assertTrue(test==result)

  def test_Subscript(self):
    test=Vec3(1.0,2.0,3.0);
    self.assertEqual(test[0],1.0)
    self.assertEqual(test[1],2.0)
    self.assertEqual(test[2],3.0)

  def test_SetVec3(self ) :
    test=Vec3(1,2,3)
    result=Vec3(test)
    self.assertTrue(test==result)

  
  def test_dot(self) :
    test=Vec3(1.0,2.0,3.0)
    rhs=Vec3(4.0,5.0,6.0)
    result=test.dot(rhs)
    self.assertTrue(result==32)
 
  def test_null(self) :
    test=Vec3(1,2,3)
    test.null()
    result=Vec3(0,0,0)
    self.assertTrue(test==result)

  def test_normalize(self) :
    test=Vec3(22.3,0.5,10.0)
    test.normalize()
    result=Vec3(0.912266,0.0204544,0.409088)

  def test_inner(self) :
    a=Vec3(1.0,2.0,3.0)
    b=Vec3(3.0,4.0,5.0)
    self.assertAlmostEqual(a.inner(b),26.0)
    
  """ need to write mat3 class before this test works
  3     4     5
     6     8    10
     9    12    15
  def test_outer(self) :
    a=Vec3(1.0,2.0,3.0)
    b=Vec3(3.0,4.0,5.0)
    self.assertEqual(a.outer(b),26.0)
    
  """

  def test_length(self) :
    a=Vec3(22,1,32)
    self.assertAlmostEqual(a.length(),38.845, delta=0.001)

  def test_lengthSquared(self) :
    a=Vec3(22,1,32)
    self.assertAlmostEqual(a.lengthSquared(),1509.0)


  def testCross2Param(self) :
    a=Vec3.up()
    b=Vec3.left()
    c=Vec3()
    c.cross(a,b)
    self.assertTrue(c==Vec3.inV())


  def testCross1Param(self) :
    a=Vec3.up()
    b=Vec3.left()
    c=a.cross(b)
    self.assertTrue(c==Vec3.inV())

if __name__ == '__main__':
    unittest.main()