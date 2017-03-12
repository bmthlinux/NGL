#!/usr/bin/python
import unittest
import sys
sys.path.append('../../lib')
from  pyngl import Vec4

class TestVec4(unittest.TestCase) :
  
  def testdefaultCtor(self):
    test=Vec4()
    result=Vec4(0.0,0.0,0.0,1.0)
    self.assertTrue(test==result)

  def test_floatCtorAndSet(self):
    test=Vec4(1.0,2.0,3.0,1.0);
    result=Vec4()
    result.set(1.0,2.0,3.0,1.0);
    self.assertTrue(test==result)

  def test_Subscript(self):
    test=Vec4(1.0,2.0,3.0,4.0);
    self.assertEqual(test[0],1.0)
    self.assertEqual(test[1],2.0)
    self.assertEqual(test[2],3.0)
    self.assertEqual(test[3],4.0)

  def test_SetVec4(self ) :
    test=Vec4(1,2,3,4)
    result=Vec4(test)
    self.assertTrue(test==result)

  
  def test_dot(self) :
    test=Vec4(1.0,2.0,3.0,1)
    rhs=Vec4(4.0,5.0,6.0,1)
    result=test.dot(rhs)
    self.assertTrue(result==32)
 
  def test_null(self) :
    test=Vec4(1,2,3,4)
    test.null()
    result=Vec4(0,0,0,0)
    self.assertTrue(test==result)

  def test_normalize(self) :
    test=Vec4(22.3,0.5,10.0,1.0)
    test.normalize()
    result=Vec4(0.912266,0.0204544,0.409088,1.0)
    self.assertTrue(test==result)

  def test_inner(self) :
    a=Vec4(1.0,2.0,3.0,1)
    b=Vec4(3.0,4.0,5.0,1)
    self.assertAlmostEqual(a.inner(b),26.0)
    
  """ need to write mat3 class before this test works
  3     4     5
     6     8    10
     9    12    15
  def test_outer(self) :
    a=Vec4(1.0,2.0,3.0)
    b=Vec4(3.0,4.0,5.0)
    self.assertEqual(a.outer(b),26.0)
    
  """

  def test_length(self) :
    a=Vec4(22,1,32,1)
    self.assertAlmostEqual(a.length(),38.845, delta=0.001)

  def test_lengthSquared(self) :
    a=Vec4(22,1,32,1)
    self.assertAlmostEqual(a.lengthSquared(),1509.0)


  def testCross2Param(self) :
    a=Vec4.up()
    b=Vec4.left()
    c=Vec4()
    c.cross(a,b)
    self.assertTrue(c==Vec4.inV())


  def testCross1Param(self) :
    a=Vec4.up()
    b=Vec4.left()
    c=a.cross(b)
    self.assertTrue(c==Vec4.inV())

if __name__ == '__main__':
    unittest.main()