/* 
flext tutorial - simple 1 

Copyright (c) 2002 Thomas Grill (xovo@gmx.net)
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "license.txt," in this distribution.  

-------------------------------------------------------------------------

This is an example of a simple object doing a float inversion
*/

// include flext header
#include <flext.h>

// check for appropriate flext version
#if !defined(FLEXT_VERSION) || (FLEXT_VERSION < 300)
#error You need at least flext version 0.3.0
#endif


// define the class that stands for a pd/Max object
// Attention: the class name must be the same as the object name!! (without an eventual ~)

class simple1:
	// inherit from basic flext class
	public flext_base
{
	// obligatory flext header (class name,base class name)
	FLEXT_HEADER(simple1,flext_base)
 
public:
	// constructor
	simple1();

protected:
	void m_float(float f);  // method 

private:
	FLEXT_CALLBACK_1(m_float,float);  // callback for method "m_float" (with one float argument)

	// FLEXT_CALLBACK_F(...) ... callback with float argument 
	// is a shortcut for:
	// FLEXT_CALLBACK_1(...,float) ... just the same
};

// instantiate the class
FLEXT_NEW("simple1",simple1)


simple1::simple1()
{ 
	// define inlets
	AddInAnything();  // first inlet must by of type anything (or signal)
	
	// define outlets
	AddOutFloat();  // one float outlet (has index 0)
	
	 // set up inlets and outlets - obligatory! (do only once!!!)
	SetupInOut(); 

	// register methods
	FLEXT_ADDMETHOD(0,m_float);  // register method (for floats) "m_float" for inlet 0
} 

void simple1::m_float(float f)
{
	float res;
	if(f == 0) {
		// special case 0
		post("%s - zero can't be inverted!",thisName());
		res = 0;
	}
	else 
		// normal case
		res = 1/f;

	// output value to outlet
	ToOutFloat(0,res); // (0 stands for the outlet index 0)
}

