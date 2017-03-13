#!/usr/bin/python
import unittest
import sys
sys.path.append('../../lib')
from  pyngl import Mat3

class TestMat3(unittest.TestCase) :
  
  def testdefaultCtor(self):
    test=Mat3()
    result=Mat3(1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0)
    self.assertTrue(test==result)

  def testNull(self):
    test=Mat3(2.0)
    test.null()
    result=Mat3(0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0)
    self.assertTrue(test==result)

  def testIdentity(self) :
    test=Mat3(2.0)
    test.identity()
    result=Mat3(1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0)
    self.assertTrue(test==result)
    
  def testFloatCtor(self) :
    test=Mat3(2.0)
    result=Mat3(2.0,0.0,0.0,0.0,2.0,0.0,0.0,0.0,2.0)
    self.assertTrue(test==result)

  def testCopyCtor(self) :
    a=Mat3(2.0)
    test=Mat3(a)
    result=Mat3(2.0,0.0,0.0,0.0,2.0,0.0,0.0,0.0,2.0)
    self.assertTrue(test==result)

  def testAssignOperator(self) :
    a=Mat3(2.0)
    test=a
    result=Mat3(2.0,0.0,0.0,0.0,2.0,0.0,0.0,0.0,2.0)
    self.assertTrue(test==result)


  def testSetAt(self ) :
    test=Mat3()
    value=0;
    for y in range(0,3) :
      for x in range(0,3) :
        test.setAtXY(x,y,value)
        value=value+1

    result=Mat3(0,3,6,1,4,7,2,5,8)    
    self.assertTrue(test==result)

  def testScale(self ) :
    test=Mat3()
    test.scale(1.0,2.0,3.0);
    result=Mat3(1,0,0,0,2,0,0,0,3);
    self.assertTrue(test==result)

  def testRotateX(self) :
    test=Mat3()
    test.rotateX(45.0);
    result=Mat3(1,0,0,0,0.707107,0.707107,0,-0.707107,0.707107);
    self.assertTrue(test==result)

  def testRotateY(self) :
    test=Mat3()
    test.rotateY(25.0);
    result=Mat3(0.906308,0,-0.422618,0,1,0,0.422618,0,0.906308);
    self.assertTrue(test==result)

  def testRotateZ(self) :
    test=Mat3()
    test.rotateZ(-36.0);
    result=Mat3(0.809017,-0.587785,0,0.587785,0.809017,0,0,0,1);
    self.assertTrue(test==result)

  def testMat3xMat3(self) :
    t1=Mat3()
    t2=Mat3()
    t1.rotateX(45.0)
    t2.rotateY(35.0)
    test=t1*t2
    result=Mat3(0.819152,0,-0.573577,0.40558,0.707107,0.579228,0.40558,-0.707107,0.579228)
    self.assertTrue(test==result)

  def testMat3xequals(self) :
    test=Mat3()
    t2=Mat3()
    test.rotateX(45.0)
    t2.rotateY(35.0)
    test*=t2
    result=Mat3(0.819152,0.40558,-0.40558,0,0.707107,0.707107,0.573577,-0.579228,0.579228)
    self.assertTrue(test==result)
    

  def testMat3pluEqual(self) :
    t1=Mat3()
    t2=Mat3()
    t1.rotateX(45.0);
    t2.rotateY(35.0);
    t1+=t2;
    result=Mat3(1.81915,0,-0.573577,0,1.70711,0.707107,0.573577,-0.707107,1.52626);
    self.assertTrue(t1==result)


  def testMat3plus(self) :
    t1=Mat3()
    t2=Mat3()
    t1.rotateX(45.0)
    t2.rotateY(35.0)
    res=t1+t2
    result=Mat3(1.81915,0,-0.573577,0,1.70711,0.707107,0.573577,-0.707107,1.52626)
    self.assertTrue(res==result)

  def testMat3xReal(self) :
    test=Mat3()
    value=0
    for y in range(0,3) :
      for x in range(0,3) :
        test.setAtXY(x,y,value)
        value=value+1
    print "\n"
    print test
    test=test*4.2
    result=Mat3(0,16.8,33.6,50.4,21,37.8,54.6,25.2,42)
    print test
    print result
    self.assertTrue(test==result)
    


if __name__ == '__main__':
  unittest.main()