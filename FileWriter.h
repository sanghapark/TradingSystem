// FileWriter.h

#pragma once


#include "DataTypeDefinition.h"
#include <tchar.h>
#include <stdio.h>

class DataBunch;


// Save시 DataBunch당 하나 FileWriter
class FileWriter{

public:
	FileWriter(DataBunch* pDataBunch=0);
	FileWriter(const FileWriter& source);
	~FileWriter();

	bool CreateDir(const tstring directoryName);
	void Write(tchar* trCode, void* data, size_t size);
	// void Read();

	bool IsEqual(const FileWriter& other);
	bool IsNotEqual(const FileWriter& other);

	FileWriter& operator=(const FileWriter& source);
	bool operator==(const FileWriter& other);
	bool operator!=(const FileWriter& other);


	tofstream& GetWriter() const;

public:
	DataBunch* p_mDataBunch;

private:
	tofstream writer;
};


inline tofstream& FileWriter::GetWriter() const{
	return const_cast<tofstream&>(this->writer);
}

