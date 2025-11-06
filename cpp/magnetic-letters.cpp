#include <iostream>
#include <string>

void canConstructWords(std::string s1, std::string s2, std::string box) {
	auto t = s1 + s2;
	std::sort(t.begin(), t.end());
	std::sort(box.begin(), box.end());
	if (t == box) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}
}

int main() {
	std::string s1("SAM");
	std::string s2("JOHN");
	std::string b("SMJAOHN");
	canConstructWords(s1, s2, b);
	return 0;
}
