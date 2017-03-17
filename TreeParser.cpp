#include "Expressions.hpp"
#include "symbol_table.hpp"
#include "TreeParser.hpp"
#include "Var.hpp"
#include <fstream>
#include <string>
extern void yyerror(const char *str);
extern int num_lines;
extern std::fstream aout;

void ProgramStart()
{
	aout<<"__main:"<<std::endl<<"move $fp, $sp"<<std::endl<<"move $gp, $fp"<<std::endl;
}

void VariableDeclaration(std::vector<std::string> *identList, Type *typeVal, std::string val)
 {
	switch(typeVal->typeType)
	{
		case Type::type:SymbolTable::getInstance()->addSymbol(typeVal->name, *typeVal,true);
			break;
		case Type::array:SymbolTable::getInstance()->addSymbol(typeVal->name, *(dynamic_cast<Array_Type*>(typeVal)), true);
            break;
        case Type::record:SymbolTable::getInstance()->addSymbol(typeVal->name, *(dynamic_cast<Record*>(typeVal)), true);
            break;
	}
	Var var(*typeVal, SymbolTable::getInstance()->offset.back(),val);
	SymbolTable::getInstance()->offset.back()+=typeVal->size;
	SymbolTable::getInstance()->addSymbol(val,var,true);
 }
 
void MoreVariableDeclarations(Type *typeVal, std::string val)
{
	Var var(*typeVal, SymbolTable::getInstance()->offset.back(),val);
	SymbolTable::getInstance()->offset.back()+=4;
	SymbolTable::getInstance()->addSymbol(val,var,true);
}

void TypeDeclaration(char *strVal, Type *typeVal)
{
	typeVal->name = strVal;
	switch(typeVal->typeType)
	{
		case Type::type:SymbolTable::getInstance()->addSymbol(strVal, *typeVal,true);
			break;
		case Type::array:SymbolTable::getInstance()->addSymbol(strVal, *(dynamic_cast<Array_Type*>(typeVal)),true);
			break;
		case Type::record:SymbolTable::getInstance()->addSymbol(strVal, *(dynamic_cast<Record*>(typeVal)),true);
			break;
	}
}

void addRecord(Record *recVal)
{
	if(!SymbolTable::getInstance()->lookup(recVal->name))
	{
		SymbolTable::getInstance()->addSymbol(recVal->name, *(dynamic_cast<Record*>(recVal)),true);
	}
}

void addArray_Type(Array_Type *arrVal)
{
	if(!SymbolTable::getInstance()->lookup(arrVal->name))
	{
		SymbolTable::getInstance()->addSymbol(arrVal->name, *(dynamic_cast<Array_Type*>(arrVal)),true);
	}
}

Type * newSimpleType(char *strVal)
{
	SymbolTable::getInstance()->checkType(strVal);
    return dynamic_cast<Type*>(SymbolTable::getInstance()->getSymbol(strVal).get());
}

void create(Expression *lhs, Expression *rhs)
{
	int location = 0;
	std::cout<<"create expression"<<std::endl;
	if(rhs->lit)
	{
		std::cout<<"create() rhs->lit"<<std::endl;
		location = SymbolTable::getInstance()->getReg();
	}
	else
	{
		std::cout<<"create() !rhs->lit"<<std::endl;
		location = rhs->getVal<int>();
		std::cout<<"location: "<<location<<std::endl;
	}

	if(rhs->lit)
	{
		std::cout<<"create() 2nd rhs->lit"<<std::endl;
		aout <<"\t li $"<<location<<", "<<rhs->getVal<int>()<<std::endl;
	}

	if(rhs->ident)
	{	
		std::cout<<"create() rhs->ident"<<std::endl;
		int reg = SymbolTable::getInstance()->getReg();
		aout <<"\t lw $"<<reg<<", "<<location<<"($fp)"<<std::endl;
		aout <<"\t sw $"<<reg<<", "<<lhs->getVal<int>()<<"($fp)"<<std::endl;
	}
	else
	{
		std::cout<<"create() !rhs->ident"<<std::endl;
		aout <<"\t sw $"<<location<<", "<<lhs->getVal<int>()<<"($fp)"<<std::endl;
	}
	std::cout<<"About to return from create()"<<std::endl;
}

