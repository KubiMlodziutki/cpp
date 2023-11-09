#include <iostream>
#include <string>
#include <sstream>
#include "ConstHeader.h"
#include <cmath>

using namespace std;

CNumber::CNumber() {
	numberAsString = defaultNumberAsString;
	numLength = numberAsString.length();
	separatedNumbers = new int[numLength];
	isPositive = true;
	for (int i = 0; i < numLength; i++) {
		stringstream ss;
		ss << numberAsString[i];
		ss >> separatedNumbers[i];
	}
	if (debugConstructInf) {
		cout << nonParamMessage << " " << endl;
	}
}

CNumber::CNumber(string myNumber) {
	if (myNumber[0] == '-') {
		isPositive = false;
		numberAsString = myNumber.substr(1, myNumber.length() - 1);
	}
	else {
		isPositive = true;
		numberAsString = myNumber;
	}
	numLength = numberAsString.length();
	separatedNumbers = new int[numLength];
	for (int i = 0; i < numLength; i++) {
		stringstream ss;
		ss << numberAsString[i];
		ss >> separatedNumbers[i];
	}
	/*
	for (int i = 0; i < numLength; i++) {
		cout << separatedNumbers[i];
		cout << "\n";
	}*/
	if (debugConstructInf) {
		cout << paramMessage << " " << endl;
	}
}

CNumber::CNumber(const CNumber &pOther) {
	isPositive = pOther.isPositive;
	numLength = pOther.numLength;
	numberAsString = pOther.numberAsString;
	separatedNumbers = new int[numLength];

	for (int i = 0; i < numLength; i++) {
		separatedNumbers[i] = pOther.separatedNumbers[i];
	}
	if (debugConstructInf) {
		cout << copyMessage << endl;
	}
}

CNumber::~CNumber() {
	delete[] separatedNumbers;
	isPositive = NULL;
	numLength = NULL;
	numberAsString = "";
	if (debugConstructInf) {
		cout << destrMessage << endl;
	}
}

string CNumber::getName() {
	return numberAsString;
}

int* CNumber::getArray() {
	return separatedNumbers;
}

bool CNumber::getRidOfZeros(int lenToSet) {
	if (lenToSet < 0) {
		return false;
	}
	else {
		int * newSeparatedNumbers = new int[lenToSet];
		int index = numLength - 1;
		for (int i = lenToSet - 1; i >= 0; i--) {
			newSeparatedNumbers[i] = separatedNumbers[index];
			index--;
		}
		delete[] separatedNumbers;
		numberAsString = "";

		numLength = lenToSet;
		separatedNumbers = newSeparatedNumbers;

		for (int i = 0; i < numLength; i++) {
			numberAsString += to_string(separatedNumbers[i]);
		}
		/*
		for (int i = 0; i < numLength; i++) {
			separatedNumbers[i] = newSeparatedNumbers[i];
		}
		delete[] newSeparatedNumbers;
		*/
		return true;
	}
}

string CNumber::toStr() {
	string result = "";
	if (!isPositive) {
		result += '-';
	}
	for (int i = 0; i < numLength; i++) {
		result += to_string(separatedNumbers[i]);
	}

	if (result.length() == 0) {
		result += '0';
	}

	return result;
}

void CNumber::operator=(CNumber other) {
	
	isPositive = other.isPositive;
	numLength = other.numLength;
	numberAsString = other.numberAsString;
	separatedNumbers = new int[numLength];

	for (int i = 0; i < numLength; i++) {
		separatedNumbers[i] = other.separatedNumbers[i];
	}
}

void CNumber::operator=(const int value) {
	*this = CNumber(to_string(value));
}

int CNumber::findMin(int number1, int number2) {
	if (number1 > number2) {
		return number2;
	}
	else return number1;
}
bool CNumber::num1BiggerThanNum2Abs(CNumber number1, CNumber number2) {
	if (number1.numLength > number2.numLength) {
		return true;
	}
	else if (number1.numLength < number2.numLength) {
		return false;
	}
	else {
		for (int i = 0; i < numLength; i++) {
			if (number1.separatedNumbers[i] > number2.separatedNumbers[i]) {
				return true;
			}
			else if (number1.separatedNumbers[i] < number2.separatedNumbers[i]) {
				return false;
			}
		}
		//return true if equal
		return true;
	}
}
bool CNumber::setNewLength(int lenToSet) {
	if (lenToSet < 0) {
		return false;
	}
	else {
		int * newSeparatedNumber = new int[lenToSet];

		for (int i = 0; i < lenToSet; i++) {
			newSeparatedNumber[i] = 0;
		}
		int index = lenToSet - 1;
		for (int i = numLength - 1; i >= 0; i--) {
			newSeparatedNumber[index] = separatedNumbers[i];
			index--;
		}
		delete[] separatedNumbers;
		separatedNumbers = newSeparatedNumber;
		numLength = lenToSet;
		/*
		separatedNumbers = new int[numLength];
		for (int i = 0; i < numLength; i++) {
			separatedNumbers[i] = newSeparatedNumber[i];
		}
		*/
		return true;
	}
}

