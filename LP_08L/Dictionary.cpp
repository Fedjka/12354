#include "stdafx.h"
#include "Dictionary.h"


#if defined(TEST_CREATE01) && defined(TEST_CREATE02)//проверяем условия,при которых выполняется задание
Dictionary::Instance Dictionary::Create(const char name[], int size) {//create-создание словаря,то есть массива элементов Entry
	if (TEST_CREATE01(strlen(name))) {
		throw THROW01;
	}
	if (TEST_CREATE02(size)) {
		throw THROW02;
	}
	Instance inst;//создаем экземпляр словаря
	strcpy_s(inst.name, name);//наименование словаря
	inst.maxsize = size;//устанавливаем размер словаря 
	inst.size = 0;//первоначальный размер словаря
	inst.dictionary = new Entry[size];//добавляем в наш словарь элемент Entry
	return inst;//возвращаем значение
}
#endif
#if defined(TEST_ADDENTRY03) && defined(TEST_ADDENTRY04)
void Dictionary::AddEntry(Instance &inst, Entry ed) {//добавляем элемент словаря 
	if (TEST_ADDENTRY03(inst.size, inst.maxsize)) {//проверяем на размер словаря
		throw THROW03;
	}
	for (int i = 0; i < inst.size; i++) {
		if (TEST_ADDENTRY04(inst.dictionary[i].id, ed.id)) {//проверяем на дублирование идентификатора
			throw THROW04;
		}
	}
	inst.dictionary[inst.size] = ed;//ed-элемент который мы добавляем
	inst.size += 1;//добавляем к текущему размеру структуры еще единицу 
}
#endif
#ifdef TEST_DELENTRY06
void Dictionary::DelEntry(Instance &inst, int id) {//удаляем один из элементов словаря
	short que(1);//флаг,в зависимости от значения которого будет выполнятся проверка 
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			que = 0;
			for (int j = i; j < inst.size; j++) {
				inst.dictionary[j] = inst.dictionary[j + 1];
			}
		}
	}
	if (que == 0) { inst.size -= 1; }
	if (que) TEST_DELENTRY06(THROW06);
}
#endif
#if defined(TEST_UPDENTRY08) && defined(TEST_UPDENTRY07)
void Dictionary::UpdEntry(Instance &inst, int id, Entry new_ed) {//изменить элемент словаря
	int count = -1;
	for (int i = 0; i < inst.size; i++) {
		if (TEST_UPDENTRY08(inst.dictionary[i].id, new_ed.id))
			throw THROW08;
		if (inst.dictionary[i].id == id)//если id совпадают,то запускается действие,зависящее от флажка count
			count = i;
	}
	if (TEST_UPDENTRY07(count)) {
		throw THROW07;
	}
	inst.dictionary[id] = new_ed;//присваиваем элементу с определенным id новое значение с новым id
}
#endif
#ifdef TEST_GETENTRY05
Dictionary::Entry Dictionary::GetEntry(Instance inst, int id) {//получить элемент словаря
	for (int i = 0; i < inst.size; i++) {
		if ((inst.dictionary[i].id == id))//сравниваем все элементы пока не найдем элемент с определенным id 
			return inst.dictionary[i];// и возвращаем этот элемент 
	}
	TEST_GETENTRY05(THROW05);
}
#endif
void Dictionary::Print(Instance d) {//печатаем элементы словаря
	std::cout << "------" << d.name << "------" << std::endl;
	for (int i = 0; i < d.size; i++) {
		printf_s("%d.", d.dictionary[i].id);
		std::cout << d.dictionary[i].name << std::endl;
	}
}
void Dictionary::Delete(Instance &d) {//удаляем словарь
	delete d.dictionary;
	std::cout << "Словарь " << d.name << ":  успешно удален" << std::endl;
}