/*Control Loop Functions*/
void repeatStmt(Expression * cond)
{
	std::cout<<"begin repeatStmt****************************************************"<<std::endl;
	int num = SymbolTable::getInstance()->controlStack.back();
	int reg;

	if(cond->type==Expression::reg)
	{
		reg = cond->getVal<int>();
	}
	else
	{
		reg = SymbolTable::getInstance()->getReg();
	}

	if(cond->type!=Expression::reg)
	{
		if(cond->lit)
		{
			aout << "\t li $"<<std::to_string(reg)<<", "<<std::to_string(cond->getVal<int>())<<std::endl;
		}
		else
		{
			aout << "\t lw $" <<std::to_string(reg)<<", "<<std::to_string(cond->getVal<int>())<<"($fp)"<<std::endl;
		}
	}
	aout <<"\t beq $"<<reg<<" , $zero, __controlStmt"<<num<<std::endl;
	SymbolTable::getInstance()->controlStack.pop_back();
	std::cout<<"end repeatStmt"<<std::endl;
}

void forStmt(Expression * cond)
{
    std::cout<<"begin forStatement****************************************************"<<std::endl;
    int num = SymbolTable::getInstance()->controlStack.back();
    int reg;

    if(cond->type==Expression::reg)
    {
        reg = cond->getVal<int>();
    }
    else
    {
        reg = SymbolTable::getInstance()->getReg();
    }

    if(cond->type!=Expression::reg)
    {
        if(cond->lit)
        {
            aout << "\t li $"<<std::to_string(reg)<<", "<<std::to_string(cond->getVal<int>())<<std::endl;
        }
        else
        {
			aout << "\t lw $" <<std::to_string(reg)<<", "<<std::to_string(cond->getVal<int>())<<"($fp)"<<std::endl;
    	}
	}
    aout <<"\t beq $"<<reg<<" , $zero, __controlStmt"<<num<<std::endl;
    SymbolTable::getInstance()->controlStack.pop_back();
}

void loopBegin()
{
	std::cout<<"Loop Begin**********"<<std::endl;
	//Add New Jump Label to Table
	int num = SymbolTable::getInstance()->controlLabels++;
	SymbolTable::getInstance()->controlStack.push_back(num);
	aout <<"__controlStmt"<<num<<": ";
}


void whileStmt(Expression * cond, bool input)
{
	int num = SymbolTable::getInstance()->controlStack.back();
    int reg;

	if(cond->type==Expression::reg)
	{
		reg = cond->getVal<int>();
	}
	else
	{
	    reg = SymbolTable::getInstance()->getReg();
	}
	
	if(cond->type!=Expression::reg)
	{
	    if(cond->lit)
	    {
		    aout << "\t li $"<<std::to_string(reg)<<", "<<std::to_string(cond->getVal<int>())<<std::endl;
	    }
	    else
	    {
	         aout << "\t lw $" <<std::to_string(reg)<<", "<<std::to_string(cond->getVal<int>())<<"($fp)"<<std::endl;        
        }
	}

	if(input==false)
	{
		aout <<"\t bne $"<<reg<<", $zero, __controlStmtAfter"<<num<<std::endl;
	}
	else
	{
		aout << "\t beq $"<<reg<<", $zero, __controlStmtAfter"<<num<<std::endl;
	}
	std::cout<<"In WhileStmt end"<<std::endl;
}

void loopEnd()
{
	aout <<"\t j __controlStmt"<<SymbolTable::getInstance()->controlStack.back()<<std::endl;
	aout <<"\t __controlStmtAfter"<<SymbolTable::getInstance()->controlStack.back()<<": "<<std::endl;

	SymbolTable::getInstance()->controlStack.pop_back();
	std::cout<<"At loopEnd()"<<std::endl;
}


/*If Statement Functions*/
void ifBegin()
{
	SymbolTable::getInstance()->ifStack.push_back(0);
	SymbolTable::getInstance()->controlStack.push_back(SymbolTable::getInstance()->controlLabels++);
}

