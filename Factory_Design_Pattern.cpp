// Copyright 2020 AmberBhardwaj
// Licensed under MIT License or any later version

// Factory
#include <iostream>
#include <string>
#include <unordered_set>
#include <memory>
#include <algorithm>

using namespace std;
enum class EDeviceType
{
	eApple,
	eAndroid,
	eWindows
};
class OS {
public:
	virtual void getDesiredOS() = 0;
};

class Apple :public OS {
	virtual void getDesiredOS()
	{
		std::cout << "Your OS is Apple\n";
	}
};
class Android :public OS {
	virtual void getDesiredOS()
	{
		std::cout << "Your OS is Android\n";
	}
};
class Windows :public OS {
	virtual void getDesiredOS()
	{
		std::cout << "Your OS is Windows\n";
	}
};
class MyFactory {
public:
	MyFactory(const EDeviceType device)
	{
		switch (device)
		{
		case EDeviceType::eApple:
			pObj = make_unique< Apple>();
			break;
		case EDeviceType::eAndroid:
			pObj = make_unique< Android>();
			break;
		case EDeviceType::eWindows:
			pObj = make_unique< Windows>();;
			break;
		default:
			std::cout << "Doesn't support your device\n";
			break;
		}
	}
	unique_ptr<OS>& getYourDevice() {
		return pObj;//std::move(pObj);
	}

private:
	unique_ptr<OS> pObj;
};
int main()
{
	MyFactory factory(EDeviceType::eWindows);
	factory.getYourDevice()->getDesiredOS();
	return 0;
}
