string reverseVowels(string s) {
	queue<char>qt;
	for (int i = 0; i<s.size(); i++) {
		if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u') {
			qt.push(s[i]);
		}
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u') {
			s[i] = qt.front();
			qt.pop();
		}
	}
	return s;
}