void ifBranch(Expression * cond)
{
	int num = SymbolTable::getInstance()->ifStack.back(); //if stack size
	int count = SymbolTable::getInstance()->controlStack.back(); //control Stmt stack size
    int reg;

    if(cond->type==Expression::reg)
    {
        reg = cond->getVal<int>();
    }
    else
    {
        reg = SymbolTable::getInstance()->getReg();
    }

    if(cond->type!=Expression::reg)
    {
        if(cond->lit)
        {
            aout << "\t li $"<<std::to_string(reg)<<", "<<std::to_string(cond->getVal<int>())<<std::endl;
        }
        else
        {
            aout << "\t lw $" <<std::to_string(reg)<<", "<<std::to_string(cond->getVal<int>())<<"($fp)"<<std::endl;
        }
    }
    aout <<"\t beq $"<<reg<<" , $zero, __control"<<count<<"IfStmt"<<num<<std::endl;
}

void ifBranchEnd()
{
	aout <<"\t j __controlStmtAfter"<<SymbolTable::getInstance()->controlStack.back()<<std::endl;
}

void labelIfBranch()
{
	int count = SymbolTable::getInstance()->ifStack.back()++;
	int controlSize = SymbolTable::getInstance()->controlStack.back();
	aout <<"__control"<<controlSize<<"IfStmt"<<count<<": "<<std::endl;
}

void endIf()
{
    int ifSize = SymbolTable::getInstance()->ifStack.back();
    int controlSize = SymbolTable::getInstance()->controlStack.back();
	aout <<"\t __control"<<controlSize<<"IfStmt"<<ifSize<<": "<<std::endl;	
	aout <<"\t __conrolStmtAfter"<<controlSize<<": "<<std::endl;
	
	SymbolTable::getInstance()->controlStack.pop_back();
	SymbolTable::getInstance()->ifStack.pop_back();
}

void loadIntoRegister(int &dest, int &lhsReg, int &rhsReg, Expression * lhs, Expression * rhs)
{
	dest = SymbolTable::getInstance()->getReg();
	if (lhs->type == Expression::reg)
	{
		lhsReg = lhs->getVal<int>();
	}
	else
	{
		lhsReg = SymbolTable::getInstance()->getReg();
		aout << ((lhs->lit) ? ("\t li $" + std::to_string(lhsReg) + ", " + std::to_string(lhs->getVal<int>())) : ("lw $") + std::to_string(lhsReg) + ", " + std::to_string(lhs->getVal<int>()) + "($fp)") << std::endl;
	}

	if (rhs->type == Expression::reg)
	{
		rhsReg = rhs->getVal<int>();
	}
	else
	{
		rhsReg = SymbolTable::getInstance()->getReg();
		aout << ((rhs->lit) ? ("\t li $" + std::to_string(rhsReg) + ", " + std::to_string(rhs->getVal<int>())) : ("lw $") + std::to_string(rhsReg) + ", " + std::to_string(rhs->getVal<int>()) + "($fp)") << std::endl;
	}
}

void writeFunc1(std::string op, int dest, int lhsReg, int rhsReg)
{
	aout <<"\t" << op << " $" << dest <<", $"<< lhsReg << ", $" << rhsReg << std::endl;
}

/*Read/Write Functions*/
void readStmt(std::vector<Expression> eList)
{
	std::cout<<"read stmt is being called"<<std::endl;
	std::for_each(eList.begin(), eList.end(), [&](Expression expr)
	{
      if(expr.str){
        aout <<"\t li $v0, 12"<<std::endl;
		aout <<"\t syscall"<<std::endl;
		aout <<"\t sw $v0, "<<expr.getVal<int>()<<"($fp)"<<std::endl;
      }
      else{
        aout <<"\t li $v0, 5"<<std::endl;
		aout <<"\t syscall"<<std::endl;
		aout <<"\t sw $v0, "<<expr.getVal<int>()<<"($fp)"<<std::endl;
      }
    });
}

