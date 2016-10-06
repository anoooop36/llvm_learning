#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"


using namespace llvm;

namespace
{
	struct CountOpcode:public FunctionPass
	{
		static char ID;
		CountOpcode():FunctionPass(ID){}

		virtual bool runOnFunction(Function &F)
		{
			errs()<<"Anoop "<<F.getName()<<"\n";

			for(Function::iterator bb=F.begin();bb!=F.end();bb++){
				errs()<<"Basic block name- "<<bb->getName()<<"    count of instruction is- "<<bb->size()<<"\n";			
			}

			
			return false;
		}
	};
}

char CountOpcode::ID = 0;
static RegisterPass<CountOpcode> X("opcount","count the number of opcode",false,false);
