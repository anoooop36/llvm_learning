#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/Support/raw_ostream.h"


using namespace llvm;

namespace
{
	struct CountOpcode:public FunctionPass
	{
		std::map<std::string,int> opcodecounter;
		static char ID;
		CountOpcode():FunctionPass(ID){}

		virtual bool runOnFunction(Function &F)
		{
			errs()<<"Anoop "<<F.getName()<<"\n";

			for(Function::iterator bb=F.begin();bb!=F.end();bb++){
				for(BasicBlock::iterator i=bb->begin();i!=bb->end();i++){
				errs()<<*i<<"\n";				
				}
			errs()<<"\n\n\n";			
			}

			
			return false;
		}
	};
}

char CountOpcode::ID = 0;
static RegisterPass<CountOpcode> X("opcount","count the number of opcode",false,false);
