#include <QString>
#include <vector>

#include "chef.h"
#include "dish.h"
#include "staticdata.h"
#include "datamanager.h"
#include "mysqlmanager.h"

using namespace std;

//Chef::Chef(const QString &phone, const QString &name): Person(phone, name) {}
Chef::Chef(const QString &phone, const QString &name, const QString &password, int dishNum, double averageTimeDifference, int rateNum, double averageRate):
    Person(phone, name, password),
    dishNum(dishNum),
    averageTimeDifference(averageTimeDifference),
    averageRate(averageRate),
    rateNum(rateNum)
{}

void Chef::takeDish(OrderedDish &dish) {
    dish.setStatus(2);
    dish.setChef(this->getPhone());
    StaticData::modifyOrderedDish(dish.getOrderedDishID(), dish);
    dishTaken.push_back(dish);
}

void Chef::finishDish(OrderedDish &dish) {
        sendMsg(QString("Table_%1").arg(dish.getTable()), QString("Dish ready %1").arg(dish.getOrderedDishID()));
        dish.setStatus(3);
        double newDiff;
        if (dish.getTimeNeeded() <= 0)
            newDiff = 0;
        else
            newDiff = (getTimeDifference(dish.getDatetime()) - dish.getTimeNeeded()) / dish.getTimeNeeded();
        averageTimeDifference = (averageTimeDifference * dishNum + newDiff) / ++dishNum;
        StaticData::modifyOrderedDish(dish.getOrderedDishID(), dish);
        StaticData::modifyChef(this->getPhone(), *this);
}

void Chef::updateRate(double newRate) {
    averageRate = (averageRate * rateNum + newRate) / ++rateNum;
    StaticData::modifyChef(this->getPhone(), *this);
}

void Chef::checkDish() {
    this->dishTaken.clear();
    for (unsigned int i = 0; i < StaticData::getOrderedDishList().size(); i ++)
        if (StaticData::getOrderedDishMaintainList()[i] >= 0
                && StaticData::getOrderedDishList()[i].getChef() == this->getPhone()
                && StaticData::getOrderedDishList()[i].getStatus() < 3)
            this->dishTaken.push_back(StaticData::getOrderedDishList()[i]);
}

void Chef::setPhone(const QString &newPhone) {
    changePhone(newPhone);
}
