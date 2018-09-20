#pragma once
#include <cstring>
#include <iostream>
#include <locale>
#include <Windows.h>


#define DICTNAMEMAXSIZE 20//используем статическую пам€ть
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30
#define THROW01 "Create: превышен размер имени словар€"
#define THROW02 "Create: превышен размер максимальной Ємкости словар€"
#define THROW03 "AddEntry: переполнение словар€"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"


//#if ( defined(TEST_CREATE01) + defined(TEST_CREATE02)+defined(TEST_ADDENTRY03)+ defined(TEST_ADDENTRY04)+defined(TEST_GETENTRY05)+defined(TEST_DELENTRY06)+defined(TEST_UPDENTRY07)+defined(TEST_UPDENTRY08))>1
//#error "error: Too many macros used"
//#endif 

namespace Dictionary {
	struct Entry {//элемент словар€
		int id;//идентификатор
		char name[ENTRYNAMEMAXSIZE];//символьна€ информаци€
	};
	struct Instance {//Ёкземпл€р словар€
		char name[100];//наименование словар€
		int maxsize;//максимальна€ емкость
		int size;//текущий размер
		Entry* dictionary;
	};//массив элементов словар€
	Instance Create(const char name[], int size);//создание словар€
	void AddEntry(Instance &inst, Entry ed);//добавить элемент
	void DelEntry(Instance &inst, int id);//удалить элемент
	void UpdEntry(Instance &inst, int id, Entry new_ed);//изменить элемент словар€
	Entry GetEntry(Instance inst, int id);//получить элемнт словар€
	void Print(Instance d);//печатать словарь
	void Delete(Instance &d);//удалить словарь
};
