class Solution {
public:
	enum Status {
		SOLID,
		EMPTY,
		UNKNOWN
	};
	
	vector<vector<Status>> bitmap; // by row
	typedef pair<int, int> Point;
	typedef queue<Point> Queue;
	

	int n_rows;
	int n_cols;

	int trapRainWater(vector<vector<int>>& heightMap) {


		n_rows = heightMap.size();
		if (n_rows <= 2) {
			return 0;
		}
		n_cols = heightMap[0].size();
		if (n_cols <= 2) {
			return 0;
		}
		bitmap.resize(n_rows);


		auto h = 0; // maximum height in heightMap
		for (auto row : heightMap) {
			for (auto val : row) {
				h = max(val, h);
			}
		}

		int sum = 0;

		for (int alt = h; alt >= 1; --alt) {
			sum += layer(heightMap, alt);
		}

		return sum;
	}
	void check_and_add_to_queue(Queue& q, int r, int c) {
		if (within_boundary(r, c) && bitmap[r][c] == UNKNOWN) {
			bitmap[r][c] = EMPTY;
			q.push(Point(r, c));
		}
	}
	bool within_boundary(int r, int c) {
		return r >= 0 && c >= 0 && r < n_rows && c < n_cols;
	}

	int layer(vector<vector<int>>& heightMap, int alt) {

		// clear bitmap
		for (auto& row : bitmap) {
			row.assign(n_cols, UNKNOWN);
		}


		for (int r = 0; r < n_rows; ++r) {
			for (int c = 0; c < n_cols; ++c) {
				if (heightMap[r][c] >= alt) {
					bitmap[r][c] = SOLID;
				}
			}
		}


		Queue q;

		// boundary
		// left, right
		for (int r = 0; r <= n_rows - 1; r += n_rows - 1) { // { 0, n_rows - 1 }
			for (int c = 1; c < n_cols - 1; ++c) { // [ 0, n_cols - 2 ]
				check_and_add_to_queue(q, r, c);
			}
		}
		// top, bottom
		for (int r = 1; r < n_rows - 1; ++r) { // [ 0, n_rows - 2 ]
			for (int c = 0; c <= n_cols - 1; c += n_cols - 1) { // { 0, n_cols - 1 }
				check_and_add_to_queue(q, r, c);
			}
		}
		// corners
		for (int r = 0; r <= n_rows - 1; r += n_rows - 1) { // { 0, n_rows - 1 }
			for (int c = 0; c <= n_cols - 1; c += n_cols - 1) { // { 0, n_rows - 1 }
				check_and_add_to_queue(q, r, c);
			}
		}
    
    // breadth-first search
		while (!q.empty()) {
			auto node = q.front();
			auto r = node.first;
			auto c = node.second;
			check_and_add_to_queue(q, r + 1, c);
			check_and_add_to_queue(q, r - 1, c);
			check_and_add_to_queue(q, r, c + 1);
			check_and_add_to_queue(q, r, c - 1);
			q.pop();
		}


		int counter = 0;

		for (int r = 0; r < n_rows; ++r) {
			for (int c = 0; c < n_cols; ++c) {
				counter += (bitmap[r][c] == UNKNOWN);
			}
		}

		return counter;

	}

};
