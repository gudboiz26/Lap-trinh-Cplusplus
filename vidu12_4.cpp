//Chương trình này cho ra KẾT QUẢ ĐÚNG.
	#include <iostream>
	class Base
	{
	private:
    		int BaseClassData;
	public:
    		Base(int baseclassdata)
    	{
        		BaseClassData = baseclassdata;
    	}
    		virtual int GetClassData() const // Hàm ảo hằng (constant virtual function).
    	{
        		return BaseClassData;
    	}
	};
	class Derived : public Base
	{
	private:
    		int DerivedClassData;
	public:
    		Derived(int derivedclassdata,
            	int baseclassdata) : Base(baseclassdata) // Gọi constructor lớp cơ sở.
    	{
        		DerivedClassData = derivedclassdata;
    	}
   	int GetClassData() const // Hàm hằng ghi đè (overriding constant function).
    	{
        	return DerivedClassData;
    	}
	};
	// Tham số được truyền theo THAM CHIẾU (pass by reference).
	int GetData(const Base& baseObject) 
	{
    	return baseObject.GetClassData();
	}
	int main()
	{
    		Base* BasePtr;
    		int ClassData;
    		BasePtr = new Base(100);
    		ClassData = GetData(*BasePtr);
    		std::cout << "Base class data " << ClassData << std::endl;
    		BasePtr = new Derived(200, 100);
   		ClassData = GetData(*BasePtr);
    		std::cout << "Derived class data " << ClassData << std::endl;
	}
