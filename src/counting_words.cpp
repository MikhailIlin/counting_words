//============================================================================
// Name        : counting_words.cpp
// Author      : ilin Mikhail
// Version     :
// Copyright   : Your copyright notice
// Description : counting_words in C++,
//============================================================================

#include <iostream>

#include <sstream>
#include <fstream>
#include <string>
#include <cctype>
#include <limits>
#include <map>

int counting_words (char *); //прототип фунциии

#define MAX_WORD_TYPES 500 //мксимальное количество типов слов, т.е. слов из разного количества букв
using namespace std;

//текст задается файлом cppstudio.txt
//считаем, что в тексте знаков переносов нет
//слова, в которых присутствует дефис считаются одним словом

int main()
{
	int z=counting_words("cppstudio.txt");
    return 0;
}

int counting_words (char * filename)
{
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    ifstream fin(filename); // открыли файл для чтения
    string str;
    int array[MAX_WORD_TYPES] = {0};
    int words = 0;
    int words_types = 0; //количество типов слов
    int i = 0;
    while (!fin.eof())
    {
    	fin >> str; // считали первое слово из файла
    	words++;
    	i=str.length()/2;
    	if (str.find("-"))
    	{
    		i++;
    	}//if (str.find("-"))
    	array[i]++;
    }//while (!fin.eof())
    cout << "Всего в тексте " << words << " слов, из них:" << endl;
    i=1;
    for (i=1; i<MAX_WORD_TYPES; ++i)
    {
    	if (array[i]!=0)
    	{
    		cout << "из " << i << " букв: " << array[i]  << endl;
    		words_types+=array[i];  //это сделано, чтобы
    		if (words_types==words) //не перебирать весь массив типов слов
    			break;
    	}
    }

 return 0;
}

