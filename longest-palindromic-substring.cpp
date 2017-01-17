class Solution {
public:
string longestPalindrome(string s) {
	int n = s.size();
	bool f[1000][1000] = { false }; //[i, j] inclusive
	int max_len = 1, start = 0;
	for (int i = n-1; i >=0 ; i--) {
		for (int j = i; j < n; j++) {
			if (i == j)
				f[i][j] = true;
			else if (j == i + 1)
				f[i][j] = (s[i] == s[j]);
			else
				f[i][j] = ((s[i] == s[j]) && i+1<n && j-1>=0 && f[i + 1][j - 1]);
			if (f[i][j] && j - i + 1 > max_len)
				start = i, max_len = j - i + 1;
		}
	}
	return s.substr(start, max_len);
}
};
