// FileWriter.cpp

#include "FileWriter.h"
#include <atltime.h>
#include <boost/filesystem.hpp>
#include <iomanip>
#include <direct.h>

FileWriter::FileWriter(DataBunch* pDataBunch){
	this->p_mDataBunch = pDataBunch;
}


FileWriter::FileWriter(const FileWriter& source){
	this->writer.copyfmt(source.writer);
}


FileWriter::~FileWriter(){
	this->writer.clear();
	this->writer.close();
}


bool FileWriter::CreateDir(const tstring directoryName){
	
	bool ret =false;

	tstring basePath(("C:/DATA/"));

	tstring fullPath = basePath+directoryName;

	//int created = _tmkdir(fullPath.c_str());


	boost::filesystem::path dir(fullPath);

	bool existing = boost::filesystem::exists(dir);
	if(existing == false){
		bool created = boost::filesystem::create_directories(dir);
	}


	std::time_t time = std::time(nullptr);
	std::tm* tm = std::localtime(&time);

	tostringstream ss;
	ss << std::put_time(tm, _T("%Y%m%d"));
	tstring date(ss.str());

	tstring filePath = fullPath + _T("/") + date + _T(".txt");

	this->writer.open(filePath, std::ios_base::out | std::ios_base::app);
	ret = true;

	return ret;
}



void FileWriter::Write(tchar* trCode, void* data, size_t size){
	this->writer << trCode << _T(' ');
	this->writer.write(reinterpret_cast<tchar*>(data), size);
	this->writer << endl;
}




bool FileWriter::IsEqual(const FileWriter& other){
	bool ret = false;
	if(this->writer == other.writer){
		ret = true;
	}
	return ret;
}


bool FileWriter::IsNotEqual(const FileWriter& other){
	bool ret = false;
	if(this->writer!=other.writer){
		ret = true;
	}
	return ret;
}


FileWriter& FileWriter::operator=(const FileWriter& source){
	this->writer.copyfmt(source.writer);
	return *this;
}


bool FileWriter::operator==(const FileWriter& other){
	bool ret = false;
	if(this->writer == other.writer){
		ret = true;
	}
	return ret;
}


bool FileWriter::operator!=(const FileWriter& other){
	bool ret = false;
	if(this->writer!=other.writer){
		ret = true;
	}
	return ret;
}