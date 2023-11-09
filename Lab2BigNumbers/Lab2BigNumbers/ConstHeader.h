#include <string>
using namespace std;

class CNumber {
public:
	CNumber();
	CNumber(string myNumber);
	~CNumber();
	CNumber(const CNumber &pOther);
	string getName();
	int *getArray();
	void operator=(CNumber other);
	void operator=(const int value);
	CNumber operator+(CNumber other);
	CNumber operator-(CNumber other);
	CNumber operator*(CNumber other);
	CNumber operator/(CNumber other);
	CNumber CNumPower(CNumber exponent, int base);
	string toStr();
private:
	bool isPositive;
	int numLength;
	string numberAsString;
	int *separatedNumbers;
	int findMin(int number1, int number2);
	bool num1BiggerThanNum2Abs(CNumber number1, CNumber number2);
	bool setNewLength(int lenToSet);
	bool getRidOfZeros(int lenToSet);
	bool setPositivity(bool positivity);
	bool string1BiggerThanString2(string number1, string number2);
};

const bool debugConstructInf = false;
const int baseToPower = 10;
const int boundDigit = 9;
const int boundTens = 10;
const string dividingByZero = "dzielenie przez zero, zwrocony wynik to 0";
const string defaultNumberAsString = "1000";
const string nonParamMessage = "bezparam";
const string paramMessage = "param";
const string copyMessage = "kopia";
const string destrMessage = "destr";