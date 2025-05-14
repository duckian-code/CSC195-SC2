#include <iostream>
using namespace std;

struct Person
{
	char name[32];
	int id;
};

void Square(int i) {
	i = i * i;
}

void Double(int* i) {
	*i = *i * 2;
}

int main()
{
	// ** REFERENCE **
	//
	// declare an int variable and set the value to some number (less than 10)
	// declare a int reference and set it to the int variable above
	int i = 7;
	int& r = i;
	// output the int variable
	std::cout << i << std::endl;
	// set the int reference to some number
	// output the int variable
	// what happened to the int variable when the reference was changed? (insert answer)
	r = 8;
	cout << i << endl;
	cout << "i was changed to 8" << endl;
	// output the address of the int variable
	// output the address of the int reference
	// are the addresses the same or different? (insert answer)
	cout << &i << endl;
	cout << &r << endl;
	cout << "They have the same address" << endl;
	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter (i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	Square(i);
	// output the int variable to the console
	cout << i << endl;
	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""

	// ** POINTER VARIABLE **
	//
	// declare an int pointer, set it to nullptr (it points to nothing)
	// set the int pointer to the address of the int variable created in the REFERENCE section
	int* p = nullptr;
	p = &i;
	// output the value of the pointer
	// what is this address that the pointer is pointing to? (insert answer)
	// output the value of the object the pointer is pointing to (dereference the pointer)
	cout << p << endl;
	cout << *p << endl;
	cout << "Pointer same as i, value same as i" << endl;
	// ** POINTER PARAMETER **
	//
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter (i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	Double(p);
	// output the dereference pointer
	// output the int variable created in the REFERENCE section
	// did the int variable's value change when using the pointer?
	cout << *p << endl;
	cout << i << endl;
	cout << "The variable value did change" << endl;
}