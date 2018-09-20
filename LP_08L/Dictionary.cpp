#include "stdafx.h"
#include "Dictionary.h"


#if defined(TEST_CREATE01) && defined(TEST_CREATE02)//��������� �������,��� ������� ����������� �������
Dictionary::Instance Dictionary::Create(const char name[], int size) {//create-�������� �������,�� ���� ������� ��������� Entry
	if (TEST_CREATE01(strlen(name))) {
		throw THROW01;
	}
	if (TEST_CREATE02(size)) {
		throw THROW02;
	}
	Instance inst;//������� ��������� �������
	strcpy_s(inst.name, name);//������������ �������
	inst.maxsize = size;//������������� ������ ������� 
	inst.size = 0;//�������������� ������ �������
	inst.dictionary = new Entry[size];//��������� � ��� ������� ������� Entry
	return inst;//���������� ��������
}
#endif
#if defined(TEST_ADDENTRY03) && defined(TEST_ADDENTRY04)
void Dictionary::AddEntry(Instance &inst, Entry ed) {//��������� ������� ������� 
	if (TEST_ADDENTRY03(inst.size, inst.maxsize)) {//��������� �� ������ �������
		throw THROW03;
	}
	for (int i = 0; i < inst.size; i++) {
		if (TEST_ADDENTRY04(inst.dictionary[i].id, ed.id)) {//��������� �� ������������ ��������������
			throw THROW04;
		}
	}
	inst.dictionary[inst.size] = ed;//ed-������� ������� �� ���������
	inst.size += 1;//��������� � �������� ������� ��������� ��� ������� 
}
#endif
#ifdef TEST_DELENTRY06
void Dictionary::DelEntry(Instance &inst, int id) {//������� ���� �� ��������� �������
	short que(1);//����,� ����������� �� �������� �������� ����� ���������� �������� 
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
void Dictionary::UpdEntry(Instance &inst, int id, Entry new_ed) {//�������� ������� �������
	int count = -1;
	for (int i = 0; i < inst.size; i++) {
		if (TEST_UPDENTRY08(inst.dictionary[i].id, new_ed.id))
			throw THROW08;
		if (inst.dictionary[i].id == id)//���� id ���������,�� ����������� ��������,��������� �� ������ count
			count = i;
	}
	if (TEST_UPDENTRY07(count)) {
		throw THROW07;
	}
	inst.dictionary[id] = new_ed;//����������� �������� � ������������ id ����� �������� � ����� id
}
#endif
#ifdef TEST_GETENTRY05
Dictionary::Entry Dictionary::GetEntry(Instance inst, int id) {//�������� ������� �������
	for (int i = 0; i < inst.size; i++) {
		if ((inst.dictionary[i].id == id))//���������� ��� �������� ���� �� ������ ������� � ������������ id 
			return inst.dictionary[i];// � ���������� ���� ������� 
	}
	TEST_GETENTRY05(THROW05);
}
#endif
void Dictionary::Print(Instance d) {//�������� �������� �������
	std::cout << "------" << d.name << "------" << std::endl;
	for (int i = 0; i < d.size; i++) {
		printf_s("%d.", d.dictionary[i].id);
		std::cout << d.dictionary[i].name << std::endl;
	}
}
void Dictionary::Delete(Instance &d) {//������� �������
	delete d.dictionary;
	std::cout << "������� " << d.name << ":  ������� ������" << std::endl;
}
