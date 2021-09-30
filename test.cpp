#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int n = 10;

class hashtable
{
private:

    struct bucket{
    unsigned int key;
    bool empty = true;
    string name;
    string fio;
    vector <int> chain;
    };
    vector <bucket> ht;
    

public:
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
  int parent = hashfunc(index);
//   if(parent!=index){
//       for (int i: ht[parent].chain){
//           if (ht[parent].chain[i] == index) ht[parent].chain.erase(i, i);
//         }
//     }
}

void printchain(int index){
  cout << endl << "ID: " << index << endl << ht[index].key << endl << ht[index].name << endl << ht[index].fio << endl << endl;

  for (int index: ht[index].chain){
    if(ht[index].empty != true) cout << endl << "ID: " << index << endl << ht[index].key << endl << ht[index].name << endl << ht[index].fio << endl << endl;
  }
  cout << "<<КОНЕЦ>>" << endl;
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
void setsize(int x){
    ht.resize(x);
}
};

int main(){
    hashtable ht;
    ht.setsize(n);
    ht.add(354202, "ООО \"МОЯ ОБОРОНА\"", "Тарасин Иван Герасимович", 0, 0);
    ht.add(768324, "ОАО \"МММММММ\"", "Зубенко Михаил Петрович", 0, 0);
    ht.add(542092, "АНО \"ЖИВОЕ\"", "Богайчук Елена Максимовна", 0, 0);
    ht.add(872314, "АРУ \"LMAO\"", "Закекин Арсений Измайлович", 0, 0);
    bool exitopt = false;
    while(exitopt!=true){
    int a;
    cout << "1. Добавить запись\n2. Удалить запись\n3. Найти запись\n4. Вывести запись на экран\n5. Вывести все записи по хеш-ключу\n6. Выйти\n";
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
        ht.add(a, b, c, 0, 0);
        break;
      }


      case 2:
      {
        cout << "\nВведите номер записи  для удаления:\n";
        int a;
        cin >> a;
        ht.delindex(a);
        cout << "\nУдалено!\n\n";
        break;
      }

      case 3:
      {
        cout << "\nВведите номер лицензии искомой записи:\n";
        int a;
        cin >> a;
        cout << "Ключ записи: " << ht.find(a) << endl;
        break;
      }

      case 4:
      {
        cout << "\nВведите ключ записи:\n";
        int a;
        cin >> a;
        ht.printcell(a);
        break;
      }
    
      case 5:
      {
        cout << "\nВведите хеш-ключ:\n";
        int a;
        cin >> a;
        ht.printchain(a);
        break;
      }
    
      case 6:
      {
        exitopt = true;
        break;
      }
    }
  }
    return 0;
}