void writeStmt(std::vector<Expression> eList)
{
	 std::for_each(eList.begin(), eList.end(), [&](Expression expr)
	 {
		 if(expr.type==Expression::charType)
		 {
			 aout<<"\t li $a0, "<< expr.getVal<int>()<<std::endl;
			 aout <<"\t li $v0, 11"<< std::endl;//there is an error here
		 }
		  if(expr.type==Expression::intType)
		 {
			 if(expr.lit)
			 {
				 aout <<"\t li $a0, "<< expr.getVal<int>()<<std::endl;
				 aout <<"\t li $v0, 1"<< std::endl;
			 }
			 else if(expr.str)
			 {
				 aout <<"lw $a0, "<< expr.getVal<int>()<<"($fp)"<<std::endl;
				 aout <<"li $v0, 11"<< std::endl;
			 }
			 else
			 {
				 aout << "lw $a0, "<< expr.getVal<int>()<<"($fp)"<<std::endl;
				 aout <<"li $v0, 1"<< std::endl;
			 }
		 }
		  if(expr.type==Expression::stringType)
		 {
			 aout <<"la $a0,"<< expr.getVal<std::string>()<<std::endl;
			 aout <<"li $v0, 4"<< std::endl;
		 }
		  if(expr.type==Expression::reg)
		 {
			 aout <<"move $a0, $"<< expr.getVal<int>()<<std::endl;
			 aout <<"li $v0, 1"<< std::endl;
		 }
		 aout<<"syscall"<<std::endl;
	 });
}


/*Expression Functions*/
Expression* AndExpr(Expression * lhs, Expression * rhs)
{
	std::cout<<"AND EXpression"<<std::endl;
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<bool>() && rhs->getVal<bool>(), Expression::boolType, true);
	}
	int lhsReg, rhsReg, dest;
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	writeFunc1("and", dest, lhsReg, rhsReg);
	return new Expression(dest, Expression::reg);
}
Expression* DivExpr(Expression * lhs, Expression * rhs)
{
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<int>() / rhs->getVal<int>(), Expression::intType, true);
	}
	int lhsReg, rhsReg, dest;
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	writeFunc1("div", dest, lhsReg, rhsReg);
	return new Expression(dest, Expression::reg);
}
Expression* EqExpr(Expression * lhs, Expression * rhs)
{
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<int>() == rhs->getVal<int>(), Expression::boolType, true);
	}
	int lhsReg, rhsReg, dest;
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	writeFunc1("seq", dest, lhsReg, rhsReg);
	return new Expression(dest, Expression::reg);
}
Expression* GteExpr(Expression * lhs, Expression * rhs)
{
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<int>() >= rhs->getVal<int>(), Expression::boolType, true);
	}
	int lhsReg, rhsReg, dest;
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	writeFunc1("sge", dest, lhsReg, rhsReg);
	return new Expression(dest, Expression::reg);
}
Expression* GtExpr(Expression * lhs, Expression * rhs)
{
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<int>() > rhs->getVal<int>(), Expression::boolType, true);
	}
	int lhsReg, rhsReg, dest;
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	writeFunc1("sgt", dest, lhsReg, rhsReg);
	return new Expression(dest, Expression::reg);
}
Expression* LteExpr(Expression * lhs, Expression * rhs)
{
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<int>() * rhs->getVal<int>(), Expression::boolType, true);
	}
	int lhsReg, rhsReg, dest;
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	writeFunc1("sle", dest, lhsReg, rhsReg);
	return new Expression(dest, Expression::reg);
}
Expression* LtExpr(Expression * lhs, Expression * rhs)
{
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<int>() < rhs->getVal<int>(), Expression::boolType, true);
	}
	int lhsReg, rhsReg, dest;
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	writeFunc1("slt", dest, lhsReg, rhsReg);
	return new Expression(dest, Expression::reg);
}
Expression* SubExpr(Expression * lhs, Expression * rhs)
{
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<int>() - rhs->getVal<int>(), Expression::intType, true);
	}
	int lhsReg, rhsReg, dest;
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	writeFunc1("sub", dest, lhsReg, rhsReg);
	return new Expression(dest, Expression::reg);
}
Expression* ModExpr(Expression * lhs, Expression * rhs)
{
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<int>() % rhs->getVal<int>(), Expression::intType, true);
	}
	int lhsReg, rhsReg, dest;
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	aout <<"div $"<<lhsReg<<" ,$"<<rhsReg<<std::endl;
	aout <<"mfhi $"<<lhsReg<<std::endl;
	return new Expression(lhsReg, Expression::reg);
}
Expression* MultExpr(Expression * lhs, Expression * rhs)
{
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<int>() * rhs->getVal<int>(), Expression::intType, true);
	}
	int lhsReg, rhsReg, dest;
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	//writeFunc1("mult", dest, lhsReg, rhsReg);
}
Expression* NeqExpr(Expression * lhs, Expression * rhs)
{
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<int>() != rhs->getVal<int>(), Expression::boolType, true);
	}
	int lhsReg, rhsReg, dest;
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	writeFunc1("sne", dest, lhsReg, rhsReg);
	return new Expression(dest, Expression::reg);
}
Expression* OrExpr(Expression * lhs, Expression * rhs)
{
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<bool>() || rhs->getVal<bool>(), Expression::boolType, true);
	}
	int lhsReg, rhsReg, dest;
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	writeFunc1("or", dest, lhsReg, rhsReg);
	return new Expression(dest, Expression::reg);
}
Expression* AddExpr(Expression * lhs, Expression * rhs)
{
	std::cout<<"inside plus"<<std::endl;
	if (lhs->lit && rhs->lit)
	{
		return new Expression(lhs->getVal<int>() + rhs->getVal<int>(), Expression::intType, true);
	}
	int lhsReg, rhsReg, dest;
	
	loadIntoRegister(dest, lhsReg, rhsReg, lhs, rhs);
	writeFunc1("add", dest, lhsReg, rhsReg);
	return new Expression(dest, Expression::reg);
}

