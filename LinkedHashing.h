#pragma once
class LinkedHashEntry {
public:
	//LinkedHashEntry();
	LinkedHashEntry(int key, int value) {
		this->key = key;
		this->value = value;
		this->next = nullptr;
	}

	int getKey() {
		return key;
	}
	int getValue() {
		return value;
	}
	void setValue(int value) {
		this->value = value;
	}
	LinkedHashEntry *getnext() {
		return next;
	}
	void setnext(LinkedHashEntry *next) {
		this->next = next;
	}

private:
	int key, value;
	LinkedHashEntry *next;
};

//const int TABLE_SIZE = 128;
class LinkedHashMap
{
public:
	LinkedHashMap();
	~LinkedHashMap();
	int get(int key) {
		int hash = key % TABLE_SIZE;
		if (table[hash] == nullptr)
			return -1;
		else
		{
			LinkedHashEntry *tableEntry = table[hash];
			while (tableEntry != nullptr && tableEntry->getKey() != key)
			{
				tableEntry = tableEntry->getnext();
			}
			if (tableEntry == nullptr)
				return -1;
			else
				return tableEntry->getValue();
		}
	}

	void put(int key, int value) {
		int hash = key % TABLE_SIZE;
		//LinkedHashEntry tableEntry;
		if (table[hash] == nullptr) {
			table[hash] = new LinkedHashEntry(key, value);
		}
		else
		{
			LinkedHashEntry *tableEntry = table[hash];
			while (tableEntry->getnext() != nullptr)
				tableEntry = tableEntry->getnext();
			if (tableEntry->getKey() == key)
				tableEntry->setValue(value);
			else
				tableEntry->setnext(new LinkedHashEntry(key, value));
		}
	}
	void remove(int key) {
		int hash = key % TABLE_SIZE;
		LinkedHashEntry *tableEntry = table[hash];
		LinkedHashEntry *prevEntry, *nextEntry;
		while (tableEntry != nullptr && tableEntry->getKey() != key) {
			prevEntry = tableEntry;
			tableEntry = tableEntry->getnext();
		}
		if (tableEntry->getKey() == key) {
			if (tableEntry->getnext() != nullptr) {
				nextEntry = tableEntry->getnext();
				prevEntry->setnext(nextEntry);
			}
			delete tableEntry;
		}
	}

private:
	LinkedHashEntry **table;
};

LinkedHashMap::LinkedHashMap()
{
	LinkedHashMap::table = new LinkedHashEntry*[TABLE_SIZE];
	for (size_t i = 0; i < TABLE_SIZE; i++)
	{
		table[i] = nullptr;
	}
}

LinkedHashMap::~LinkedHashMap()
{
	for (size_t i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != nullptr) {
			LinkedHashEntry *prevEntry, *tableEntry;
			tableEntry = table[i];
			while (tableEntry != nullptr)
			{
				prevEntry = tableEntry;
				tableEntry = tableEntry->getnext();
				delete prevEntry;
			}
		}
	}
	delete[] table;
}