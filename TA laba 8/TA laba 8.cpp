#include "table.h"

int main() {
	setlocale(LC_ALL, "rus");

	Table* table = new Table(1e3+7);

	cout << "\n<=================[Добавление]=================>\n\n";

	string keys[] = 
		{
		"Иван",                                              
		"Никита",                                            
		"Галя",                                              
		"Катя",                                              
		"Игорь",                                             
		"Ибрагим",                                           
		"Святослав",                                         
		"Билли Херингтон",                                   
		"Владимир Красно Солнышко",                          
		"Джон Сноу",                                         
		"Быдло получает по заслугам нарезка справедливости", 
		"Смешная нарезка детей",                             
		"Цыганские учёные уже много лет работают ",			 
		"над лекарством от рака, ",						     
		"но пока получается только героин",					 
		"Штирлиц долго смотрел в одну точку.",				 
		"Потом в другую.",									 
		"\"Двоеточие\", -смекнул Штирлиц",					 
		};

	for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
		table->Add(keys[i], i);
		//table->Show();
	}
	table->Show(false);

	cout << "\n<=================[Поиск]=================>\n\n";

	string key1 = "Катя";
	Element* temp = table->Find(key1);
	cout << "Find by key: " << key1 << " value: ";
	if (temp) cout << temp->Value << "\n";
	else cout << "-\n";

	cout << "\n<=================[Изменение]=================>\n\n";

	string key2 = "Игорь";
	t newValue = 100;
	cout << "Изменение значения по ключу: " << key2 << " Новое значение: " << newValue << '\n';
	bool res1 = table->ChangeValue(key2, newValue);
	table->Show(false);

	cout << "\n<=================[Удаление]=================>\n\n";

	bool res2 = table->Delete("Никита");
	bool res4 = table->Delete("Святослав");
	bool res3 = table->Delete("Билли Херингтон");
	table->Show(false);	
}
