#include "DefaultClass.h"
#include "ValueClass.h"
#include "DirectClass.h"
#include "CopyClass.h"
#include "ListClass.h"
#include "AggregateClass.h"

// GIVEN CODE
struct S
{
	int x;
	struct Foo
	{
		int i; int j; int a[3];
	} b;
};

int main() {
	// PART A)
	// default init
	DefaultClass c1;
	// value init
	ValueClass c2{};
	// direct init
	int init_val{ 4 };
	DirectClass c3(init_val);
	// copy init
	CopyClass c4(init_val);
	CopyClass c5(c4);
	// list init
	ListClass c6{ init_val, init_val + 4, init_val + 8 };
	// aggregate init
	AggregateClass c7{ init_val,'s', 3.14 };
	

	// PART B)
	// method 1 (default)
	S s1;
	// method 2 (value)
	S s2{};
	// method 3 (direct)
	S s3();
	// method 4 (copy)
	S s4(s2);
	// method 5 (list)
	S s5{ 0,{0, 0, {0, 0, 0}} };


}