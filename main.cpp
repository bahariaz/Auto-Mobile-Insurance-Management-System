#include "MenuUI.h"

// Moved to global scope to avoid stack overflow (fixes C6262 warning)
Customer ali;
Customer sara;

Salesman bilal("S1", "Bilal Ahmed", "22222-2222222-2", "0322-2222222",
    "bilal@ins.com", "Sales", "2020-06-01");

Surveyor anjum("SUR1", "Anjum Rashid", "44444-4444444-4", "0344-4444444",
    "anjum@ins.com", "Vehicle Damage", "2019-03-15");

Manager sara_mgr("M1", "Sara Khan", "55555-5555555-5", "0355-5555555",
    "sara@ins.com", "Senior Manager", "2017-07-01");

int main() {

    (void)ali;
    (void)sara;
    (void)bilal;
    (void)anjum;
    (void)sara_mgr;

    MenuUI ui;
    ui.run();

    return 0;
}