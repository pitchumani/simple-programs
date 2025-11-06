export module math;

export int add(int a, int b) {
	return a + b;
}
export int sub(int a, int b) {
	return a - b;
}

export int mul(int a, int b) {
	return a * b;
}

export namespace mymath
{
    int square(int a) {
    	return a * a;
    }

    int power(int a, int b) {
        int result = 1;
        for (int i = 0; i < b; ++i) {
    	    result *= a;
        }
        return result;
    }
}

