#include <iostream>

class Expression;
class Number;
class Add;
class Sub;

// visitor interface
class Visitor {
public:
	Visitor() {}
	virtual ~Visitor() {}
	virtual void Visit(Number *e) = 0;
	virtual void Visit(Add *e) = 0;
	virtual void Visit(Sub *e) = 0;
};

// element interface
class Expression {
public:
	Expression() {}
	virtual ~Expression() {}
	virtual void Accept(Visitor* v) = 0;
	template <typename T>
	bool is() {
		return (dynamic_cast<T*>(this) != nullptr);
	}
	template <typename T>
	T *to() {
		return dynamic_cast<T*>(this);
	}
};

class Number : public Expression {
	int val;
public:
	Number(int n) : val(n) {}
	int Get() { return val; }
	void Accept(Visitor *v) override {
		// visite number node
		v->Visit(this);
	}
};

class Add : public Expression {
public:
	Expression *lhs;
	Expression *rhs;
	Add(Expression *e1, Expression *e2) : lhs(e1), rhs(e2) {}
	void Accept(Visitor *v) override {
		// visite lhs
		if (auto add = lhs->to<Add>()) {
			v->Visit(add);
		} else if (auto sub = lhs->to<Sub>()) {
			v->Visit(sub);
		} else if (auto num = lhs->to<Number>()) {
			v->Visit(num);
		} else {}
		// visit rhs
		if (auto add = rhs->to<Add>()) {
			v->Visit(add);
		} else if (auto sub = rhs->to<Sub>()) {
			v->Visit(sub);
		} else if (auto num = rhs->to<Number>()) {
			v->Visit(num);
		} else {}
	}
};

class Sub : public Expression {
public:
	Expression *lhs;
	Expression *rhs;
	Sub(Expression *e1, Expression *e2) : lhs(e1), rhs(e2) {}
	void Accept(Visitor *v) override {
		// visite lhs
		if (auto add = lhs->to<Add>()) {
			v->Visit(add);
		} else if (auto sub = lhs->to<Sub>()) {
			v->Visit(sub);
		} else if (auto num = lhs->to<Number>()) {
			v->Visit(num);
		} else {}
		// visit rhs
		if (auto add = rhs->to<Add>()) {
			v->Visit(add);
		} else if (auto sub = rhs->to<Sub>()) {
			v->Visit(sub);
		} else if (auto num = rhs->to<Number>()) {
			v->Visit(num);
		} else {}
	}
};

class Inspector : public Visitor {
public:
	Inspector() {}
	void Visit(Number *e) override {
		std::cout << "Inspector: visited Number (" << e->Get() << ")" << std::endl;
	}
	void Visit(Add *e) override {
		std::cout << "Inspector: visited Add node" << std::endl;
		e->lhs->Accept(this);
		e->rhs->Accept(this);
	}
	void Visit(Sub *e) override {
		std::cout << "Inspector: visited Sub node" << std::endl;
		e->lhs->Accept(this);
		e->rhs->Accept(this);
	}
};

class Modifier : public Visitor {
public:
	Modifier() {}
	void Visit(Number *e) override {
		std::cout << "Modifier: visited Number (" << e->Get() << ")" << std::endl;
	}
	void Visit(Add *e) override {
		std::cout << "Modifier: visited Add node" << std::endl;
		e->lhs->Accept(this);
		e->rhs->Accept(this);
	}
	void Visit(Sub *e) override {
		std::cout << "Modifier: visited Sub node" << std::endl;
		e->lhs->Accept(this);
		e->rhs->Accept(this);
	}
};
	

int main() {
	std::cout << "Visitor Pattern!" << std::endl;

	// 4 + 5 - 6
	Number *num1 = new Number(4);
	Number *num2 = new Number(5);
	Number *num3 = new Number(6);
	auto e1 = new Add(num1, num2);
	auto e2 = new Sub(e1, num3);
	std::cout << "Visit by Inspector" << std::endl;
	Inspector *ins = new Inspector();
	ins->Visit(e2);
	std::cout << "Visit by Modifier" << std::endl;
	Modifier *mod = new Modifier();
	mod->Visit(e2);
	return 0;
}
