// Ask.h

#pragma once


class Ask{
	public:
		Ask();
		Ask(const Ask& source);
		~Ask();

		void Update(double price, int quantity, int count);

		bool IsEqual(const Ask& other);
		bool IsNotEqual(const Ask& other);

		Ask& operator=(const Ask& source);
		bool operator==(const Ask& other);
		bool operator!=(const Ask& other);

		double GetPrice() const;
		int GetQuantity() const;
		int GetCount() const;
	private:
		double price;
		int quantity; //
		int count;	  // 
};

inline double Ask::GetPrice() const{
	return this->price;
}

inline int Ask::GetQuantity() const{
	return this->quantity;
}

inline int Ask::GetCount() const{
	return this->count;
}