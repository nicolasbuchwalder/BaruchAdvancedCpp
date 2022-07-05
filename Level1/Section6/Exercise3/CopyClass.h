#pragma once
class CopyClass
{
private:
	int val;
public:
	CopyClass(int init_val) { val = init_val; };

	CopyClass(const CopyClass& copy) {
		val = copy.val;
	};
};

