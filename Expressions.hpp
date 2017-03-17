#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H


class Expression{
public:
	void *val;
	bool lit;
	bool str;
	bool ident;
	enum exprType{ intType, charType, boolType, stringType, reg };

	exprType type;
	template <class T>
	Expression(T val, exprType type, bool lit = false, bool str = false, bool ident = false) : type(type)
		, lit(lit)
		, str(str)
		, ident(ident)
	{
		T *temp = new T(val);
		this->val = ((void*)temp);
	};

	template<class T>
	T getVal(){
		auto temp = (T*)val;
		return *temp;
	};
};



#endif