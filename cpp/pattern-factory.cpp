#include <iostream>

class Enemy {
public:
	virtual void Attack() const = 0;
	// virtual destructor for proper cleanup
	virtual ~Enemy() = default;
};

class Goblin : public Enemy {
public:
	Goblin() {}
	void Attack() const override {
		std::cout << "Goblin Attack!" << std::endl;
	}
};

class Orc : public Enemy {
public:
	Orc() {}
	void Attack() const  override {
		std::cout << "Orc Attack!" << std::endl;
	}
};

class Dragon : public Enemy {
public:
	Dragon() {}
	void Attack() const override {
		std::cout << "Dragon Attack!" << std::endl;
	}
};

class EnemyFactory {
public:
	EnemyFactory() {}
	std::unique_ptr<Enemy> CreateEnemy(std::string type) {
		if (type == std::string("Goblin")) {
			return std::make_unique<Goblin>();
		} else if (type == std::string("Orc")) {
			return std::make_unique<Orc>();
		} else if (type == std::string("Dragon")) {
			return std::make_unique<Dragon>();
		} else {
			std::cerr << "Unknown enemy type!" << std::endl;
			return nullptr;
		}
	}
};


int main() {
	std::cout << "Factory pattern..." << std::endl;
	EnemyFactory efactory;
	auto goblin1 = efactory.CreateEnemy("Goblin");
	auto orc1 = efactory.CreateEnemy("Orc");
	auto dragon1 = efactory.CreateEnemy("Dragon");
	goblin1->Attack();
	orc1->Attack();
	dragon1->Attack();
	return 0;
}
