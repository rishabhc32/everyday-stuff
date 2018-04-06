## Inheritance in C++
[link](https://www.geeksforgeeks.org/inheritance-in-c/)

The capability of a class to derive properties and characteristics from another class is called Inheritance

**Sub Class/Derived Class**: The class that inherits properties from another class is called Sub class or Derived Class.
**Super Class/Base Class**:The class whose properties are inherited by sub class is called Base Class or Super class. 

**Syntax:**
```c++
class class_name: access_specifier base_class_name {
    //body
};
```
**Modes of Inheritance**
![](http://cdncontribute.geeksforgeeks.org/wp-content/uploads/Untitled-presentation-4.png)

**Example**
```C++
class base 
{
	public:
		int x;
	protected:
		int y;
	private:
		int z;
};

class publicDerived: public base
{
	// x is public
	// y is protected
	// z is not accessible from publicDerived
};

class protectedDerived: protected base
{
	// x is protected
	// y is protected
	// z is not accessible from protectedDerived
};

class privateDerived: private base
{
	// x is private
	// y is private
	// z is not accessible from privateDerived
}
```
In the above example, we observe the following things:
* `base` has three member variables: x, y and z which are public, protected and private member respectively.
* `publicDerived` inherits variables x and y as public and protected. z is not inherited as it is a private member variable of base.
* `protectedDerived` inherits variables x and y. Both variables become protected. z is not inherited
If we derive a class `derivedFromProtectedDerived` from `protectedDerived`, variables x and y are also inherited to the derived class.
* `privateDerived` inherits variables x and y. Both variables become private. z is not inherited
If we derive a class `derivedFromPrivateDerived` from `privateDerived`, variables x and y are not inherited because they are private variables of privateDerived.

**Types of Inheritance**
* **Single:** Normal waali, [gfg](https://www.geeksforgeeks.org/inheritance-in-c/)
* **Multiple:** [link](https://www.geeksforgeeks.org/multiple-inheritance-in-c/)
    * Class inherits from multiple classes
    * Constructors are called in same order, in which they are inherited, exampul in link
    * The destructors are called in reverse order of constructors. 
    * **Diamond Problem:** Occurs when two base class of class have a common base class, check link
        * Constructor and destructor called two times
        * Solution is virtual class
* **Multilevel:** [gfg](https://www.geeksforgeeks.org/inheritance-in-c/)
    * Derived class is created from derived class, A->B->C
* **Hierarchical :** [gfg](https://www.geeksforgeeks.org/inheritance-in-c/)
    * More than one derived class from base class, ek baap ke ek se zyada bacche.
* **Hybrid:** [gfg](https://www.geeksforgeeks.org/inheritance-in-c/)
    * Combining more than one inheritance, eg: Combining Hierarchical and multiple inheritance.
> Questions from notes or search by yourself

### Virtual base class
[Link](https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/cplr135.htm)

> As seen in multiple inheritance

Suppose you have two derived classes B and C that have a common base class A, and you also have another class D that inherits from B and C. You can declare the base class A as virtual to ensure that B and C share the same subobject of A.
A virtual base class ensures that only one copy of that class is inherited.


