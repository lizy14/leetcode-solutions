class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> lines;
		auto line_begin = words.begin();

		while (line_begin != words.end()) {
			auto line_end = line_begin;
			auto nChars = 0;
			auto nWords = 0;
			do {
				auto word = *line_end;
				if ((nChars + word.length()) + (nWords + 1) - 1 > maxWidth) {
					break;
				}
				nWords++;
				nChars += word.length();
				++line_end;
			} while (line_end != words.end());

			// generate line for [line_begin, line_end)
			string line;
			if (line_end == words.end() || nWords == 1) {
				for (auto it = line_begin; it != line_end; ++it) {
					line += *it;
					if (it + 1 != line_end) {
						line.push_back(' ');
					}
				}
				while (line.length() < maxWidth) {
					line.push_back(' ');
				}
			}
			else {

				// more than one word and not the last line
				auto quotient = (maxWidth - nChars) / (nWords - 1);
				auto residue = (maxWidth - nChars) % (nWords - 1);
				for (auto it = line_begin; it != line_end; ++it) {
					line += *it;
					if (it + 1 != line_end) {
						for (int i = 0; i < quotient; ++i) {
							line.push_back(' ');
						}
						if (residue) {
							residue--;
							line.push_back(' ');
						}
					}
				}

			}
			lines.push_back(line);
			line_begin = line_end;
		};

		return lines;
	}
};
