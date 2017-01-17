class Solution {
public:

class RegEx {
	// NFA
	typedef int State;
	typedef char Char; /*1 to 127, 0 reserved*/
	typedef set<State> States;
	typedef pair<Char, State> Pair;
	typedef map<Pair, States> Transition;

	#define CHAR_FOR_WILD_CARD '.'
	#define CHAR_FOR_REPEAT '*'
	#define CHAR_FOR_EMPTY 0

	Transition delta;
	State initial;
	State terminal;
public:
	RegEx(string& pattern) {
		initial = 0;
		State trunk = initial;
		State count = 1;
		int i = 0;
		int n = pattern.length();
		while (1) {
			if (i >= n) {
				break;
			}
			Char c = pattern[i];
			if ((i + 1 < n) && pattern[i + 1] == CHAR_FOR_REPEAT) {
				delta[Pair(c, trunk)].insert(trunk);
				delta[Pair(CHAR_FOR_EMPTY, trunk)].insert(count);

				trunk = count++;
				i += 2;
			} else {
				delta[Pair(c, trunk)].insert(count);
				
				trunk = count++;
				i++;
			}
		}
		terminal = trunk;
	}
	States enclose(States& states) {
		auto validStates = states;
		while (1) {
			auto validStatesClosure = validStates;
			int o = validStatesClosure.size();
			for (auto state : validStates) {
				auto epsilon = delta[Pair(CHAR_FOR_EMPTY, state)];
				validStatesClosure.insert(epsilon.begin(), epsilon.end());
			}
			int n = validStatesClosure.size();
			if (n == o)break;
			validStates = validStatesClosure;
		}
		return validStates;
	}
	bool match(string& s) {
		States validStates;
		validStates.insert(initial);
		validStates = enclose(validStates);

		for (auto c : s) {

			States newValidStates;
			for (auto oldState : validStates) {
				for (auto s : delta[Pair(c, oldState)])
					newValidStates.insert(s);
				for (auto s : delta[Pair(CHAR_FOR_WILD_CARD, oldState)])
					newValidStates.insert(s);
			}

			validStates = enclose(newValidStates);

			if (validStates.empty())
				return false;
		}
		
		for (auto i : validStates)
			if (i == terminal)
				return true;
		return false;
	}
};

bool isMatch(string s, string p) {
	return RegEx(p).match(s);
}

};
