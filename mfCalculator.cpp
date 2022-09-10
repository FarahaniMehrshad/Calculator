#include "mfCalculator.h"
#include <iostream>

mf::Calculator::Calculator() {}

void mf::Calculator::calculate(const std::string& command)
{
	m_command = command;
	isValid(m_command);

	delete m_postfix;
	m_answer = 0.0;
	m_steps = "";

	m_postfix = convertToPostfix(m_command);
	m_answer = evaluatePostfix(m_postfix);
}

double mf::Calculator::getAnswer() const
{
	return m_answer;
}

std::string mf::Calculator::getAnswerString() const
{
	return removeTrailer(std::to_string(m_answer));
}

std::string mf::Calculator::getSteps() const
{
	return m_steps;
}

const mf::LinkedList<std::string>* mf::Calculator::getPostfix() const
{
	return m_postfix;
}


mf::Calculator::~Calculator()
{
	delete m_postfix;
}

void mf::Calculator::isValid(const std::string& command) const
{
	mf::Stack<char> stack;
	for (int i = 0; i < command.length(); ++i)
	{
		if (i == 0)
		{
			if (command[i] != '-' && command[i] != '(' && isOperator(command[i]))
			{
				throw "Error:beginning";
			}

			if (command[i] == ')')
			{
				throw "Error:beginning";
			}

		}

		if (i == command.length() - 1)
		{
			if (command[i] != ')' && isOperator(command[i]))
			{
				throw "Error:end";
			}
		}

		if (command[i] == '(' && command[i + 1] == ')')
		{
			throw "Error:empty ()";
		}

		if (isOperator(command[i]) && isOperator(command[i + 1]))
		{
			std::string valid[] = { "(-", "((", "--" };
			if (command[i] != ')' && command[i + 1] != '-' && command[i + 1] != '(')
			{
				bool isValid = false;
				std::string temp = std::to_string(command[i]) + std::to_string(command[i + 1]);
				for (std::string cur : valid)
				{
					if (temp == cur)
					{
						isValid == true;
					}
				}

				if (!isValid) throw "Error:two operators";
			}
		}

		if (command[i] == '(')
		{
			stack.push('(');
		}

		if (command[i] == ')')
		{
			if (stack.getTop() != '(')
			{
				throw "Error:parantheses";
			}

			stack.pop();
		}
	}

	if (!stack.isEmpty())
	{
		throw "Error:parantheses";
	}
}

const mf::LinkedList<std::string>* mf::Calculator::convertToPostfix(const std::string& command)
{
	mf::LinkedList<std::string>* postfix = new mf::LinkedList<std::string>();
	mf::Stack<char> operators;

	std::string number = "";
	bool isDecimal = false;

	for (int i = 0; i < command.length(); ++i)
	{
		if (!isOperator(command[i]))
		{
			if (command[i] == '.')
			{
				if (!isDecimal)
				{
					isDecimal = true;
				}
				else
				{
					throw "Error:decimal number";
				}
			}
			number += command[i];
			continue;
		}

		// If Reached an operator, add leftover number to list
		if (number != "")
		{
			postfix->pushBack(number);
			number = "";
			isDecimal = false;
		}

		// Operators
		switch (command[i])
		{
		case '(':

			// (2)(3) = 6
			if (i != 0 && (!isOperator(command[i - 1]) || command[i - 1] == ')'))
			{
				while (!operators.isEmpty() && !precedence('*', operators.getTop()))
				{
					postfix->pushBack(std::string(1, operators.getTop()));
					operators.pop();
				}
				operators.push('*');
			}

			operators.push('(');
			break;

		case ')':

			while (true)
			{
				if (operators.getTop() == '(')
				{
					operators.pop();
					break;
				}
				postfix->pushBack(std::string(1, operators.getTop()));
				operators.pop();
			}
			break;

		case '-':
			if (i == 0 || (isOperator(command[i - 1]) && command[i - 1] != ')'))
			{
				postfix->pushBack("0");
				operators.push('-');
				break;
			}

		default:
			if (operators.isEmpty())
			{
				operators.push(command[i]);
				break;
			}

			while (!operators.isEmpty() && !precedence(command[i], operators.getTop()))
			{
				postfix->pushBack(std::string(1, operators.getTop()));
				operators.pop();
			}

			operators.push(command[i]);
			break;
		}
	}

	// Add leftover numbers and operators at the end of command to list.
	if (number != "")
	{
		postfix->pushBack(number);
		number = "";
	}

	while (!operators.isEmpty())
	{
		postfix->pushBack(std::string(1, operators.getTop()));
		operators.pop();
	}

	return postfix;
}

