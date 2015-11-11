// OptionValue.h

#pragma once

class OptionValue{
	public:
		OptionValue();
		OptionValue(double value, double intrinsicValue, double timeValue);
		OptionValue(const OptionValue& source);
		~OptionValue();

		bool IsEqual(const OptionValue& other);
		bool IsNotEqual(const OptionValue& other);

		OptionValue& operator=(const OptionValue& source);
		bool operator==(const OptionValue& other);
		bool operator!=(const OptionValue& other);

		double GetValue() const;
		double GetIntrinsicValue() const;
		double GetTimeValue() const;
	
	private:
		double value;
		double intrinsicValue;
		double timeValue;
};


inline double OptionValue::GetValue() const{
	return this->value;
}


inline double OptionValue::GetIntrinsicValue() const{
	return this->intrinsicValue;
}


inline double OptionValue::GetTimeValue() const{
	return this->timeValue;
}