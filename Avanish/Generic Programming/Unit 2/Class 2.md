
Derived class being public, implies it can access base class (private or public)
Templates screw everything up, need to fully resolve the scope.
Parent can be accessed, for grandparent, need to explicitly mention the grandfather class.
Child class can not have less template parameters than the parent.

#### Specialized Base class
Must fully scope it for access 

#### Can a templatized derived class inherit from a non-template base class?
Yes. (No reason for there to be an issue.)

A template can be inherited **as long as they are a class**.
