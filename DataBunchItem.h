// DataBunchItem.h

#pragma once


class DataFeedingItemInfo;

class DataBunchItem{
public:

	DataBunchItem();
	DataBunchItem(int itemID, DataFeedingItemInfo* m_pData=0);
	DataBunchItem(const DataBunchItem& source);
	~DataBunchItem();

	bool IsEqual(const DataBunchItem& other);
	bool IsNotEqual(const DataBunchItem& other);

	DataBunchItem& operator=(const DataBunchItem& source);
	bool operator==(const DataBunchItem& other);
	bool operator!=(const DataBunchItem& other);

	int GetItemID() const;


public:
	DataFeedingItemInfo* m_pData;

private:
	int itemID;
};

inline int DataBunchItem::GetItemID() const{
	return this->itemID;
}