#pragma once
#ifndef MFSTACK_H
#define MFSTACK_H

namespace mf
{
	template <typename DataType>
	class StackNode
	{
		template <typename DataType2>
		friend class Stack;
	private:
		DataType value;
		StackNode<DataType>* next;

		StackNode(const DataType& value, StackNode<DataType>* next) : value(value), next(next)
		{}

	};

	template <typename DataType>
	class Stack
	{

	private:
		StackNode<DataType>* top = nullptr;
		int size = 0;

	public:

		Stack();

		Stack(const Stack<DataType>& source);

		void push(const DataType&);

		void pop();

		DataType& getTop() const;

		bool isEmpty() const;

		int getSize() const;

		~Stack();
	};

	template <typename DataType>
	Stack<DataType>::Stack()
	{
		top = nullptr;
		size = 0;
	}

	template <typename DataType>
	Stack<DataType>::Stack(const Stack<DataType>& source)
	{

		StackNode<DataType>* cur = source.top;

		Stack<DataType> temp;

		for (int i = 0; i < source.getSize(); ++i)
		{
			temp.push(cur->value);
			cur = cur->next;
		}

		while (!temp.isEmpty())
		{
			this->push(temp.getTop());
			temp.pop();
		}
	}

	template <typename DataType>
	void Stack<DataType>::push(const DataType& value)
	{
		StackNode<DataType>* temp = new StackNode<DataType>(value, top);
		top = temp;
		++size;
	}

	template <typename DataType>
	void Stack<DataType>::pop()
	{
		StackNode<DataType>* temp = top;
		top = top->next;
		delete temp;
		--size;
	}

	template <typename DataType>
	bool Stack<DataType>::isEmpty() const
	{
		return size == 0;
	}

	template <typename DataType>
	DataType& Stack<DataType>::getTop() const
	{
		if (isEmpty())
		{
			throw - 1;
		}
		return top->value;
	}

	template <typename DataType>
	int Stack<DataType>::getSize() const
	{
		return size;
	}

	template <typename DataType>
	Stack<DataType>::~Stack()
	{
		while (size != 0)
		{
			pop();
		}
	}
}


#endif //MFSTACK_H
