class Solution {
public:
	bool validUtf8(vector<int> &data) {

		int tails = 0;
		for (auto byte : data) {

			if (tails == 0) {
				tails = head(byte) - 1;
				if (tails < 0) {
					return false;
				}
			}
			else {
				tails--;
				if (!tail(byte)) {
					return false;
				}
			}
		}
		return tails == 0;
	}

private:
	bool validate(int mask, int target, int val) { 
	    return (mask & val) == target; 
	}
	bool tail(int byte) { 
	    return validate(0b11000000, 0b10000000, byte); 
	}
	int head(int byte) {
		if (validate(0b10000000, 0b00000000, byte)) {
			return 1;
		}
		if (validate(0b11100000, 0b11000000, byte)) {
			return 2;
		}
		if (validate(0b11110000, 0b11100000, byte)) {
			return 3;
		}
		if (validate(0b11111000, 0b11110000, byte)) {
			return 4;
		}
		return 0;
	}
};
