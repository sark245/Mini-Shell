## OOPS Concepts and Design Problems

  ### 1. Multilevel Inheritence and Virtual Base Class
A derived class with two base classes and these two base classes have one common base class is called multipath inheritance. An ambiguity  
can arrise in this type of inheritance. Virtual base classes are used in virtual inheritance in a way of preventing multiple “instances” of a given  
class appearing in an inheritance hierarchy when using multiple inheritances.


There are 2 ways to avoid this ambiguity:  
  a. Use scope resolution operator  
  b. Use virtual base class  
  
  ### 2. Abstract Class and Pure Virtual Functions
    A class is abstract if it has at least one pure virtual function.
    
    We can have pointers and references of abstract class type.
    
    If we do not override the pure virtual function in derived class,   then derived class also becomes abstract class.
    
    An abstract class can have constructors.


In Java, a class can be made abstract by using abstract keyword. Similarly a function can be made pure virtual or abstract by using abstract keyword.  
An interface does not have implementation of any of its methods, it can be considered as a collection of method declarations.   In C++, an interface can be simulated by making all methods as pure virtual. In Java, there is a separate keyword for interface.
