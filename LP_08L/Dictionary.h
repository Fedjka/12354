#pragma once
#include <cstring>
#include <iostream>
#include <locale>
#include <Windows.h>


#define DICTNAMEMAXSIZE 20//���������� ����������� ������
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30
#define THROW01 "Create: �������� ������ ����� �������"
#define THROW02 "Create: �������� ������ ������������ ������� �������"
#define THROW03 "AddEntry: ������������ �������"
#define THROW04 "AddEntry: ������������ ��������������"
#define THROW05 "GetEntry: �� ������ �������"
#define THROW06 "DelEntry: �� ������ �������"
#define THROW07 "UpdEntry: �� ������ �������"
#define THROW08 "UpdEntry: ������������ ��������������"


//#if ( defined(TEST_CREATE01) + defined(TEST_CREATE02)+defined(TEST_ADDENTRY03)+ defined(TEST_ADDENTRY04)+defined(TEST_GETENTRY05)+defined(TEST_DELENTRY06)+defined(TEST_UPDENTRY07)+defined(TEST_UPDENTRY08))>1
//#error "error: Too many macros used"
//#endif 

namespace Dictionary {
	struct Entry {//������� �������
		int id;//�������������
		char name[ENTRYNAMEMAXSIZE];//���������� ����������
	};
	struct Instance {//��������� �������
		char name[100];//������������ �������
		int maxsize;//������������ �������
		int size;//������� ������
		Entry* dictionary;
	};//������ ��������� �������
	Instance Create(const char name[], int size);//�������� �������
	void AddEntry(Instance &inst, Entry ed);//�������� �������
	void DelEntry(Instance &inst, int id);//������� �������
	void UpdEntry(Instance &inst, int id, Entry new_ed);//�������� ������� �������
	Entry GetEntry(Instance inst, int id);//�������� ������ �������
	void Print(Instance d);//�������� �������
	void Delete(Instance &d);//������� �������
};
