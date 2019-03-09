// Name: Yuchi Zhao
// Date: 27/02/2019
// SequentialList cpp file
#include "SequentialList.hpp"
#include <iostream>
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
	capacity_=cap;
	data_=new DataType[cap];
	size_=0;
}

SequentialList::~SequentialList()
{
	delete [] data_;
	data_=NULL;
}

bool SequentialList::empty() const
{
	return size_==0;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::full() const
{
	return capacity_==size_;
}

void SequentialList::print() const
{
	if (empty())
	{
		cout<<"The list is empty!!!"<<endl;
	}else{
		for(int index=0; index<size_; index++)
		{
			cout<<index<<"  "<<data_[index]<<endl;
		}
	}
}


// NOTE on inserts: do NOT grow the array if we reach capacity. Simply return false.
bool SequentialList::insert_front(DataType val)
{
	return insert(val,0);
}

bool SequentialList::remove_front()
{
	return remove(0);
}

bool SequentialList::insert_back(DataType val)
{
	return insert(val, size_);
}

bool SequentialList::remove_back()
{
	return remove(size_-1);
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if(index>=capacity_||index<0||full()||index>size_)
	{
		return false;
	}
	if(index==size_)
	{
		data_[size_]=val;
	}else
	{
		for(int i=size_; i>index; i--)
		{
			data_[i]=data_[i-1];
		}
		data_[index]=val;
	}
	size_++;
	return true;
}

bool SequentialList::remove(unsigned int index)
{
	if(empty()||index>=capacity_||index<0||index>=size_)
	{
		return false;
	}
	if(index==(size_-1))
	{
		data_[index]=NULL;
	}else{
		for(int count=index; count<size_-1; count++)
		{
			data_[count]=data_[count+1];
		}
		data_[size_-1]=NULL;
	}
	size_--;
	return true;
}

unsigned int SequentialList::search(DataType val) const
{
	for (int index=0; index<size_;index++)
	{
		if(data_[index]==val)
		{
			return index;
		}
	}
	return size_;
}


SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if(index >=size_||index<0||index>=capacity_)
	{
		return data_[size_-1];
	}
	else{
		return data_[index];
	}
}


bool SequentialList::replace(unsigned int index, DataType val)
{
	if(empty()||index>=capacity_||index<0||index>=size_)
	{
		return false;
	}else{
		data_[index]=val;
		return true;
	}
}