Expression* IntExpr(int intVal)
{
	std::cout<<"returning a int expression"<<std::endl;
	return new Expression(intVal, Expression::intType,true);
}
Expression* CharExpr(char *strVal)
{
	std::cout<<"inside char expr"<<std::endl;
	return new Expression(strVal[1], Expression::charType, true);
}
Expression* StrExpr(char *strVal)
{
	if(SymbolTable::getInstance()->lookup(std::string(strVal)))
	{
		auto temp = *(dynamic_cast<Constant*>(SymbolTable::getInstance()->getSymbol(strVal).get()));
		return new Expression(temp.location,Expression::stringType,true);
	}
	else
	{
		auto temp = new Constant(std::string(strVal),std::string(strVal));
		SymbolTable::getInstance()->addSymbol(std::string(strVal), *temp,true);
		return new Expression(temp->location,Expression::stringType,true);
	}
}

Expression* genLValue(std::vector<Expression> exprList)
{
	
	std::cout<<"inside genLValue function"<<std::endl;
	auto tempVar = (dynamic_cast<Var*>(SymbolTable::getInstance()->getSymbol(exprList[0].getVal<std::string>()).get()));
	std::cout<<"after tempVar"<<std::endl;

	//get a dynamic ptr to the symbol table, get symbol from expression list, and its values there
	if(!tempVar)
	{
		yyerror("Error Casting Var");
	}

	

	int rootLoc = tempVar->location;
	int lastLower;

	auto lastType=dynamic_cast<Type*>(SymbolTable::getInstance()->getSymbol(tempVar->type->name).get());//look up symbol by name

	if(exprList.size()>1)
	{
		bool rootInt = true;
		int locReg = SymbolTable::getInstance()->getReg();
		int tempReg = SymbolTable::getInstance()->getReg();
		int tempRegMult = SymbolTable::getInstance()->getReg();
		
		aout <<"move $"<<locReg<<", $zero"<<std::endl;
		
		for(int i=1;i<exprList.size();++i)
		{
			if(lastType->typeType==Type::array)//if its an array
			{
				lastLower = (dynamic_cast<Array_Type*>(SymbolTable::getInstance()->getSymbol(lastType->name).get()))->lower;
				lastType = dynamic_cast<Type*>(dynamic_cast<Array_Type*>(SymbolTable::getInstance()->getSymbol(lastType->name).get())->type.get());
			}

			if(exprList[i].type==Expression::intType)
			{
				if(exprList[i].lit)//if its a literal
				{
					rootLoc+=((exprList[i].getVal<int>()-lastLower)*lastType->size);//shouldnt size alwasys be 4
				}
				else
				{
					//need to load register
					aout <<"lw $"<<tempReg<<", " <<exprList[i].getVal<int>()<<"($fp)"<<std::endl;
					aout <<"addi $"<<tempReg<<", $"<<tempReg<<", "<<(-lastLower)<<std::endl;
					aout << "li $"<<tempRegMult<<", $"<<tempRegMult<<std::endl;
					aout << "mult $"<<tempReg<<", $"<<tempRegMult<<std::endl;
					aout << "mflo $"<<tempReg<<std::endl;
					aout <<"add $"<<locReg<<", $"<<tempReg<<std::endl;
				}
			}
			else if(exprList[i].type==Expression::stringType)
			{
				auto tempRec = (dynamic_cast<Record*>(lastType));
				if(tempRec->layout.find(exprList[i].getVal<std::string>())==tempRec->layout.end());
				{
					yyerror("Invalid lvalue expr");
				}
				auto mem=tempRec->layout.at(exprList[i].getVal<std::string>());
				rootLoc +=mem.second;
				lastType = dynamic_cast<Type*>(SymbolTable::getInstance()->getSymbol(mem.first->name).get());
			}
			else
			{
				yyerror("invalid Lvalue expr");
			}
		}	
	}

	auto simpTemp = (dynamic_cast<Simple*>(SymbolTable::getInstance()->getSymbol(lastType->name).get()));
	if(!simpTemp)
	{
		auto what = dynamic_cast<Array_Type*>(SymbolTable::getInstance()->getSymbol(lastType->name).get());
		simpTemp = (dynamic_cast<Simple*>(SymbolTable::getInstance()->getSymbol(what->type->name).get()));
	}
	
	return new Expression(rootLoc, Expression::intType, false,(simpTemp->simType==Simple::character||simpTemp->simType==Simple::string),true);
	
}

