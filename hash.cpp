#include <iostream>
#include <vector>
#include <string>

using namespace std;

int hashfunc(int x);
void add(int lic, string name, string fio, bool first, int link);
void printchain(int index);
void printcell(int index);
void delindex(int index);
int find(unsigned int lic);

struct bucket{
  unsigned int key;
  bool empty = true;
  string name;
  string fio;
  vector <int> chain;
};
vector <bucket> ht;
const int n = 10;


int main(){
  ht.resize(n);
  add(354202, "ООО \"МОЯ ОБОРОНА\"", "Тарасин Иван Герасимович", 0, 0);
  add(768324, "ОАО \"МММММММ\"", "Зубенко Михаил Петрович", 0, 0);
  add(542092, "АНО \"ЖИВОЕ\"", "Богайчук Елена Максимовна", 0, 0);
  add(872314, "АРУ \"LMAO\"", "Закекин Арсений Измайлович", 0, 0);

  bool exitopt = false;
  while(exitopt!=true){
    int a;
    cout << "1. Добавить запись\n2. Удалить запись\n3. Найти запись\n4. Вывести запись на экран\n5. Выйти\n";
    cin >> a;
    switch (a) {

      case 1:
      {
        unsigned int a;
        string b;
        string c;
        cout << "\nВведите данные [ЛИЦЕНЗИЯ, НАЗВАНИЕ, ФИО]:\n";
        cin >> a;
        getline(cin, b);
        getline(cin, c);
        add(a, b, c, 0, 0);
        break;
      }


      case 2:
      {
        cout << "\nВведите номер записи  для удаления:\n";
        int a;
        cin >> a;
        delindex(a);
        cout << "\nУдалено!\n\n";
        break;
      }

      case 3:
      {
        cout << "\nВведите номер лицензии искомой записи:\n";
        int a;
        cin >> a;
        cout << "Ключ записи: " << find(a) << endl;
        break;
      }

      case 4:
      {
        cout << "\nВведите ключ записи:\n";
        int a;
        cin >> a;
        printcell(a);
        break;
      }

      case 5:
      {
        exitopt = true;
        break;
      }
    }
  }
  return 0;
}


int hashfunc(int x){
  return (x % n);
}

void add(int lic, string name, string fio, bool dub, int link){
  int index;
  if(dub) {
    index = ht.size()-1;
  }
  else index = hashfunc(lic);
  if(ht[index].empty == true){
    ht[index].key = lic;
    ht[index].empty = false;
    ht[index].name = name;
    ht[index].fio = fio;
    if (dub){
      ht[link].chain.push_back(index);
      }
    }
  else{
    ht.push_back(bucket());
    add(lic, name, fio, true, index);
  }
}

void delindex(int index){
  ht[index].key = 0;
  ht[index].empty = true;
  ht[index].name = "";
  ht[index].fio = "";
  ht[index].chain.clear();
}

void printchain(int index){
  cout << endl << "ID: " << index << ht[index].key << endl << ht[index].name << endl << ht[index].fio << endl << endl;

  for (int index: ht[index].chain){
    cout << endl << ht[index].key << endl << ht[index].name << endl << ht[index].fio << endl << endl;
  }
  cout << "<<КОНЕЦ ПОИСКА>>" << endl;
}

void printcell(int index){
  cout << endl << ht[index].key << endl << ht[index].name << endl << ht[index].fio << endl << endl;
}

int find(unsigned int lic){
  int index = hashfunc(lic);
  if(ht[index].key == lic){
    return index;
  }
  else {
    for (int i: ht[index].chain){
      if(ht[i].key == lic) return i;
    }
  }
  cout << "НЕ НАЙДЕНО!!";
  return -1;
}

  //ht.push_back(bucket());
  //const int n = 100;
  //ht.resize(n);

  // ifstream base;
  // base.open("bd.txt");
  // for(file >> s; !file.eof(); file >> s){
  //
  // }

  // while (!base.eof()){
  //   ht.push_back(bucket());
  //   base >> ht[cnt].key;
  //   getline(base, s);
  //   ht[cnt].name = s;
  //   getline(base, s);
  //   ht[cnt].fio = s;
  //   ht[cnt].empty = false;
  //   cnt++;
  // }
  // base.close();
