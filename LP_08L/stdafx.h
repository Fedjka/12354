// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include<sdkddkver.h>



#define TEST_CREATE01(x) (x>DICTNAMEMAXSIZE)//Тест функции Create: проверка генерации исключения THROW01 
#define TEST_CREATE02(x) (x>DICTMAXSIZE)//Тест функции Create: проверка генерации исключения THROW02 
#define TEST_ADDENTRY03(x, y) (x>=y)//Тест функции AddEntry: проверка генерации исключения THROW03
#define TEST_ADDENTRY04(x, y) (x==y)//Тест функции AddEntry: проверка генерации исключения THROW04
#define TEST_GETENTRY05(x) (throw x)//Тест функции GetEntry: проверка генерации исключения THROW05
#define TEST_DELENTRY06(x) (throw x)//Тест функции DelEntry: проверка генерации исключения THROW06
#define TEST_UPDENTRY07(x) (x==-1)//Тест функции UpdEntry: проверка генерации исключения THROW07
#define TEST_UPDENTRY08(x,y) (x==y)//Тест функции UpdEntry: проверка генерации исключения THROW08
#define TEST_DICTIONARY0(x) (x==true)//Демонстрирует успешное выполнение всех функций





// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы
