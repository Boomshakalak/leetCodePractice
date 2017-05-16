int longestConsecutive(vector<int> &num) {
	unordered_map<int, int> m;
	int r = 0;
	for (int i : num) {
		if (m[i]) continue;
		r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
	}
	return r;
}
