#include <string>
#include <vector>

#include "chef.h"
#include "dish.h"
#include "staticdata.h"
#include "datamanager.h"
#include "mysqlmanager.h"

using namespace std;

Chef::Chef(string phone, string name): Person(phone, name, 2) {}

bool Chef::takeDish(const OrderedDish &dish) {
        if(StaticData::db->update("orderedDish", "status", "1", "id = " + ntos(dish.getOrderedDishID()))) {
                dishTaken.push_back(dish);
                return true;
        }
        return false;
}

bool Chef::finishDish(const OrderedDish &dish) {
        return StaticData::db->update("orderedDish", "status", "2", "id = " + ntos(dish.getOrderedDishID()));
}

