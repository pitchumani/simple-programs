#include <iostream>
#include <thread>

class Options {
	Options(int argc, char*argv[]) : argc(argc), argv(argv) {
	}
	static Options* instance;

public:
	int argc;
	char **argv;
	static Options* Get(int argc, char *argv[]) {
		if (instance == nullptr) {
			instance = new Options(argc, argv);
		}
		return instance;
	}
	Options(const Options&) = delete;
	void operator= (const Options&) = delete;
	bool handleOptions() {
		// handle options
		return true;
	}
};

Options* Options::instance = nullptr;

int main(int argc, char *argv[]) {
	auto opts = Options::Get(argc, argv);
	auto status = opts->handleOptions();
	std::cout << "Singleton Pattern!" << std::endl;
	if (!status) return 1;
	std::cout << "opts->argc: " << opts->argc << std::endl;
	auto opts1 = Options::Get(argc, argv);
	opts1->argc++;
	std::cout << "After, opts->argc: " << opts->argc << std::endl;
	return 0;
}