double mf::Calculator::evaluatePostfix(const mf::LinkedList<std::string>* postfix)
{
	mf::Stack<double> stack;
	int index = 0;

	for (auto node = postfix->getHead(); node != nullptr; node = node->getNext())
	{
		std::string cur = node->getData();
		double a;
		double b;

		if (isOperator(cur[0]))
		{
			b = stack.getTop();
			stack.pop();
			a = stack.getTop();
			stack.pop();

			switch (cur[0])
			{
			case '^':
				if (a < 0)
				{
					if (b < 1)
					{
						if ((1 / b) - int(1 / b) < 0.00000001)
						{
							if (int(1 / b) % 2 == 0)
							{
								throw "Error:imaginary number";
							}
						}
						double temp = pow(-a, b);
						stack.push(-temp);
					}
					else
					{
						stack.push(pow(a, b));
					}
				}
				else
				{
					stack.push(pow(a, b));
				}
				break;

			case '*': stack.push(a * b); break;

			case '/':
				if (b == 0) throw "Error:division by 0";
				stack.push(a / b);
				break;

			case '+': stack.push(a + b); break;

			case '-': stack.push(a - b); break;
			}

			if (a != 0 && cur[0] != '-') // Do not add step when calculating negative number
			{
				// evaluate step
				addStep(postfix, stack, index);
			}
		}
		else // Number
		{
			stack.push(std::stod(cur));
		}

		++index;
	}

	return stack.getTop();
}

void mf::Calculator::addStep(const mf::LinkedList<std::string> * postfix, mf::Stack<double> stack, int index)
{
	mf::LinkedList<std::string> steps;

	// Copy old stack to new one
	while (!stack.isEmpty())
	{
		double value = stack.getTop();
		if (int(value) == value)
		{
			steps.pushBack(removeTrailer(std::to_string(int(value))));
		}
		else
		{
			steps.pushBack(removeTrailer(std::to_string(value)));
		}
		stack.pop();
	}

	int i = 0;
	for (auto node = postfix->getHead(); node != nullptr; node = node->getNext())
	{
		if (i <= index)
		{
			++i;
			continue;
		}

		std::string cur = node->getData();
		std::string a;
		std::string b;


		if (isOperator(cur[0]))
		{
			b = steps.getHead()->getData();
			steps.popFront();
			a = steps.getHead()->getData();
			steps.popFront();

			if (a == "0" && cur[0] == '-') // negative number
			{
				if (b[0] == '-')
				{
					b.erase(0, 1); 
					steps.pushFront(b);
				}
				else
				{
					steps.pushFront('-' + b);
				}
				continue;
			}

			if (node == postfix->getTail())
			{
				steps.pushFront(a + cur[0] + b);
			}
			else
			{
				steps.pushFront('(' + a + cur[0] + b + ')');
			}
		}
		else // Number
		{
			steps.pushFront(cur);
		}
	}

	m_steps += steps.getHead()->getData() + '\n';
}

bool mf::Calculator::precedence(char a, char b) const
{
	int nOperators = 7;
	char operators[] = { '^', '_', '*', '/', '+', '-' };
	int precedence[] = { 6,   5,   4,   4,   3,   3 };

	int aIndex = -1;
	int bIndex = -1;

	for (int i = 0; i < nOperators; ++i)
	{
		if (operators[i] == a)
		{
			aIndex = i;
		}

		if (operators[i] == b)
		{
			bIndex = i;
		}
	}

	if (precedence[aIndex] > precedence[bIndex])
	{
		return true;
	}

	if (operators[aIndex] == '^' && operators[bIndex] == '^')
	{
		return true;
	}

	return false;

}

bool mf::Calculator::isOperator(char a) const
{
	switch (a)
	{
	case '^':
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
		return true;
	}

	return false;
}

std::string mf::Calculator::removeTrailer(std::string number) const
{
	if (number.find('.') == std::string::npos)
	{
		return number;
	}

	while (true)
	{
		if (number[number.length() - 1] == '0')
		{
			number.resize(number.length() - 1);
		}
		else
		{
			break;
		}

		if (number[number.length() - 1] == '.')
		{
			number.resize(number.length() - 1);
			break;
		}
	}

	return number;
}