bool CNumber::setPositivity(bool positivity) {
	isPositive = positivity;
	return true;
}

bool CNumber::string1BiggerThanString2(string number1, string number2) {
	if (number1.length() > number2.length()) {
		return true;
	}
	else if (number1.length() < number2.length()) {
		return false;
	}
	else{
		for (int i = 0; i < number1.length(); i++) {
			stringstream s1;
			stringstream s2;
			int digit1; 
			int digit2;
			s1 << number1[i];
			s2 << number2[i];

			s1 >> digit1;
			s2 >> digit2;

			if (digit1 > digit2) {
				return true;
			}
			if (digit1 < digit2) {
				return false;
			}
		}
	}
	return true;
}

CNumber CNumber::operator+(CNumber other) {
	CNumber result;
	CNumber *add1;
	CNumber *add2;
	int iterationNumber = findMin(numLength, other.numLength);
	if ((isPositive && other.isPositive) || (!isPositive && !other.isPositive)) {
		if (num1BiggerThanNum2Abs(*this, other)) {
			add1 = new CNumber(*this);
			add2 = new CNumber(other);
		}
		else {
			add1 = new CNumber(other);
			add2 = new CNumber(*this);
		}
		int index1 = add1->numLength - 1;
		int index2 = add2->numLength - 1;
		for (int i = 0; i < iterationNumber; i++) {
			add1->separatedNumbers[index1] += add2->separatedNumbers[index2];
			index1--;
			index2--;
		}
		for (int i = add1->numLength - 1; i >= 1; i--) {
			if (add1->separatedNumbers[i] > boundDigit) {
				add1->separatedNumbers[i] -= boundTens;
				add1->separatedNumbers[i - 1] += 1;
			}
		}
		if (add1->separatedNumbers[0] > boundDigit) {
			add1->setNewLength(add1->numLength + 1);
			add1->separatedNumbers[0] = 1;
			add1->separatedNumbers[1] -= boundTens;
		}
		result = *add1;
	}
	if ((!isPositive && other.isPositive) || (isPositive && !other.isPositive)) {
		if (num1BiggerThanNum2Abs(*this, other)) {
			add1 = new CNumber(*this);
			add2 = new CNumber(other);
		}
		else {
			add1 = new CNumber(other);
			add2 = new CNumber(*this);
		}
		int index1 = add1->numLength - 1;
		int index2 = add2->numLength - 1;
		for (int i = 0; i < iterationNumber; i++) {
			if (add1->separatedNumbers[index1] >= add2->separatedNumbers[index2]) {
				add1->separatedNumbers[index1] -= add2->separatedNumbers[index2];
				index1--;
				index2--;
			}
			else {
				int startIndex = index1;
				int endIndex = index1 - 1;
				bool notFound = true;
				while (notFound) {
					if (endIndex <= 0) {
						break;
					}
					else if (add1->separatedNumbers[endIndex] > 0) {
						notFound = false;
					}
					else {
						endIndex--;
					}
				}
				for (int j = endIndex; j < startIndex; j++) {
					add1->separatedNumbers[j] -= 1;
					add1->separatedNumbers[j + 1] += boundTens;
				}
				add1->separatedNumbers[index1] -= add2->separatedNumbers[index2];
				index1--;
				index2--;
			}
			
		}
		result = *add1;
		if ((!isPositive && other.isPositive) && (num1BiggerThanNum2Abs(*this, other))) {
			result.setPositivity(false);
		}
		else if ((!isPositive && other.isPositive) && !(num1BiggerThanNum2Abs(*this, other))) {
			result.setPositivity(true);
		}
		else if ((isPositive && !other.isPositive) && !(num1BiggerThanNum2Abs(*this, other))) {
			result.setPositivity(false);
		}
		else if ((isPositive && !other.isPositive) && (num1BiggerThanNum2Abs(*this, other))) {
			result.setPositivity(true);
		}

		int startIndex = 0;
		/*
		bool notFound = true;
		
		while (notFound || (startIndex == sizeof(result.separatedNumbers) / sizeof(int))) {
			if (separatedNumbers[startIndex] == 0) {
				startIndex++;
			}
			else {
				notFound = false;
			}
		}
		*/
		for (int i = 0; i < result.numLength; i++) {
			if (result.separatedNumbers[i] != 0) {
				break;
			}
			else {
				startIndex++;
			}
		}
		if (startIndex != 0) {
			result.getRidOfZeros(numLength - startIndex);
		}
	
	}

	return result;
}
CNumber CNumber::operator-(CNumber other) {
	CNumber result;
	CNumber *num1;
	CNumber *num2;

	num1 = new CNumber(*this);
	num2 = new CNumber(other);

	if (!isPositive && other.isPositive) {
		num1->setPositivity(true);

		result = num1->operator+(*num2);
		result.setPositivity(false);
	}

	if (isPositive && other.isPositive) {
		if (num1BiggerThanNum2Abs(*num1, *num2)) {
			num2->setPositivity(false);
			result = num1->operator+(*num2);
			result.setPositivity(true);
		}
		else {
			num1->setPositivity(false);
			result = num2->operator+(*num1);
			result.setPositivity(false);
		}
	}

	if (isPositive && !other.isPositive) {
		num2->setPositivity(true);

		result = num1->operator+(*num2);
		result.setPositivity(true);
	}

	return result;
}

