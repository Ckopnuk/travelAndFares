#ifndef TARIFF_H
#define TARIFF_H


class Tariff
{
    double const useMinCost = 0.3;
    double const waitMinCost = 0.07;
    int useTime = 0;
    int waitTime = 0;
    double travelCost = 0;

public:
    Tariff(int minIsWait, int minIsUse);
    Tariff();
    double getUseMinCost() const;
    double getWaitMinCost() const;
    int getUseTime() const;
    void setUseTime(int value);
    int getWaitTime() const;
    void setWaitTime(int value);
    double getTravelCost() const;
    void setTravelCost();
};

class TariffThree : private Tariff
{
    double cost = 24;
    double mileageIncluded = 35;
    double const rerun = 0.29;
    double runSize = 0;
    double totalPrice = cost;

public:
    TariffThree(double itsRun, int time);
    TariffThree();
    double getCost() const;
    double getMileageIncluded() const;
    double getRerun() const;
    double getRunSize() const;
    void setRunSize(double value);
    double getTotalPrice() const;
    void setTotalPrice();
    void setCost(double value);
    void setMileageIncluded(double value);
};

class TariffSix : public TariffThree
{
public:
    TariffSix(double itsRun, int time);
    TariffSix();
};

class TariffNine : public TariffThree
{
public:
    TariffNine(double itsRun, int time);
    TariffNine();
};

class TariffTwelve : public TariffThree
{
public:
    TariffTwelve(double itsRun, int time);
    TariffTwelve();
};

class TariffDay : public TariffThree
{
public:
    TariffDay(double itsRun, int time);
    TariffDay();
};

#endif // TARIFF_H
