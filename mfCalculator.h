#ifndef MF_CALCULATORPRO_H
#define MF_CALCULATORPRO_H

#include <string>
#include <math.h>
#include "mfLinkedList.h"
#include "mfStack.h"

namespace mf
{

	class Calculator
	{
	public:
		Calculator();

		void calculate(const std::string& command);

		double getAnswer() const;

		std::string getAnswerString() const;

		std::string getSteps() const;

		const mf::LinkedList<std::string>* getPostfix() const;

		~Calculator();

	private:
		void isValid(const std::string& command) const;

		const mf::LinkedList<std::string>* convertToPostfix(const std::string& command);

		double evaluatePostfix(const mf::LinkedList<std::string>* postfix);

		void addStep(const mf::LinkedList<std::string>* postfix
			, mf::Stack<double> stack
			, int index);

		bool precedence(char a, char b) const;

		bool isOperator(char a) const;

		std::string removeTrailer(std::string number) const;

	private:
		std::string m_command;

		const mf::LinkedList<std::string>* m_postfix = nullptr;

		double m_answer = 0.0;

		std::string m_steps;

	};
}


#endif // MF_CALCULATORPRO_H
