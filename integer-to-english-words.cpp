class Solution {
    
public:
unordered_map<int, string> dict = {
	{ 0, "Zero " },
	{ 1, "One " },
	{ 2, "Two " },
	{ 3, "Three " },
	{ 4, "Four " },
	{ 5, "Five " },
	{ 6, "Six " },
	{ 7, "Seven " },
	{ 8, "Eight " },
	{ 9, "Nine " },
	{ 10, "Ten " },
	{ 11, "Eleven " },
	{ 12, "Twelve " },
	{ 13, "Thirteen " },
	{ 14, "Fourteen " },
	{ 15, "Fifteen " },
	{ 16, "Sixteen " },
	{ 17, "Seventeen " },
	{ 18, "Eighteen " },
	{ 19, "Nineteen " },
	{ 20, "Twenty " },
	{ 30, "Thirty " },
	{ 40, "Forty " },
	{ 50, "Fifty " },
	{ 60, "Sixty " },
	{ 70, "Seventy " },
	{ 80, "Eighty " },
	{ 90, "Ninety " },
	{ 100, "Hundred " },
};

string trunk(int num) {
	if (num == 0)
		return "";
	string str;
	int h = num / 100;
	if (h) {
		str += dict[h];
		str += dict[100];
	}
	num %= 100;
	if (num <= 20) {
		if(num) str += dict[num];
	}
	else {
		int d = num % 10;
		num /= 10, num *= 10;
		if(num) str += dict[num];
		if(d) str += dict[d];
	}
	return str;
}
string numberToWords(int num) {
	string str;
	if (num == 0)
		str = dict[0];
	else {
		unordered_map<int, string> scale = {
			{ 1, "Thousand " },
			{ 2, "Million " },
			{ 3, "Billion " },
			{ 4, "Trillion " }
		};
		int i = 0;
		while (num != 0) {
			int t = num % 1000;
			if(t) str = trunk(num % 1000) + scale[i] + str;
			num /= 1000;
			i++;
		}
	}
	return str.substr(0, str.length()-1);
}
};
