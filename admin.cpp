#include <string>
#include <vector>

#include "person.h"
#include "tools.h"
#include "admin.h"
#include "mysqlmanager.h"
#include "datamanager.h"
#include "staticdata.h"
#include "tools.h"

//Admin::Admin(const QString &phone, const QString &name): Person(phone, name) {}

Admin::Admin(const QString &phone, const QString &name, const QString &password): Person(phone, name, password) {}

//void Admin::addDish(const Dish& dish) {
//        StaticData::insertDish(dish);
//}

//void Admin::removeDish(const Dish& dish) {
//        StaticData::removeDish(dish.getDishID());
//}

//void Admin::modifyDish(const Dish& dish, const QString &newName, double newPrice, int newTime, const QString &newImgDir) {
////    Dish newDish = Dish(newName, newPrice, newTime, newImgDir);
////    StaticData::modifyDish(dish.getDishID(), newDish);
//}

//void Admin::addPerson(const Person& person, int type) {
////    if (type == 1) {
////        Guest newGuest(person.getPhone(), person.getName(), person.getPassword());
////        StaticData::insertGuest(newGuest);
////    }
////    else if (type == 2) {
////        Chef newChef(person.getPhone(), person.getName(), person.getPassword(), );
////        StaticData::insertChef(newChef);
////    }
////    else if (type == 3) {
////        Clerk newClerk(person.getPhone(), person.getName(), person.getPassword());
////        StaticData::insertClerk(newClerk);
////    }
//}

//void Admin::removePerson(const Person& person) {
//    StaticData::removeGuest(person.getPhone());
//    StaticData::removeChef(person.getPhone());
//    StaticData::removeClerk(person.getPhone());
//}

//void Admin::modifyPerson(const Person& person, const QString &newPhone, const QString &newName, const QString &newPassword) {
////        Guest newGuest(newPhone, newName, newPassword);
////        StaticData::modifyGuest(person.getPhone(), newGuest);
////        Chef newChef(newPhone, newName, newPassword);
////        StaticData::modifyChef(person.getPhone(), newChef);
////        Clerk newClerk(newPhone, newName, newPassword);
////        StaticData::modifyClerk(person.getPhone(), newClerk);
//}

//void Admin::addTable(const Table& table) {
//    StaticData::insertTable(table);
//}

//void Admin::removeTable(const Table& table) {
//    StaticData::removeTable(table.getTableID());
//}

void Admin::setPhone(const QString &newPhone) {
    changePhone(newPhone);
}
