#include <iostream>
#include "uscxml/uscxml.h"
#include "uscxml/Interpreter.h"
#include "uscxml/plugins/DataModelImpl.h"
#include "uscxml/plugins/DataModel.h"


int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Expected URL with SCXML document as first argument" << std::endl;
		return -1;
	}

	uscxml::Interpreter sc = uscxml::Interpreter::fromURL(argv[1]);
	uscxml::InterpreterState state;
    uscxml::StateTransitionMonitor stm;
    sc.addMonitor(&stm);

//    uscxml::ActionLanguage al;
  //  sc.setActionLanguage(al);




    while ((state = sc.step()) != uscxml::USCXML_FINISHED)
    {
        uscxml::DataModel dm = sc.getActionLanguage()->dataModel;

        std::cout << dm.evalAsData("foreachArray1") << std::endl;

	}

	return 0;
}
