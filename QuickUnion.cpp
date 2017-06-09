#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

class QuickUnion {

public:
	QuickUnion( int noOfObjects )
	: m_TotalObjects( noOfObjects )
	{
		_initializeObjectArray();
	}

	void Union( int objA, int objB ) {
		if ( objA < 0 or objB < 0 or
			 objA >= m_TotalObjects or objB >= m_TotalObjects or
			 objA == objB ) {
			cerr << "Invalid objects in union!" << endl;
			return;
		}
		m_Objects[objB] = m_Objects[objA];
	}

	bool isConnected( int objA, int objB ) {
		if ( objA < 0 or objB < 0 or
			 objA >= m_TotalObjects or objB >= m_TotalObjects ) {
			cerr << "Invalid objects in union!" << endl;
			exit(1);
		}
		try {
			return _getRoot( objA, objB ) == _getRoot( objB, objA );
		}
		catch( const string& found ) {
			return true;
		}
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

	int _getRoot( int obj, int find ) {

		while ( obj != m_Objects[obj] ) {
			obj = m_Objects[obj];

			if ( obj == find )
				throw( "Found" );
		}
		return obj;
	}

};
