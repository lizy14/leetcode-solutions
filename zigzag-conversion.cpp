class Solution {
public:
string convert(string s, int numRows) {
	vector<vector<char> > v(numRows);
	int period = 2 * numRows - 2;
	if (period == 0)
	    period = 1;
	for (int i = 0; i < s.length(); i++) {
		int j = i % period;
		if (j >= numRows)
			j = period - j;
		v[j].push_back(s[i]);
	}
	string r;
	for (auto& i : v) {
		for (auto j : i) {
			r.push_back(j);
		}
	}
	return r;
}

};
