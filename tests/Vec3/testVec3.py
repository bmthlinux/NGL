#!/usr/bin/python
import unittest
import sys
sys.path.append('../../lib')
from  pyngl import Vec3

class TestVec3(unittest.TestCase) :
  
  def test_defaultCtor(self):
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
    


  



if __name__ == '__main__':
    unittest.main()