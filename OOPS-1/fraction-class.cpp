class Fraction {
	private:
	
		int numerator;
		int denominator;

	public:

	Fraction(int numerator, int denominator) {
		this -> numerator = numerator; //Same as this.numerator = numerator
		this -> denominator = denominator;
	}

	void print() {
		// Not necessary to write this here as when we write numerator here this is alredy assumed
		cout << this -> numerator << " / " << denominator << endl;
	}

	void simplify() {	// Finding gcd and simplifying the answer
		int gcd = 1;
		int j = min(this -> numerator, this -> denominator);
		for(int i = 1; i <= j; i++) {
			if(this -> numerator % i == 0 && this -> denominator % i ==0) {
				gcd = i;
			}			
		}
		this -> numerator = this -> numerator / gcd;
		this -> denominator = this -> denominator / gcd;
	}

	void add(Fraction f2) {
		int lcm = denominator * f2.denominator;
		int x = lcm / denominator;
		int y = lcm / f2.denominator;

		int num = x * numerator + (y * f2.numerator);

		numerator = num;
		denominator = lcm;
			
		simplify();	// Call simplify on this (whaterver is passed f1 here)
	}
};
