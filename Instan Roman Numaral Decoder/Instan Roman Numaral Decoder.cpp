#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> roman_and_normal;

int find_normal_from_numerals(string numeral) {
	int normal = 0;
	for (int i = 0; i+1 < numeral.size(); i++) {

		if (roman_and_normal[numeral[i]] >= roman_and_normal[numeral[i + 1]]) {
			normal += roman_and_normal[numeral[i]];
		}
		else {
			normal -= roman_and_normal[numeral[i]];
		}

	}
	normal += roman_and_normal[numeral[numeral.size() - 1]];
	return normal;
}

int main()
{
	roman_and_normal['i'] = 1;
	roman_and_normal['v'] = 5;
	roman_and_normal['x'] = 10;
	roman_and_normal['l'] = 50;
	roman_and_normal['c'] = 100;
	roman_and_normal['d'] = 500;
	roman_and_normal['m'] = 1000;
	cout << find_normal_from_numerals("mmmcdlxvii");
}