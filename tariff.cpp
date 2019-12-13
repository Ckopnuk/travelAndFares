#include "tariff.h"

/*tariff class*/

double Tariff::getUseMinCost() const
{
    return useMinCost;
}

double Tariff::getWaitMinCost() const
{
    return waitMinCost;
}

int Tariff::getUseTime() const
{
    return useTime;
}

void Tariff::setUseTime(int value)
{
    useTime = value;
}

int Tariff::getWaitTime() const
{
    return waitTime;
}

void Tariff::setWaitTime(int value)
{
    waitTime = value;
}

double Tariff::getTravelCost() const
{
    return travelCost;
}

void Tariff::setTravelCost()
{
    travelCost = getUseTime() * getUseMinCost() + getWaitTime() * getWaitMinCost();
}

Tariff::Tariff(int minIsWait, int minIsUse)
{
    setUseTime(minIsUse);
    setWaitTime(minIsWait);
    setTravelCost();
}

Tariff::Tariff()
{
    setTravelCost();
}



/*TariffThree class*/

double TariffThree::getMileageIncluded() const
{
    return mileageIncluded;
}

double TariffThree::getRerun() const
{
    return rerun;
}

double TariffThree::getRunSize() const
{
    return runSize;
}

void TariffThree::setRunSize(double value)
{
    runSize = value;
}

double TariffThree::getTotalPrice() const
{
    return totalPrice;
}

void TariffThree::setTotalPrice()
{
    if (getMileageIncluded() >= getRunSize()) {
        totalPrice = getCost();
    } else {
        totalPrice = ((getRunSize() - getMileageIncluded()) * getRerun()) + getCost();
    }

}

void TariffThree::setCost(double value)
{
    cost = value;
}

void TariffThree::setMileageIncluded(double value)
{
    mileageIncluded = value;
}

TariffThree::TariffThree(double itsRun, int time)
{
    if (time > 180) throw time;
    else {
        setRunSize(itsRun);
        setTotalPrice();
    }
}

TariffThree::TariffThree()
{
    setTotalPrice();
}

double TariffThree::getCost() const
{
    return cost;
}

/*TariffSix class*/

TariffSix::TariffSix(double itsRun, int time)
{
    if (time > 360) throw time;
    else {
        setRunSize(itsRun);
        setMileageIncluded(55);
        setCost(34);
        setTotalPrice();
    }
}

TariffSix::TariffSix()
{
    setTotalPrice();
}

/*TariffNine class*/

TariffNine::TariffNine(double itsRun, int time)
{
    if (time > 540) throw time;
    else {
        setRunSize(itsRun);
        setMileageIncluded(70);
        setCost(42);
        setTotalPrice();
    }
}

TariffNine::TariffNine()
{
    setTotalPrice();
}

/*TariffTwelve class*/

TariffTwelve::TariffTwelve(double itsRun, int time)
{
    if (time > 720) throw time;
    else {
        setRunSize(itsRun);
        setMileageIncluded(80);
        setCost(49);
        setTotalPrice();
    }
}

TariffTwelve::TariffTwelve()
{
    setTotalPrice();
}

/*TariffDay class*/

TariffDay::TariffDay(double itsRun, int time)
{
    if (time > 1440) throw time;
    else {
        setRunSize(itsRun);
        setMileageIncluded(105);
        setCost(59);
        setTotalPrice();
    }
}

TariffDay::TariffDay()
{
    setTotalPrice();
}
