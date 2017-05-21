class Solution {
	inline int getBits(char c) {
		switch (c) {
		case 'A': return 0;
		case 'G': return 1;
		case 'C': return 2;
		case 'T': return 3;
		}
	}
	int _hash(string s) {
		int result = 0;
		for (char c : s) {
			result <<= 2;
			result |= getBits(c);
		}
		return result;
	}
	const static int mask = (1 << 20) - 1;  // 2 bits * 10
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<int, int> counter;
		vector<string> result;
		auto n = s.length();
		if (n < 10) {
			return result;
		}
		int hashed = 0;
		for (auto i = 0; i < n; ++i) {
			
			hashed <<= 2;
			hashed |= getBits(s[i]);
			hashed &= mask;

			if (i >= 9 && counter[hashed]++ == 1) {
				result.push_back(s.substr(i - 10 + 1, 10));
			}
		}
		return result;

	}
};
