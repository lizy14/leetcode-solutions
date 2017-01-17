class Solution {
public:

string& replace(string& str, const string& old_value, const string& new_value)
{
	auto pos = str.find(old_value);
	if (pos != string::npos)
		str.replace(pos, old_value.length(), new_value);
	return str;
}
int romanToInt(string s) {
	unordered_map<char, int> v = {
		{ 'M',1000 },
		{ 'D',500 },
		{ 'C',100 },
		{ 'L',50 },
		{ 'X',10 },
		{ 'V',5 },
		{ 'I',1 }
	};
	vector<pair<string, string>> r = {
		{ "DCCCC","CM" },
		{ "CCCC" ,"CD" },
		{ "LXXXX","XC" },
		{ "XXXX" ,"XL" },
		{ "VIIII","IX" },
		{ "IIII" ,"IV" }
	};
	for (auto i : r)
		s = replace(s, i.second, i.first);
	int res = 0;
	for (auto c : s)
		res += v[c];
	return res;
}
string intToRoman(int num) {
	vector<pair<char, int>> v = {
		{ 'M',1000 },
		{ 'D',500 },
		{ 'C',100 },
		{ 'L',50 },
		{ 'X',10 },
		{ 'V',5 },
		{ 'I',1 } 
	};
	vector<pair<string, string>> r = { 
		{ "DCCCC","CM" },
		{ "CCCC" ,"CD" },
		{ "LXXXX","XC" },
		{ "XXXX" ,"XL" },
		{ "VIIII","IX" },
		{ "IIII" ,"IV" }
	};
	string str;
	for (auto i : v) {
		int s = i.second;//scale
		int n = num / s;
		num %= s;
		for (int j = 0; j < n; j++) {
			str.push_back(i.first);
		}
	}
	for (auto i : r) {
		str = replace(str, i.first, i.second);
	}
	return str;
}

};
