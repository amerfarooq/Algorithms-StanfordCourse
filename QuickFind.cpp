#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

class UF {

public:
	UF( int noOfObjects )
	: m_TotalObjects( noOfObjects )
	{
		_initializeObjectArray();
	}

	void Union( int objA, int objB ) {
		// Verify objects are valid.
		if ( objA < 0 or objB < 0 or
			 objA >= m_TotalObjects or objB >= m_TotalObjects or
			 objA == objB ) {
			cerr << "Invalid objects in union!" << endl;
			return;
		}

		for( int i = 0; i < m_TotalObjects; ++i ) {
			if ( m_Objects[i] == m_Objects[objA] ) {
				m_Objects[i] = m_Objects[objB];
			}
		}
	}

	bool isConnected( int objA, int objB ) {
		if ( objA < 0 or objB < 0 or objA >= m_TotalObjects or objB >= m_TotalObjects ) {
			cerr << "Invalid objects in union!" << endl;
			exit(1);
		}
		return m_Objects[objA] == m_Objects[objB];
	}

	void print() {
		for ( int i = 0; i < m_TotalObjects; ++i ) {
			cout << m_Objects[i] << " ";
		}
	}

private:
	int m_TotalObjects;
	vector<int> m_Objects;

	void _initializeObjectArray() {
		for ( int i = 0; i < m_TotalObjects; ++i ) {
			m_Objects.push_back(i);
		}
	}
};




