#include <string>

#include "table.h"
#include "clerk.h"

Table::Table(int id, int seats, int freeSeats, string clerk):
    id(id),
    seats(seats),
    freeSeats(freeSeats),
    clerk(clerk) {}

void Table::viewAll() {}

bool Table::linkClerk(Clerk& clerk) {
        this->clerk = clerk.getPhone();
        return true;
}


bool Table::addGuest() {
    if(freeSeats == 0)
        return false;
    freeSeats --;
    return true;
}
