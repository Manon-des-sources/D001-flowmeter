#include"flowmeters.h"

void flowmeter_init(void)
{
    fm_skfl500_init();
}

void flowmeter_update(void)
{
    fm_skfl500_update();
}