CNumber CNumber::operator*(CNumber other) {
	CNumber result("0");
	result.setNewLength(numLength + other.numLength + 1);

	CNumber *num1;
	CNumber *num2;
	int movedIndex = 0;
	int multiplied;

	if (num1BiggerThanNum2Abs(*this, other)) {
		num1 = new CNumber(*this);
		num2 = new CNumber(other);
	}
	else {
		num1 = new CNumber(other);
		num2 = new CNumber(*this);
	}
	int whereAdding;
	for (int i = num2->numLength - 1; i >= 0; i--) {
		whereAdding = num1->numLength + num2->numLength;
		for (int j = num1->numLength - 1; j >= 0; j--) {
			multiplied = (num2->separatedNumbers[i]) * (num1->separatedNumbers[j]);

			result.separatedNumbers[whereAdding - movedIndex] += multiplied;
			whereAdding--;
		}
		movedIndex++;
	}

	for (int i = result.numLength - 1; i >= 0; i--) {
		bool stillDividing = true;

		while (stillDividing) {
			if (result.separatedNumbers[i] > boundDigit) {
				result.separatedNumbers[i] -= boundTens;
				result.separatedNumbers[i - 1] += 1;
			}
			else {
				stillDividing = false;
			}
		}
	}

	if ((isPositive && other.isPositive) || (!isPositive && !other.isPositive)) {
		result.setPositivity(true);
	}
	else {
		result.setPositivity(false);
	}
	int startIndex = 0;
	for (int i = 0; i < result.numLength; i++) {
		if (result.separatedNumbers[i] != 0) {
			break;
		}
		else {
			startIndex++;
		}
	}
	if (startIndex != 0) {
		result.getRidOfZeros(result.numLength - startIndex);
	}
	return result;
}

CNumber CNumber::CNumPower(CNumber exponent, int base) {
	CNumber substractor("1");
	CNumber result("1");
	CNumber baseMul(to_string(base));
	while (num1BiggerThanNum2Abs(exponent, substractor)) {
		result = result * baseMul;
		exponent = exponent - substractor;
	}

	return result;
}

CNumber CNumber::operator/(CNumber other) {
	string result = "";
	int counter = 0;
	if (!num1BiggerThanNum2Abs(*this, other)) {
		result += '0';
	}
	else if (other.numberAsString == "0") {
		cout << dividingByZero << endl;
		result += '0';
	}
	else {
		CNumber  *dividend = new CNumber(*this);
		CNumber mulDividor;
		CNumber temporary;
		int exponent = numLength - other.numLength;
		dividend->setPositivity(true);

		while (exponent >= 0) {
			int myPower = pow(baseToPower, exponent);
			CNumber powPow(to_string(myPower));
			mulDividor = other * powPow;
			mulDividor.setPositivity(true);
			temporary = mulDividor;
			if (num1BiggerThanNum2Abs(*dividend, temporary)) {
				while (num1BiggerThanNum2Abs(*dividend, temporary)) {
					temporary = temporary + mulDividor; 
					counter++;
				}
				temporary = temporary - mulDividor;
				result += to_string(counter);
				*dividend = *dividend - temporary;
			}
			else {
				if ((num1BiggerThanNum2Abs(other, *dividend)) && (exponent >= 0)) {
					for (int i = 0; i < exponent; i++) {
						result = result + '0';
					}
					exponent = 0;
				}
				exponent--;
			}
			counter = 0;
			
		}
	}

	CNumber resultNumber(result);
	
	if ((isPositive && other.isPositive) || (isPositive && other.isPositive)) {
		resultNumber.setPositivity(true);
	}
	if ((!isPositive && other.isPositive) || (isPositive && !other.isPositive)) {
		resultNumber.setPositivity(false);
	}

	return resultNumber;
}