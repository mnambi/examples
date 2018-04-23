#include <iostream>
#include <thread>
#include "uscxml/uscxml.h"
#include "uscxml/Interpreter.h"
#include "uscxml/plugins/DataModelImpl.h"
#include "uscxml/plugins/DataModel.h"


bool printHello()
{
    std::cout << "Hello world." << std::endl;
    return true;
}

void printMenu()
{
    std::cout << "--- Input Menu --- \n"
              << "Type event name" << std::endl
              << "Type 'q' to exit" << std::endl;

}

void run( uscxml::Interpreter& sc)
{
    uscxml::InterpreterState state;
    while ((state = sc.step()) != uscxml::USCXML_FINISHED)
    {
        // uscxml::DataModel dm = sc.getActionLanguage()->dataModel;

        // std::cout << dm.evalAsData("foo") << std::endl;

    }
}

void fn(const std::string& ssid, const std::string& state, const xercesc_3_1::DOMElement* st)
{
    std::cout << "In state: " << state << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Expected URL with SCXML document as first argument" << std::endl;
		return -1;
	}

	uscxml::Interpreter sc = uscxml::Interpreter::fromURL(argv[1]);
	uscxml::InterpreterState state;
    uscxml::StateTransitionMonitor stm;
    //sc.addMonitor(&stm);
    sc.on().enterState(fn);

    std::thread t(run, std::ref(sc));
    // uscxml::ActionLanguage al;
    // sc.setActionLanguage(al);

    std::string inputString;
    do
    {
        printMenu();
        std::getline(std::cin, inputString);
        std::cout << "Event called: " << inputString << std::endl;
        uscxml::Event e(inputString);
        sc.receive(e);

    } while(inputString != "q");





	return 0;
}
