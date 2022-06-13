#include <iostream>

struct Node
{
	int m_iData;
	Node *m_ptrNext = nullptr;

	Node(int iValue) : m_iData(iValue){} //Initializer list. This is used because for parameterized constructor
	//assignment operator call is avoided. Thus saving one operation.
	/*{
		iData = iValue;
	}*/
};

class SortedLinkedList
{
	Node *m_ptrHead = nullptr;
	Node *m_ptrNavigator = nullptr;
public:
	void Add(const int iValue);
	void Insert(Node *ptrNode);
	void Print();
};

void SortedLinkedList::Insert(Node *ptrNode)
{
	ptrNode->m_ptrNext = m_ptrNavigator->m_ptrNext;
	m_ptrNavigator->m_ptrNext = ptrNode;
}

void SortedLinkedList::Add(const int iValue)
{
	if (nullptr == m_ptrHead)
	{
		m_ptrHead = new Node(iValue);
		m_ptrNavigator = m_ptrHead;
	}
	else
	{
		Node *ptrTemp = new Node(iValue);

		if (iValue > m_ptrNavigator->m_iData)
		{
			if (nullptr == m_ptrNavigator->m_ptrNext)
				m_ptrNavigator->m_ptrNext = ptrTemp;
			else
			{
				if (iValue > m_ptrNavigator->m_ptrNext->m_iData)
				{
					m_ptrNavigator = m_ptrNavigator->m_ptrNext;
					Add(iValue);
				}
				else
				{
					//insert
					Insert(ptrTemp);
				}
			}
		}
		else if(iValue < m_ptrHead->m_iData)
		{
			ptrTemp->m_ptrNext = m_ptrHead;
			m_ptrNavigator = m_ptrHead = ptrTemp;
		}
	}
}

void SortedLinkedList::Print()
{
	if (m_ptrHead)
	{
		while (m_ptrHead)
		{
			std::cout << " " << m_ptrHead->m_iData << std::endl;
			m_ptrHead = m_ptrHead->m_ptrNext;
		}
	}
}

int main()
{
	int iSizeLL = 0;
	std::cout << "Enter number of nodes in Linked list - \n";
	std::cin >> iSizeLL;
	SortedLinkedList objSLL;
	for (int i = 0; i < iSizeLL; i++)
	{
		int iValue = 0;
		std::cin >> iValue;
		objSLL.Add(iValue);
	}
	objSLL.Print();
}