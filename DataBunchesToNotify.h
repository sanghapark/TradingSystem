// DataBunchesToNotify.h

#include "Template/Array.hpp"

class DataBunch;

class DataBunchesToNotify{

public:
	DataBunchesToNotify(int capacity=5);
	DataBunchesToNotify(const DataBunchesToNotify& source);
	~DataBunchesToNotify();

	int AddDataBunchToNotify(DataBunch* pDataBunch);
	int FindDataBunchToNotify(DataBunch* pDataBunch);
	int DeleteDataBunchToNotify(int index);

	bool IsEqual(const DataBunchesToNotify& other);
	bool IsNotEqual(const DataBunchesToNotify& other);
	DataBunch* GetAt(int index);

	DataBunchesToNotify& operator=(const DataBunchesToNotify& source);
	bool operator==(const DataBunchesToNotify& other);
	bool operator!=(const DataBunchesToNotify& other);
	DataBunch* operator[](int index);

	int GetLength() const;
	int GetCapacity() const;

private:
	Array<DataBunch*> dataBunches;
	int length;
	int capacity;
};


inline int DataBunchesToNotify::GetLength() const{
	return this->length;
}

inline int DataBunchesToNotify::GetCapacity() const{
	return this->capacity;
}