bool checkType(Constant &input, Constant::ConstType type)
{
	if(input.type==Constant::identType)
	{
		input = *(dynamic_cast<Constant*>(SymbolTable::getInstance()->getSymbol(input.name).get()));
	}
	return input.type=type;
}

bool isSameType(Constant &lhs, Constant &rhs)
{
	if(lhs.type==Constant::identType)
	{
		lhs =*(dynamic_cast<Constant*>(SymbolTable::getInstance()->getSymbol(lhs.name).get()));
	}
	
	if(rhs.type==Constant::identType)
	{
		rhs =*(dynamic_cast<Constant*>(SymbolTable::getInstance()->getSymbol(rhs.name).get()));
	}
	return lhs.type==rhs.type;
}


Constant* ConstAndExpr(Constant lhs, Constant rhs)
{
	if(!isSameType(lhs,rhs))
	{
		yyerror("Operands are not same type");
	}
	
	if(lhs.type == Constant::boolType)
	{
		return new Constant(lhs.boolVal&&rhs.boolVal);
	}
	else
	{
		yyerror("Invalid operator on Const");
	}
}
Constant* ConstDivExpr(Constant lhs, Constant rhs)
{
	if((lhs.type!=Constant::intType)||(!isSameType(lhs,rhs)))
	{
		yyerror("Invalid operator on Const");
	}
	return new Constant(lhs.numVal/rhs.numVal);
}
Constant* ConstEqExpr(Constant lhs, Constant rhs)
{
	if(!isSameType(lhs,rhs))
	{
		yyerror("Operands are different types");
	}
	
	if(lhs.type == Constant::intType)
	{
		return new Constant(lhs.numVal==rhs.numVal);
	}else if(lhs.type ==  Constant::charType)
	{
		return new Constant(lhs.charVal==rhs.charVal);
	}else if(lhs.type == Constant::stringType)
	{
		return new Constant(lhs.strVal==rhs.strVal);
	}
}
Constant* ConstGteExpr(Constant lhs, Constant rhs)
{
	if(!isSameType(lhs,rhs))
	{
		yyerror("Operands are different types");
	}
	
	if(lhs.type == Constant::intType)
	{
		return new Constant(lhs.numVal>=rhs.numVal);
	}else if(lhs.type ==  Constant::charType)
	{
		return new Constant(lhs.charVal>=rhs.charVal);
	}else if(lhs.type == Constant::stringType)
	{
		return new Constant(lhs.strVal>=rhs.strVal);
	}
}
Constant* ConstGtExpr(Constant lhs, Constant rhs)
{
	if(!isSameType(lhs,rhs))
	{
		yyerror("Operands are different types");
	}
	
	if(lhs.type == Constant::intType)
	{
		return new Constant(lhs.numVal>rhs.numVal);
	}else if(lhs.type ==  Constant::charType)
	{
		return new Constant(lhs.charVal>rhs.charVal);
	}else if(lhs.type == Constant::stringType)
	{
		return new Constant(lhs.strVal>rhs.strVal);
	}
}
Constant* ConstLteExpr(Constant lhs, Constant rhs)
{
	if(!isSameType(lhs,rhs))
	{
		yyerror("Operands are different types");
	}
	
	if(lhs.type == Constant::intType)
	{
		return new Constant(lhs.numVal<=rhs.numVal);
	}else if(lhs.type ==  Constant::charType)
	{
		return new Constant(lhs.charVal<=rhs.charVal);
	}else if(lhs.type == Constant::stringType)
	{
		return new Constant(lhs.strVal<=rhs.strVal);
	}
}
Constant* ConstLtExpr(Constant lhs, Constant rhs)
{
	if(!isSameType(lhs,rhs))
	{
		yyerror("Operands are different types");
	}
	
	if(lhs.type == Constant::intType)
	{
		return new Constant(lhs.numVal<rhs.numVal);
	}else if(lhs.type ==  Constant::charType)
	{
		return new Constant(lhs.charVal<rhs.charVal);
	}else if(lhs.type == Constant::stringType)
	{
		return new Constant(lhs.strVal<rhs.strVal);
	}
}
Constant* ConstSubExpr(Constant lhs, Constant rhs)
{
	if((lhs.type!=Constant::intType)||(!isSameType(lhs,rhs)))
	{
		yyerror("Invalid operator on Const");
	}
	return new Constant(lhs.numVal-rhs.numVal);
}
Constant* ConstModExpr(Constant lhs, Constant rhs)
{
	if((lhs.type!=Constant::intType)||(!isSameType(lhs,rhs)))
	{
		yyerror("Invalid operator on Const");
	}
	return new Constant(lhs.numVal%rhs.numVal);
}
Constant* ConstMultExpr(Constant lhs, Constant rhs)
{
	if((lhs.type!=Constant::intType)||(!isSameType(lhs,rhs)))
	{
		yyerror("Invalid operator on Const");
	}
	return new Constant(lhs.numVal*rhs.numVal);
}
Constant* ConstNeqExpr(Constant lhs, Constant rhs)
{
	if(!isSameType(lhs,rhs))
	{
		yyerror("Operands are different types");
	}
	
	if(lhs.type == Constant::intType)
	{
		return new Constant(lhs.numVal!=rhs.numVal);
	}else if(lhs.type ==  Constant::charType)
	{
		return new Constant(lhs.charVal!=rhs.charVal);
	}else if(lhs.type == Constant::stringType)
	{
		return new Constant(lhs.strVal!=rhs.strVal);
	}
}
Constant* ConstOrExpr(Constant lhs, Constant rhs)
{
	if(!isSameType(lhs,rhs))
	{
		yyerror("Operands are not same type");
	}
	
	if(lhs.type == Constant::boolType)
	{
		return new Constant(lhs.boolVal||rhs.boolVal);
	}
	else
	{
		yyerror("Invalid operator on Const");
	}
}
Constant* ConstAddExpr(Constant lhs, Constant rhs)
{
	if((lhs.type!=Constant::intType)||(!isSameType(lhs,rhs)))
	{
		yyerror("Invalid operator on Const");
	}
	return new Constant(lhs.numVal+rhs.numVal);
}

Constant* ConstNotExpr(Constant in)
{
	if(!checkType(in,Constant::boolType))
	{
		yyerror("Invalid Operator on const expr");
	}
	return new Constant(!in.boolVal);
}

Constant* ConstUminusExpr(Constant in)
{
	if(!checkType(in,Constant::intType))
	{
		yyerror("Invalid Operator on const expr");
	}
	return new Constant(-in.intType);
}

