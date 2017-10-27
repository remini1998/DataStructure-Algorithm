#include <iostream>
#include "interface-josephus-circle.h"
#include "josephus-circle-array.h"
#include "josephus-circle-chain.h"

void testArry()
{
	while (true) {
		try {
			int n, s, m;
			std::cout << "Plz input n, s, m: ";
			std::cin >> n;
			if (n == 0) return;
			std::cin >> s >> m;
			IJosephusCircle* jc = new JosephusCircleArray(n);
			jc->setNow(s);
			while (jc->next(m) != -1) {
				jc->print();
			}
			std::cout << "END£¡" << std::endl;
		}
		catch (char* e) {
			std::cout << "AN EXCEPTION CAUGHT:" << e << std::endl;
			throw e;
		}
	}
}

void testChain()
{
	while (true) {
		try {
			int n, s, m;
			std::cout << "Plz input n, s, m: ";
			std::cin >> n;
			if (n == 0) return;
			std::cin >> s >> m;
			IJosephusCircle* jc = new JosephusCircleChain(n);
			//std::cout << jc->getLength() << std::endl;
			jc->setNow(s);
			while (JosephusCircleChain::now->next(m) != -1) {
				JosephusCircleChain::now->print();
			}
			std::cout << "END£¡" << std::endl;
		}
		catch (char* e) {
			std::cout << "AN EXCEPTION CAUGHT:" << e << std::endl;
			throw e;
		}
	}
}

int main() {
	//testArry();
	testChain();
	return 0;
}