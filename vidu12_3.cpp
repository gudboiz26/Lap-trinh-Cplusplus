//Chương trình này tạo ra KẾT QUẢ SAI!
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
    		virtual int GetClassData() const // Hàm hằng (constant function).
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
            	int baseclassdata) : Base(baseclassdata)
  	{
        		DerivedClassData = derivedclassdata;
    	}
    		int GetClassData() const // Hàm hằng (constant function).
    	{
        		return DerivedClassData;
    	}
	};
		int GetData(const Base baseObject) // Truyền theo giá trị (pass by value)
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
    	delete BasePtr;
    	BasePtr = new Derived(200, 100);
    	ClassData = GetData(*BasePtr);
    	std::cout << "Derived class data " << ClassData << std::endl;
    	delete BasePtr;
        return 0;
	}
