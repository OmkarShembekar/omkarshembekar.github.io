// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node
{
	int iData;
	Node *ptrNextAddr = nullptr;

	Node(int iValue)
	{
		iData = iValue;
	}
};

class LinkedList
{
	Node *m_ptrHead = nullptr;
	Node *m_ptrNext = nullptr;
public:
	void Add(const int iData);
	void Print();
};

void LinkedList::Add(const int iData)
{
	if (!m_ptrHead)
	{
		m_ptrHead = new Node(iData);
		m_ptrNext = m_ptrHead;
	}
	else
	{
		Node *ptrTemp = new Node(iData);
		if (!m_ptrNext->ptrNextAddr)
			m_ptrNext->ptrNextAddr = ptrTemp;
		else
		{
			m_ptrNext = m_ptrNext->ptrNextAddr;
			Add(iData);
		}
	}
}

void LinkedList::Print()
{
	if (m_ptrHead)
	{
		while (m_ptrHead)
		{
			std::cout << "-> " << m_ptrHead->iData << std::endl;

			if (m_ptrHead->ptrNextAddr)
				m_ptrHead = m_ptrHead->ptrNextAddr;
			else
				m_ptrHead = nullptr;
		}
	}
}

int main()
{
	int iSizeLL = 0;
    std::cout << "Enter size of linked list.\n";
	std::cin >> iSizeLL;
	LinkedList objLL;
	for (int i = 0; i < iSizeLL; i++)
	{
		int iValue = 0;
		std::cin >> iValue;
		objLL.Add(iValue);
	}
	objLL.Print();
}
