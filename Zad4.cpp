#include <iostream>
#include <string>

using namespace std;


class CTable
{
private:
	string sName;
	int iTableLen;
	int *iTable;

	string sNameDefault = "default";
	int iTableLenDefault = 10;

	string sTextNonParam = "bezp: ";
	string sTextParam = "parametr: ";
	string sTextCopy = "kopiuj: ";
	string sTextDestr = "usuwam: ";
	string sTextLenError = "nie mozna przypisac wartosci dlugosci tablicy: ";
	string sTextSetLenError = "nie mozna zmienic dlugosci tablicy na: ";
	string sTextSetLenSuccess = "udalo sie zmienic dlugosc tablicy na: ";
	string sTextCopyAddon = "_copy";

public:
	CTable() 
	{
		sName = sNameDefault;
		iTableLen = iTableLenDefault;

		iTable = new int[iTableLen];
		cout << sTextNonParam << "'" << sName << "'" << endl;
	}

	CTable(string sConstructorName, int iConstructorTableLen) {
		sName = sConstructorName;
		iTableLen = iConstructorTableLen;

		cout << sTextParam << "'" << sName << "'" << endl;

		if (iConstructorTableLen <= 0) {
			cout << sTextLenError << iConstructorTableLen << endl;
			iTableLen = iTableLenDefault;
			iTable = new int[iTableLen];
		}
		else {
			iTableLen = iConstructorTableLen;
			iTable = new int[iTableLen];
		}
	}

	CTable(CTable &pcOther) {
		sName = pcOther.sName + sTextCopyAddon;
		iTableLen = pcOther.iTableLen;
		int *iTable = new int[iTableLen];

		for (int i = 0; i < iTableLen; i++) {
			iTable[i] = pcOther.iTable[i];
		}

		cout << sTextCopy << "'" << sName << "'" << endl;
	}
	~CTable() {
		cout << sTextDestr << "'" << sName << "'" << endl;
		delete[] iTable;
	}

	void vSetName(string sNameToSet) {
		sName = sNameToSet;
	}

	bool bSetNewSize(int iTableLenToSet) {
		if (iTableLenToSet <= 0) {
			cout << sTextSetLenError << iTableLenToSet << endl;
			return false;
		}
		else {
			iTableLen = iTableLenToSet;
			cout << sTextSetLenSuccess << iTableLenToSet << endl;
			return true;
		}
	}

	CTable *pcClone() {
		return new CTable(*this);
	}

	string sGetName() {
		return sName;
	}
	
	int iGetLen() {
		return iTableLen;
	}

	int *iGetLenAddress() {
		return &iTableLen;
	}

	void vShowParameters() {
		cout << "moja nazwa to: " << sName << ", moja dlugosc to: " << iTableLen << endl;
	}
};

void v_mod_tab(CTable *pcTab, int iNewSize) {
	pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize) {
	cTab.bSetNewSize(iNewSize);
}

int main() {
	CTable cTabNonParam;
	CTable cTabParam("myCTable", 4);
	CTable *cTabCopy = new CTable(cTabParam);
	CTable *cTabClone = cTabParam.pcClone();

	cTabNonParam.vShowParameters();
	cTabNonParam.bSetNewSize(-3);
	cTabNonParam.bSetNewSize(20);
	cTabNonParam.vShowParameters();

	cTabParam.vShowParameters();

	(*cTabCopy).vShowParameters();

	(*cTabClone).vShowParameters();

	//cout << cTabNonParam.iGetLenAddress() << endl; 
	v_mod_tab(&cTabNonParam, 2);
	//cout << cTabNonParam.iGetLenAddress() << endl;
	cTabNonParam.vShowParameters();

	//cout << cTabNonParam.iGetLenAddress() << endl;
	v_mod_tab(cTabCopy, 14);
	//cout << cTabNonParam.iGetLenAddress() << endl;
	(*cTabCopy).vShowParameters();
}