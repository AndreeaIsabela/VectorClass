#pragma once
template <typename T>class MyVector
{
public:

	MyVector() :mPointer(nullptr), mSize(0), mCapacity(0) {};
	MyVector(const MyVector& aOtherVector) :mPointer(nullptr), mSize(0), mCapacity(0) 
	{
		mPointer = new T[aOtherVector.mCapacity];

		for (auto i = 0; i < aOtherVector.mSize; ++i)
			mPointer[i] = aOtherVector.mPointer[i];


		mSize=aOtherVector.mSize;
		mCapacity = aOtherVector.mCapacity;
	};

	int Size() { return mSize; };
	int Capacity() { return mCapacity; };

	bool Empty() { return mSize == 0; };
	void Clear();

	MyVector& operator=(MyVector aOther) 
	{
		*this = move(aOther);
		return *this;
	};

	T& operator[](const int & aPosition) { return mPointer[aPosition]; };

	void Reserve(const int& aCapacity);
	void Resize(const int& aSize);

	void PushBack(const T & aElement);
	void PopBack();

	~MyVector(){delete[] mPointer;};


private:
	T* mPointer;
	int mSize;
	int mCapacity;

};

template<typename T>
inline void MyVector<T>::Clear()
{
	for (auto i = 0; i < mSize; ++i)
	{
		mPointer[i].~T();
	}
	mSize = 0;
}

template<typename T>
inline void MyVector<T>::Reserve(const int & aCapacity)
{
	if (aCapacity > mCapacity) {
		T* temp = new T[aCapacity];
		for (auto i = 0; i < mSize; ++i)
			temp[i] = mPointer[i];
		mCapacity = aCapacity;
		delete[] mPointer;
		mPointer = temp;
	}
}

template<typename T>
inline void MyVector<T>::Resize(const int & aSize)
{
	if(aSize<mSize)
	{
		for (auto i = aSize; i < mSize; ++i)
		{
			mPointer[i].~T();
		}
	else if (aSize > mSize)
	{
		Reserve(aSize);
	}
	mSize = aSize;
	}
}

template<typename T>
inline void MyVector<T>::PushBack(const T & aElement)
{
	if (mCapacity <= mSize)
	{
		Reserve(mSize);
	}
	++mSize;
	mPointer[mSize] = aElement;
}

template<typename T>
inline void MyVector<T>::PopBack()
{
	if (mSize)
	{
		mPointer[mSize - 1].~T();
		--mSize;
	}
}


