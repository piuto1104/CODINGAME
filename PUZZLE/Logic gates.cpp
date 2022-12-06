#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

typedef struct INPUT {
	string name;
	string signal;
}INPUT;

int n;
int m;
INPUT input[10];

int getIndex(string name) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (input[i].name == name) {
			ret = i;
			break;
		}
	}
	return ret;
}

string AND(string a, string b) {
	string ret = "";
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '-' & b[i] == '-') ret += "-";
		else ret += "_";
	}
	return ret;
}

string OR(string a, string b) {
	string ret = "";
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '-' | b[i] == '-') ret += "-";
		else ret += "_";
	}
	return ret;
}

string XOR(string a, string b) {
	string ret = "";
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) ret += "-";
		else ret += "_";
	}
	return ret;
}

string inverted(string a) {
	string ret = "";
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '_') ret += "-";
		else ret += "_";
	}
	return ret;
}


string solve(string out_name, string type, int idx1, int idx2) {
	string ret = out_name + " ";

	if (type == "AND") {
		ret += AND(input[idx1].signal, input[idx2].signal);
	}
	else if (type == "OR") {
		ret += OR(input[idx1].signal, input[idx2].signal);
	}
	else if (type == "XOR") {
		ret += XOR(input[idx1].signal, input[idx2].signal);
	} 
	else if (type == "NAND") {
		ret += inverted(AND(input[idx1].signal, input[idx2].signal));
	}
	else if (type == "NOR") {
		ret += inverted(OR(input[idx1].signal, input[idx2].signal));
	}
	else if (type == "NXOR") {
		ret += inverted(XOR(input[idx1].signal, input[idx2].signal));
	}
	return ret;
}

int main()
{
	cin >> n; cin.ignore();
	cin >> m; cin.ignore();
	for (int i = 0; i < n; i++) {
		string input_name;
		string input_signal;
		cin >> input[i].name >> input[i].signal; cin.ignore();
	}
	for (int i = 0; i < m; i++) {
		string output_name;
		string type;
		string input_name_1;
		string input_name_2;
		// cin >> output[i].output_name >> output[i].type >> output[i].input_name_1 >> output[i].input_name_2; cin.ignore();
		cin >> output_name >> type >> input_name_1 >> input_name_2; cin.ignore();

		cout << solve(output_name, type, getIndex(input_name_1), getIndex(input_name_2)) <<"\n";
	}
}