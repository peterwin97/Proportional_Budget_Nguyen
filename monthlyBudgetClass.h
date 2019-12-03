class MonthlyBudget
{
  private:
  //EXPENSES  
    double mortgageRent;
    double electric;
    double gasHome;
    double water;
    double savings;
    double entertainment;
    double clothes;
    double shoes;
    double vendingMachine;
    double creditCards;
    double carPMT;
    double carInsurance;
    double carMaintenance;
    double carGas;
    double schoolBooks;
    double groceries;
    double eatingOut;
    double cleaningSupplies;
    double personalCare;
    double charity;
    double dayCare;
    double petCare;
    double cellPhone;
    double internet;
    double cableSat;
    double streamingServ;
    double amazon;
  public:
    void setMortgageRent(double d) { mortgageRent = d; }
    void setElectric(double d) { electric = d; } 
    void setGasHome(double d) { gasHome = d; }
    void setWater(double d) { water = d; }
    void setSavings(double d) { savings = d; }
    void setEntertainment(double d) { entertainment = d; }
    void setClothes(double d) { clothes = d; }
    void setShoes(double d) { shoes = d; }
    void setVendingMachine(double d) { vendingMachine = d; }
    void setCreditCard(double d) { creditCards = d; }
    void setCarPMT(double d) { carPMT = d; }
    void setCarInsurance(double d) { carInsurance = d; }
    void setCarMaintenance(double d) { carMaintenance = d; }
    void setCarGas(double d) { carGas = d; }
    void setSchoolBook(double d) { schoolBooks = d; }
    void setGroceries(double d) { groceries = d; }
    void setEatingOut(double d) { eatingOut = d; }
    void setCleaningSupplies(double d) { cleaningSupplies = d; }
    void setPersonalCare(double d) { personalCare = d; }
    void setCharity(double d) { charity = d; }
    void setDayCare(double d) { dayCare = d; }
    void setPetCare (double d) { petCare = d; }
    void setCellPhone(double d) { cellPhone = d; }
    void setInternet(double d) { internet = d; }
    void setCableSat(double d) { cableSat = d; }
    void setStreamingServ(double d) { streamingServ = d; }
    void setAmazon(double d) { amazon = d; }
  
    double getMortgageRent() { return mortgageRent; }
    double getElectric() { return electric; }
    double getGasHome() { return gasHome; }
    double getWater() { return water; }
    double getSavings() { return savings; }
    double getEntertainement() { return entertainment; }
    double getClothes() { return clothes; }
    double getShoes() { return shoes; }
    double getVendingMachine() { return vendingMachine; }
    double getCreditCard() { return creditCards; }
    double getCarPMT() { return carPMT; }
    double getCarInsurance() { return carInsurance; }
    double getCarMaintenance() { return carMaintenance; }
    double getCarGas() { return carGas; }
    double getSchoolBook() { return schoolBooks; }
    double getGroceries() { return groceries; }
    double getEatingOut(){ return eatingOut; }
    double getCleaningSupplies() { return cleaningSupplies; }
    double getPersonalCare() { return personalCare; }
    double getCharity() { return charity; }
    double getDayCare() { return dayCare; }
    double getPetCare() { return petCare; }
    double getCellPhone() { return cellPhone; }
    double getInternet() { return internet; }
    double getCableSat() { return cableSat; }
    double getStreamingServ() { return streamingServ; }
    double getAmazon() { return amazon; }

    void setValues(vector<double> expenses, double percent){
      setMortgageRent(expenses[0]*percent);
      setElectric(expenses[1]*percent);
      setGasHome(expenses[2]*percent);
      setWater(expenses[3]*percent);
      setSavings(expenses[4]*percent);
      setEntertainment(expenses[5]*percent);
      setClothes(expenses[6]*percent);
      setShoes(expenses[7]*percent);
      setVendingMachine(expenses[8]*percent);
      setCreditCard(expenses[9]*percent);
      setCarPMT(expenses[10]*percent);
      setCarInsurance(expenses[11]*percent);
      setCarMaintenance(expenses[12]*percent);
      setCarGas(expenses[13]*percent);
      setSchoolBook(expenses[14]*percent);
      setGroceries(expenses[15]*percent);
      setEatingOut(expenses[16]*percent);
      setCleaningSupplies(expenses[17]*percent);
      setPersonalCare(expenses[18]*percent);
      setCharity(expenses[19]*percent);
      setDayCare(expenses[20]*percent);
      setPetCare(expenses[21]*percent);
      setCellPhone(expenses[22]*percent);
      setInternet(expenses[23]*percent);
      setCableSat(expenses[24]*percent);
      setStreamingServ(expenses[25]*percent);
      setAmazon(expenses[26]*percent);
    }
};